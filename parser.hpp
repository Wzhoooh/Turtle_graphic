#ifndef PARSER_HPP_INCLUDED
#define PARSER_HPP_INCLUDED

#include <memory>

class Command_Handler;

class Parser
{
public:
    Parser(const char* input, Command_Handler* handler);
    void handle();

private:
    const char* _data;
    Command_Handler* _handler;
};

#endif // PARSER_HPP_INCLUDED
