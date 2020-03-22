#ifndef COMMAND_HANDLER_HPP_INCLUDED
#define COMMAND_HANDLER_HPP_INCLUDED

#include <memory>
#include "list.hpp"
#include "command_identifiers.hpp"

class Composite;
class Define_List;
class Command_Factory;
class Command_Identifier;

class Command_Handler
{
public:
    Command_Handler(std::shared_ptr<Composite> composite, std::shared_ptr<Define_List> defineList,
                    std::shared_ptr<Command_Factory> factory);
    void handleStr(const char* s);

private:
    std::shared_ptr<Composite> _composite;
    std::shared_ptr<Define_List> _defineList;
    std::shared_ptr<Command_Factory> _factory;
    dataStructures::list<std::shared_ptr<Command_Identifier>> _identifiers;
};

#endif // COMMAND_HANDLER_HPP_INCLUDED
