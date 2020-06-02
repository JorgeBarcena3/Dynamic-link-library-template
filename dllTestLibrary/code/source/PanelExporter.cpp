#include "../headers/PanelExporter.hpp"
#include "../headers/PanelDto.hpp"
#include "rapidxml_ext.hpp"
#include <fstream>
#include <sstream>
#include "../headers/Aplication.hpp"
#include "../headers/PanelManager.hpp"


using namespace rapidxml;


TaskManager::TaskStatus_b TaskManager::PanelExporter::exportData(std::string directory)
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
        panel_node->append_attribute(doc.allocate_attribute("Title", doc.allocate_string( panel->getTitle().c_str())));

        for (auto state : manager->getStatesFromPanel(panel->getTitle()).getReturnObj())
        {
            xml_node<> * state_node = doc.allocate_node(node_element, "State");
            state_node->append_attribute(doc.allocate_attribute("Title", doc.allocate_string(state->getTitle().c_str())));
            auto name = state->getTitle();

            for (auto task : manager->getTaskFromState(state->getTitle()).getReturnObj())
            {
                xml_node<>* task_node = doc.allocate_node(node_element, "Task");

                xml_node<>* title_node  = doc.allocate_node(node_element, "Title");
                title_node->value(doc.allocate_string(task->getTitle().c_str()));
                task_node->append_node(title_node);

                xml_node<>* descp_node  = doc.allocate_node(node_element, "Description");
                descp_node->value(doc.allocate_string(task->getDescription().c_str()));
                task_node->append_node(descp_node);

                xml_node<>* assing_node = doc.allocate_node(node_element, "Assign");
                assing_node->value (doc.allocate_string(task->getAssigned().c_str()));
                task_node->append_node(assing_node);

                xml_node<>* date_node   = doc.allocate_node(node_element, "Date");
                date_node->value (doc.allocate_string(to_string( task->getCreationDate()).c_str()));
                task_node->append_node(date_node);


                state_node->append_node(task_node);

            }

            panel_node->append_node(state_node);

        }

        root->append_node(panel_node);

    }

    // Convert doc to string if needed
    std::string xml_as_string;
    rapidxml::print(std::back_inserter(xml_as_string), doc);

    // Save to file
    std::ofstream file_stored("file_stored.xml");

    if (file_stored.is_open())
    {

        file_stored << xml_as_string;
        file_stored.close();

    }

    doc.clear();


    return true;
}

TaskManager::TaskStatus_b TaskManager::PanelExporter::initializeLuaScripting(TaskManager::LuaScripting& scripting)
{
    return true;
}
