#include "../headers/PanelExporter.hpp"
#include "rapidxml_ext.hpp"
#include <fstream>
#include <sstream>
#include "../headers/Aplication.hpp"
#include "../headers/PanelManager.hpp"

using namespace rapidxml;


TaskManager::TaskStatus_b TaskManager::PanelExporter::exportData(std::string directory)
{

    PanelManager * manager = (PanelManager * )Aplication::instance().getComponent("PanelManager");

    // Write xml file =================================
    xml_document<> doc;
    xml_node<>* decl = doc.allocate_node(node_declaration);
    decl->append_attribute(doc.allocate_attribute("version", "1.0"));
    decl->append_attribute(doc.allocate_attribute("encoding", "utf-8"));
    doc.append_node(decl);

    xml_node<>* root = doc.allocate_node(node_element, "rootnode");
    root->append_attribute(doc.allocate_attribute("version", "1.0"));
    root->append_attribute(doc.allocate_attribute("type", "example"));
    doc.append_node(root);

    xml_node<>* child = doc.allocate_node(node_element, "childnode");
    root->append_node(child);

    // Convert doc to string if needed
    std::string xml_as_string;
    rapidxml::print(std::back_inserter(xml_as_string), doc);

    // Save to file
    std::ofstream file_stored("file_stored.xml");
    file_stored << doc;
    file_stored.close();
    doc.clear();


    return true;
}

TaskManager::TaskStatus_b TaskManager::PanelExporter::initializeLuaScripting(TaskManager::LuaScripting& scripting)
{
    return true;
}
