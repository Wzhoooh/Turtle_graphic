#include <sstream>
#include <iostream>
#include "define_list.hpp"
#include "commands.hpp"
#include "string.hpp"

void Define_List::addPenDefinition(Command* penDefinition, int number)
{
    _penDefinitions.push_back(std::make_pair(penDefinition, number));
}
void Define_List::addCanvasDefinition(Command* canvasDefinition)
{
    _canvasDefinition = canvasDefinition;
}
void Define_List::applyDefinition(int numberOfDefinition)
{
    for (auto&& i : _penDefinitions)
        if (i.second == numberOfDefinition)
        {
            i.first->execute();
            return;
        }

    std::stringstream ss;
    ss << numberOfDefinition;
    DS::string s(ss.str().c_str());
std::cout << "-----------------" << s << "\n";
    throw std::runtime_error("ERROR: no pen with number " + s);
}
void Define_List::applyCanvasDefinition()
{
    _canvasDefinition->execute();
}
