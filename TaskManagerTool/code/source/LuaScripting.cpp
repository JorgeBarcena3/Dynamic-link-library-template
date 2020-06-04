#include "..\headers\LuaScripting.hpp"
#include "LuaState.h"


TaskManager::LuaScripting::LuaScripting()
{
    vm = new lua::State();

}

TaskManager::TaskStatus_b TaskManager::LuaScripting::exec(const std::string& luaCode)
{
    try
    {
        vm->doString(luaCode);
        return true;
    }
    catch (exception e)
    {

        return TaskManager::TaskStatus_b("Revise el codigo ejecutado", false);
    }
}

