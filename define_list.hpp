#ifndef DEFINE_LIST_HPP_INCLUDED
#define DEFINE_LIST_HPP_INCLUDED

#include <memory>
#include "list.hpp"

class Command;

class Definition
{
public:
    Definition(int numberOfDefinition, std::shared_ptr<Command> command);
    int getNumber();
    void apply(); // применить

private:
    int _numberOfDefinition;
    std::shared_ptr<Command> _command;
};

class Define_List
{
public:
    Define_List();
    void addPenDefinition(std::shared_ptr<Definition> penDefinition);
    void addCanvasDefinition(std::shared_ptr<Command> canvasDefinition);
    void applyDefinition(int numberOfDefinition);
    void applyCanvasDefinition();

private:
    std::shared_ptr<dataStructures::list<std::shared_ptr<Definition>>> _penDefinitions;
    std::shared_ptr<Command> _canvasDefinition;
};

#endif // DEFINE_LIST_HPP_INCLUDED
