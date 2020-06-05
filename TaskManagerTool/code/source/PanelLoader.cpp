#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include <sstream>
#include <string>
#include <fstream>
#include <bitset>

#include "../headers/PanelLoader.hpp"
#include "../headers/LuaScripting.hpp"
#include "LuaState.h"
#include "../headers/PanelManager.hpp"

TaskManager::TaskStatus_b TaskManager::PanelLoader::importPanelAsXML(std::string path)
{
    try
    {
        rapidxml::file<> xmlFile(path.c_str());
        parseXML(xmlFile.data());

        return true;
    }
    catch (exception e)
    {
        return ("Error al importar el archivo XML", false);
    }
}

TaskManager::TaskStatus_b TaskManager::PanelLoader::importPanel(std::string path)
{
    std::string data = "";

    string line;
    ifstream myfile(path);

    if (myfile.is_open())
    {
        while (std::getline(myfile, line))
        {
            data += line;
        }

        myfile.close();
    }

    std::stringstream sstream(data);
    std::string output;

    while (sstream.good())
    {
        std::bitset<8> bits;
        sstream >> bits;
        char c = char(bits.to_ulong());
        output += c;
    }

    parseXML(const_cast<char*>(output.c_str()));


    return true;
}

TaskManager::TaskStatus_b TaskManager::PanelLoader::initializeLuaScripting(TaskManager::LuaScripting& scripting)
{
    scripting.vm->set("importPanelAsXML", [this](const char* path) {this->importPanelAsXML(path);  });
    scripting.vm->set("importPanel", [this](const char* path) {this->importPanel(path);  });

    return true;
}

TaskManager::TaskStatus_b TaskManager::PanelLoader::parseXML(char* data)
{
    // Donde debemos guardar la informacion
    PanelManager* manager = (PanelManager*)Aplication::instance()->getComponent("PanelManager");
    manager->removeAllPanels();

    rapidxml::xml_document<> doc;
    doc.parse<0>(data);

    auto rootNode = doc.first_node();
    TaskStatus_b err(false);

    for (rapidxml::xml_node<>* panelNode = rootNode->first_node(); panelNode; panelNode = panelNode->next_sibling()) //Son las entidades
    {
        string panel_title(panelNode->first_attribute("Title")->value());
        err = manager->createPanel(panel_title);
        err = manager->changeToPanel(panel_title);

        for (rapidxml::xml_node<>* stateNode = panelNode->first_node(); stateNode; stateNode = stateNode->next_sibling()) //Son las entidades
        {
            string state_title(stateNode->first_attribute("Title")->value());
            err = manager->addState(state_title);

            for (rapidxml::xml_node<>* taskNode = stateNode->first_node(); taskNode; taskNode = taskNode->next_sibling()) //Son las entidades
            {

                string task_title;
                string task_descp;
                string task_assing;
                string task_date;

                for (rapidxml::xml_node<>* task_atr = taskNode->first_node(); task_atr; task_atr = task_atr->next_sibling()) //Son las entidades
                {
                    string attr_name = task_atr->name();
                    string attr_value = task_atr->value();

                    if (attr_name == "Title")
                    {
                        task_title = attr_value;
                    }
                    else if (attr_name == "Description")
                    {
                        task_descp = attr_value;

                    }
                    else if (attr_name == "Assign")
                    {
                        task_assing = attr_value;

                    }
                    else if (attr_name == "Date")
                    {
                        task_date = attr_value;

                    }
                }

                err = manager->addTaskToState(state_title, task_title, task_descp, task_assing, task_date);

            }
        }
    }


    return true;
}
