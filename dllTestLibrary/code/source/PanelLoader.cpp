#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "../headers/PanelLoader.hpp"
#include "../headers/LuaScripting.hpp"
#include "../headers/PanelManager.hpp"

TaskManager::TaskStatus_b TaskManager::PanelLoader::loadPanel(std::string path)
{

    // Donde debemos guardar la informacion
    PanelManager* manager = (PanelManager*)Aplication::instance()->getComponent("PanelManager");
    manager->removeAllPanels();

    rapidxml::file<> xmlFile(path.c_str());
    rapidxml::xml_document<> doc;
    doc.parse<0>(xmlFile.data());

    auto rootNode = doc.first_node();
    TaskStatus_b err(false);

    for (rapidxml::xml_node<>* panelNode = rootNode->first_node(); panelNode; panelNode = panelNode->next_sibling()) //Son las entidades
    {
        string panel_title (panelNode->first_attribute("Title")->value());
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
                    string attr_name  = task_atr->name();
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

TaskManager::TaskStatus_b TaskManager::PanelLoader::initializeLuaScripting(TaskManager::LuaScripting& scripting)
{
    //scripting.vm->set("loadScene", [this](const char* path) {this->loadScene(path);  });

    return true;
}
