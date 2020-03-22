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
    void addDefinition(std::shared_ptr<Definition> definition);
    void applyDefinitioin(int numberOfDefinition);

private:
    dataStructures::list<std::shared_ptr<Definition>> _definitions;

};

#endif // DEFINE_LIST_HPP_INCLUDED
