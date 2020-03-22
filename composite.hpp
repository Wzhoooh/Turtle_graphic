#ifndef COMPOSITE_HPP_INCLUDED
#define COMPOSITE_HPP_INCLUDED

#include <memory>
#include "list.hpp"

class Command;

class Composite
{
public:
    Composite();
    void addSimleCommand(std::shared_ptr<Command> command);
    void addCycle(std::shared_ptr<Command> command);
    void goUp();
    void execute();

private:
    std::shared_ptr<Command> _commands;
    dataStructures::list<std::shared_ptr<Command>> _commandsStack;
};

#endif // COMPOSITE_HPP_INCLUDED
