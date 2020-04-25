#include "define_list.hpp"
#include "commands.hpp"

Define_List::Define_List():
    _penDefinitions(std::make_shared<DS::list<std::pair<std::shared_ptr<Command>, int>>>())
{}
void Define_List::addPenDefinition(std::shared_ptr<Command> penDefinition, int number)
{
    _penDefinitions->push_back(std::make_pair(penDefinition, number));
}
void Define_List::addCanvasDefinition(std::shared_ptr<Command> canvasDefinition)
{
    _canvasDefinition = canvasDefinition;
}
void Define_List::applyDefinition(int numberOfDefinition)
{
    for (auto&& i : *_penDefinitions)
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
