#ifndef PARSER_HPP_INCLUDED
#define PARSER_HPP_INCLUDED

#include <memory>

class Command_Handler;

class Parser
{
public:
    Parser(const char* input, std::shared_ptr<Command_Handler> handler);
    void handle();

private:
    const char* _data;
    std::shared_ptr<Command_Handler> _handler;
};

#endif // PARSER_HPP_INCLUDED
