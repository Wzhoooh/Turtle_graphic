#ifndef COMPOSITE_HPP_INCLUDED
#define COMPOSITE_HPP_INCLUDED

#include <memory>
#include "list.hpp"

class Command;
class Command_Factory;

class Composite
{
public:
    Composite(Command_Factory* factory);
    void addCommand(std::shared_ptr<Command> command);
    void finishBlok();
    void execute();

private:
    std::shared_ptr<Command> _commands;
    DS::list<std::shared_ptr<Command>> _commandsStack;
};

#endif // COMPOSITE_HPP_INCLUDED
