#include "..\headers\Aplication.hpp"
#include "..\headers\Component.hpp"
#include "..\headers\LuaScripting.hpp"
#include "..\headers\PanelLoader.hpp"
#include "..\headers\PanelExporter.hpp"
#include "..\headers\PanelManager.hpp"

TaskManager::Aplication::Aplication()
{

    aplicationComponents["scriptingComponent"] = new LuaScripting();
    aplicationComponents["PanelLoader"]        = new PanelLoader();
    aplicationComponents["PanelExporter"]      = new PanelExporter();
    aplicationComponents["PanelManager"]       = new PanelManager();

    for (auto component : aplicationComponents)
    {
        component.second->initializeLuaScripting(getScripting());
    }

}

TaskManager::Aplication::~Aplication()
{
    for (auto component : aplicationComponents)
    {
        delete component.second;
    }
}

TaskManager::LuaScripting& TaskManager::Aplication::getScripting()
{
    return *((TaskManager::LuaScripting*) (aplicationComponents["scriptingComponent"]));
}
