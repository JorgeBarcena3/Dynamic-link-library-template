#include "../headers/PanelLoader.hpp"
#include "../headers/LuaScripting.hpp"

bool TaskManager::PanelLoader::loadPanel(std::string path)
{

    return true;
}

bool TaskManager::PanelLoader::initializeLuaScripting(TaskManager::LuaScripting& scripting)
{
    //scripting.vm->set("loadScene", [this](const char* path) {this->loadScene(path);  });

    return true;
}
