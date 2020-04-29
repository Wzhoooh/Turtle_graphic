#ifndef PARSER_HPP_INCLUDED
#define PARSER_HPP_INCLUDED

#include <memory>
#include "string.hpp"

class Command_Handler;

class Parser
{
public:
    Parser(DS::string&&, Command_Handler&& handler);
    void handle();

private:
    DS::string s;
    Command_Handler& _handler;
};

#endif // PARSER_HPP_INCLUDED
