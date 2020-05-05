#include "..\headers\Aplication.hpp"
#include "..\headers\Component.hpp"
#include "..\headers\LuaScripting.hpp"
#include "..\headers\SceneLoader.hpp"

SceneCreator::Aplication::Aplication()
{

    aplicationComponents["scriptingComponent"] = new LuaScripting();
    aplicationComponents["SceneLoader"]        = new SceneLoader();

    for (auto component : aplicationComponents)
    {
        component.second->initialice_scripting_lua(getScripting());
    }

}

SceneCreator::Aplication::~Aplication()
{
    for (auto component : aplicationComponents)
    {
        delete component.second;
    }
}

SceneCreator::LuaScripting& SceneCreator::Aplication::getScripting()
{
    return *((SceneCreator::LuaScripting*) (aplicationComponents["scriptingComponent"]));
}
