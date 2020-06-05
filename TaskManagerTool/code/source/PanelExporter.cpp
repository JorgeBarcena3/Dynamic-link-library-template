#include "../headers/PanelExporter.hpp"
#include "../headers/PanelDto.hpp"
#include "../headers/Aplication.hpp"
#include "../headers/PanelManager.hpp"
#include "../headers/LuaScripting.hpp"
#include "LuaState.h"

#include <bitset>
#include "rapidxml_ext.hpp"
#include <fstream>
#include <sstream>
#include <ctime>
#include <string>


using namespace rapidxml;


TaskManager::TaskStatus_b TaskManager::PanelExporter::exportDataAsXML(std::string directory)
{
    try
    {
        string xml = createXML();

        // Save to file
        std::ofstream file_stored(string(directory).c_str());

        if (file_stored.is_open())
        {

            file_stored << xml;
            file_stored.close();

        }

        return true;
    }
    catch (exception e)
    {
        return ("Error al exportar los datos", false);
    }
}

TaskManager::TaskStatus_b TaskManager::PanelExporter::exportData(std::string directory)
{
    try {
        string data = createXML();

        string binarydata;

        for (char& _char : data)
        {

            binarydata += bitset<8>(_char).to_string();
        }

        // Save to file
        std::ofstream file_stored(string(directory).c_str(), std::ios::trunc);

        if (file_stored.is_open())
        {
            file_stored << binarydata;
            file_stored.close();

        }

        return true;
    }
    catch (exception e)
    {
        return ("Error al exportar los datos", false);
    }
}

TaskManager::TaskStatus_b TaskManager::PanelExporter::initializeLuaScripting(TaskManager::LuaScripting& scripting)
{
    scripting.vm->set("exportData", [this](const char* t) { this->exportData(t);  });
    scripting.vm->set("exportDataAsXML", [this](const char* t) { this->exportDataAsXML(t);  });

    return true;
}

string TaskManager::PanelExporter::createXML()
{
    // Datos a extraer
    PanelManager* manager = (PanelManager*)Aplication::instance()->getComponent("PanelManager");

    // Write xml file =================================
    xml_document<> doc;

    // Cabecera del XML
    xml_node<>* decl = doc.allocate_node(node_declaration);
    decl->append_attribute(doc.allocate_attribute("version", "1.0"));
    decl->append_attribute(doc.allocate_attribute("encoding", "utf-16"));
    doc.append_node(decl);

    // Cuerpo del XML

    xml_node<>* root = doc.allocate_node(node_element, "TaskManager");
    doc.append_node(root);


    for (auto panel : manager->getAllPanels().getReturnObj())
    {
        xml_node<>* panel_node = doc.allocate_node(node_element, "Panel");
        panel_node->append_attribute(doc.allocate_attribute("Title", doc.allocate_string(panel->getTitle().c_str())));

        for (auto state : manager->getStatesFromPanel(panel->getTitle()).getReturnObj())
        {
            xml_node<>* state_node = doc.allocate_node(node_element, "State");
            state_node->append_attribute(doc.allocate_attribute("Title", doc.allocate_string(state->getTitle().c_str())));
            auto name = state->getTitle();

            for (auto tasks : manager->getTaskFromState(state->getTitle()).getReturnObj())
            {
                xml_node<>* task_node = doc.allocate_node(node_element, "Task");

                xml_node<>* title_node = doc.allocate_node(node_element, "Title");
                title_node->value(doc.allocate_string(tasks->getTitle().c_str()));
                task_node->append_node(title_node);

                xml_node<>* descp_node = doc.allocate_node(node_element, "Description");
                descp_node->value(doc.allocate_string(tasks->getDescription().c_str()));
                task_node->append_node(descp_node);

                xml_node<>* assing_node = doc.allocate_node(node_element, "Assign");
                assing_node->value(doc.allocate_string(tasks->getAssigned().c_str()));
                task_node->append_node(assing_node);

                xml_node<>* date_node = doc.allocate_node(node_element, "Date");
                date_node->value(doc.allocate_string(to_string(tasks->getCreationDate()).c_str()));
                task_node->append_node(date_node);


                state_node->append_node(task_node);

            }

            panel_node->append_node(state_node);

        }

        root->append_node(panel_node);

    }

    std::stringstream ss;
    ss << doc;
    std::string result_xml = ss.str();

    doc.clear();

    return result_xml;
}
