#ifndef COMMAND_HANDLER_HPP_INCLUDED
#define COMMAND_HANDLER_HPP_INCLUDED

#include <memory>
#include "list.hpp"
#include "string.hpp"
#include "primitives.hpp"

class Composite;
class Define_List;
class Command_Factory;
class Command_Identifier;

class Command_Handler
{
public:
    Command_Handler(Composite& composite, Define_List& defineList, Command_Factory& factory);
    void handle(DS::list<DS::string>&);

private:
    Composite& _composite;
    Define_List& _defineList;
    Command_Factory& _factory;
};

#endif // COMMAND_HANDLER_HPP_INCLUDED
