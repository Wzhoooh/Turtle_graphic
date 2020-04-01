#include <string.h>
#include <iostream>
#include "composite.hpp"
#include "command_factory.hpp"
#include "commands.hpp"

Composite::Composite(std::shared_ptr<Command_Factory> factory): _commands(factory->crDo(1)),
_commandsStack(std::make_shared<dataStructures::list<std::shared_ptr<Command>>>())
{
    _commandsStack->push_back(_commands);
std::cout << "constructor\n";
}

void Composite::addCommand(std::shared_ptr<Command> command)
{
std::cout << "add: " << command->getName() << "\n";
    if (!strcmp(command->getName(), "Do")) // add cycle
    {
        (*_commandsStack->back())->addCommand(command);
        _commandsStack->push_back(command);
    }
    else
    {
        (*_commandsStack->back())->addCommand(command);
    }
}

void Composite::finishBlok()
{
    _commandsStack->pop_back();
}

void Composite::execute()
{
    _commands->execute();
}
