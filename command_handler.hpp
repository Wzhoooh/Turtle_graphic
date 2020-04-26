#ifndef COMMAND_HANDLER_HPP_INCLUDED
#define COMMAND_HANDLER_HPP_INCLUDED

#include <memory>
#include "list.hpp"
#include "primitives.hpp"

class Composite;
class Define_List;
class Command_Factory;
class Command_Identifier;

class Command_Handler
{
public:
    Command_Handler(Composite* composite, Define_List* defineList, Command_Factory* factory);
    void handleStr(const char* s);

private:
    Composite* _composite;
    Define_List* _defineList;
    Command_Factory* _factory;
    DS::list<Command_Identifier*> _identifiers;
};

#endif // COMMAND_HANDLER_HPP_INCLUDED
