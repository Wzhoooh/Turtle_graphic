#include "parser.hpp"
#include "list.hpp"
#include "string.hpp"
#include "command_handler.hpp"
#include <iostream>

Parser::Parser(DS::string&& input, Command_Handler&& handler): s(input),
        _handler(handler){}

void Parser::handle()
{
std::cout << s << "\n";
    DS::list<DS::string> commandsList;
    for (size_t i = 0; i < s.size();)
    {
        for (; s[i] == ' ' && i < s.size(); ++i)
            continue;

        DS::string word;
        for (; s[i] != ' ' && i < s.size(); ++i)
            word += s[i];

        if (word.size() != 0)
            commandsList.push_back(std::move(word));

    }
    for (auto&& i : commandsList)
        std::cout << i << "\n";

    std::cout << "---------------\n";

    _handler.handle(commandsList);
}
