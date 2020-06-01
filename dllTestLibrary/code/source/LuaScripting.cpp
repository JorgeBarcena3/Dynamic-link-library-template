#include "..\headers\LuaScripting.hpp"
#include "LuaState.h"


TaskManager::LuaScripting::LuaScripting()
{
    vm = new lua::State();

}

void TaskManager::LuaScripting::exec(const std::string& luaCode)
{
    vm->doString(luaCode);
}

