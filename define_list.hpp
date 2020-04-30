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
    ~Define_List();
    void addPenDefinition(Command* penDefinition, int number);
    void addCanvasDefinition(Command* canvasDefinition);
    void applyDefinition(int numberOfDefinition);
    void applyCanvasDefinition();

private:
    DS::list<std::pair<Command*, int>> _penDefinitions;
    Command* _canvasDefinition;
};

#endif // DEFINE_LIST_HPP_INCLUDED
