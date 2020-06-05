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
        auto s = vm->doString(luaCode);
        return true;
    }
    catch (exception e)
    {

        return TaskManager::TaskStatus_b("Revise el codigo ejecutado", false);
    }
}

TaskManager::TaskStatus_b TaskManager::LuaScripting::execFile(const std::string& luaCode)
{
    try
    {
        auto s = vm->doFile(luaCode);
        return true;
    }
    catch (exception e)
    {

        return TaskManager::TaskStatus_b("Revise el codigo ejecutado", false);
    }
}

