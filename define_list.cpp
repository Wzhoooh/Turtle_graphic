#include "define_list.hpp"
#include "commands.hpp"

Definition::Definition(int numberOfDefinition, std::shared_ptr<Command> command): _numberOfDefinition(numberOfDefinition),
_command(command)
{}
int Definition::getNumber()
{
    return _numberOfDefinition;
}
void Definition::apply()
{
    _command->execute();
}

Define_List::Define_List(): _penDefinitions(std::make_shared<dataStructures::list<std::shared_ptr<Definition>>>())
{}
void Define_List::addPenDefinition(std::shared_ptr<Definition> penDefinition)
{
    _penDefinitions->push_back(penDefinition);
}
void Define_List::addCanvasDefinition(std::shared_ptr<Command> canvasDefinition)
{
    _canvasDefinition = canvasDefinition;
}
void Define_List::applyDefinition(int numberOfDefinition)
{
    for (auto&& i : *_penDefinitions)
        if (i->getNumber() == numberOfDefinition)
        {
            i->apply();
            return;
        }

    throw std::runtime_error("invalid definition");
}
void Define_List::applyCanvasDefinition()
{
    _canvasDefinition->execute();
}
