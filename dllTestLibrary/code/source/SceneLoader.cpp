#include "../headers/SceneLoader.hpp"
#include "../headers/LuaScripting.hpp"
#include "Scene.hpp"

bool SceneCreator::SceneLoader::loadScene(std::string path)
{

    try
    {

        OpenGLRender3D::Scene* a = new OpenGLRender3D::Scene(800, 600, path);
        return true;
    
    }
    catch (std::exception e)
    {

        return false;
    }
}

bool SceneCreator::SceneLoader::initialice_scripting_lua(SceneCreator::LuaScripting& scripting)
{
    scripting.vm->set("loadScene", [this](const char* path) {this->loadScene(path);  });

    return true;
}
