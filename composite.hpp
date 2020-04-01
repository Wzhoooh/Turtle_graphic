#ifndef COMPOSITE_HPP_INCLUDED
#define COMPOSITE_HPP_INCLUDED

#include <memory>
#include "list.hpp"

class Command;
class Command_Factory;

class Composite
{
public:
    Composite(std::shared_ptr<Command_Factory> factory);
    void addCommand(std::shared_ptr<Command> command);
    void finishBlok();
    void execute();

private:
    std::shared_ptr<Command> _commands;
    std::shared_ptr<dataStructures::list<std::shared_ptr<Command>>> _commandsStack;
};

#endif // COMPOSITE_HPP_INCLUDED
