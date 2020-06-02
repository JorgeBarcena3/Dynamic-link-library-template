#include "../headers/PanelLoader.hpp"
#include "../headers/LuaScripting.hpp"

TaskManager::TaskStatus_b TaskManager::PanelLoader::loadPanel(std::string path)
{

    return true;
}

TaskManager::TaskStatus_b TaskManager::PanelLoader::initializeLuaScripting(TaskManager::LuaScripting& scripting)
{
    //scripting.vm->set("loadScene", [this](const char* path) {this->loadScene(path);  });

    return true;
}
