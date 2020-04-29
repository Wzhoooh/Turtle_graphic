#include <sstream>
#include "define_list.hpp"
#include "commands.hpp"
#include "string.hpp"

Define_List::~Define_List()
{
    for (auto&& i : _penDefinitions)
        delete i.first;

    delete _canvasDefinition;
}

void Define_List::addPenDefinition(Command* penDefinition, int number)
{
    for (auto&& i : _penDefinitions)
        if (number == i.second)
        {
            i.first = penDefinition;
            return;
        }
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
    throw std::runtime_error("no pen with number " + s);
}
void Define_List::applyCanvasDefinition()
{
    _canvasDefinition->execute();
}
