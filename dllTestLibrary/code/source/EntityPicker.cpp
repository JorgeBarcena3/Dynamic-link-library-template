#include "..\headers\EntityPicker.hpp"
#include "../headers/LuaScripting.hpp"
#include "Scene.hpp"

bool SceneCreator::EntityPicker::getEntity(std::string name)
{
    //¿De que escena lo cojo?
    return false;
}

bool SceneCreator::EntityPicker::initialice_scripting_lua(SceneCreator::LuaScripting& scripting)
{
    scripting.vm->set("getEntity", [this](const char* name) {this->getEntity(name);  });

    return true;
}
