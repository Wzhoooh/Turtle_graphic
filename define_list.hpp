#ifndef DEFINE_LIST_HPP_INCLUDED
#define DEFINE_LIST_HPP_INCLUDED

#include <memory>
#include <utility>
#include "list.hpp"

class Command;

class Define_List
{
public:
    Define_List();
    void addPenDefinition(std::shared_ptr<Command> penDefinition, int number);
    void addCanvasDefinition(std::shared_ptr<Command> canvasDefinition);
    void applyDefinition(int numberOfDefinition);
    void applyCanvasDefinition();

private:
    std::shared_ptr<dataStructures::list<std::pair<std::shared_ptr<Command>, int>>> _penDefinitions;
    std::shared_ptr<Command> _canvasDefinition;
};

#endif // DEFINE_LIST_HPP_INCLUDED
