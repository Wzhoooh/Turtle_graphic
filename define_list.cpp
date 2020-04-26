#include "define_list.hpp"
#include "commands.hpp"

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

    throw std::runtime_error("invalid definition");
}
void Define_List::applyCanvasDefinition()
{
    _canvasDefinition->execute();
}
