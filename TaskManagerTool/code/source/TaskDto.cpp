#include "../headers/TaskDto.hpp"
#include "../headers/StateDto.hpp"

TaskManager::StateDto& TaskManager::TaskDto::getStateDto()
{
    return *stateDto;
};