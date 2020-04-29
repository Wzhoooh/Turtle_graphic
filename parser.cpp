#include "parser.hpp"
#include "list.hpp"
#include "string.hpp"
#include "command_handler.hpp"
#include <iostream>

Parser::Parser(const char* input, Command_Handler&& handler): _buffer(input),
        _handler(handler){}

void Parser::handle()
{
    DS::list<DS::string> commandsList;
    for (size_t i = 0; _buffer[i];)
    {
        for (; _buffer[i] == ' ' && _buffer[i]; ++i)
            continue;

        DS::string word;
        for (; _buffer[i] != ' ' && _buffer[i]; ++i)
            word += _buffer[i];

        if (word.size() != 0)
            commandsList.push_back(std::move(word));

    }
    for (auto&& i : commandsList)
        std::cout << i << "\n";

    std::cout << "---------------\n";

    _handler.handle(commandsList);
}
