#include "..\headers\LuaScripting.hpp"
#include "LuaState.h"


SceneCreator::LuaScripting::LuaScripting()
{
    vm = new lua::State();

}

void SceneCreator::LuaScripting::exec(const std::string& luaCode)
{
    vm->doString(luaCode);
}

