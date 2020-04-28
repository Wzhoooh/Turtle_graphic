#include <string.h>
#include <iostream>
#include "composite.hpp"
#include "command_factory.hpp"
#include "commands.hpp"

Composite::Composite(Command_Factory& factory): _commands(factory.crDo(1))
{
    _commandsStack.push_back(_commands);
}

void Composite::addCommand(Command* command)
{
std::cout << "Composite add: " << command->getName() << "\n";
    if (!strcmp(command->getName(), "Do")) // add cycle
    {
        (*_commandsStack.back())->addCommand(command);
        _commandsStack.push_back(command);
    }
    else
        (*_commandsStack.back())->addCommand(command);
}

void Composite::finishBlok()
{
    _commandsStack.pop_back();
}

void Composite::execute()
{
    _commands->execute();
}
