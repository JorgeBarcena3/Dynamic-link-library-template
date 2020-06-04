#include "..\headers\Aplication.hpp"
#include "..\headers\Component.hpp"
#include "..\headers\LuaScripting.hpp"
#include "..\headers\PanelLoader.hpp"
#include "..\headers\PanelExporter.hpp"
#include "..\headers\PanelManager.hpp"


using namespace TaskManager;

Aplication * Aplication::app = nullptr;

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

Aplication* TaskManager::Aplication::instance()
{
    if (app)
        return app;

    app = new Aplication();
    return app;

}

TaskManager::Aplication::~Aplication()
{
    for (auto component : aplicationComponents)
    {
        delete component.second;
        aplicationComponents.erase(component.first);
    }
}

TaskManager::LuaScripting& TaskManager::Aplication::getScripting()
{
    return *((TaskManager::LuaScripting*) (aplicationComponents["scriptingComponent"]));
}

TaskManager::Component* TaskManager::Aplication::getComponent(std::string name)
{
    return aplicationComponents[name];
}
