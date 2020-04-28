#ifndef COMMANDS_IDENTIFICATORS_HPP_INCLUDED
#define COMMANDS_IDENTIFICATORS_HPP_INCLUDED

#include <memory>
#include <exception>
#include "list.hpp"
#include "string.hpp"

class Composite;
class Define_List;
class Command_Factory;

class Command_Identifier
{
public:
    Command_Identifier(Composite& composite, Define_List& defineList,
        Command_Factory& factory): _composite(composite), _defineList(defineList),
        _factory(factory){}

    virtual bool pushCommand(DS::list<DS::string>::iterator& wordIt) // pushes command to composite or defineList from factory if command is correct
    {
        throw std::runtime_error("ERROR: using of Command_Identifier");
    }

protected:
    Composite& _composite;
    Define_List& _defineList;
    Command_Factory& _factory;
};

class Move_Id: public Command_Identifier
{
public:
    Move_Id(Composite& composite, Define_List& defineList, Command_Factory& factory):
        Command_Identifier(composite, defineList, factory){}
    bool pushCommand(DS::list<DS::string>::iterator& wordIt) override;
};

class Move_To_Id: public Command_Identifier
{
public:
    Move_To_Id(Composite& composite, Define_List& defineList, Command_Factory& factory):
        Command_Identifier(composite, defineList, factory){}
    bool pushCommand(DS::list<DS::string>::iterator& wordIt) override;
};

class Turn_Id: public Command_Identifier
{
public:
    Turn_Id(Composite& composite, Define_List& defineList, Command_Factory& factory):
        Command_Identifier(composite, defineList, factory){}
    bool pushCommand(DS::list<DS::string>::iterator& wordIt) override;
};

class Turn_Left_Id: public Command_Identifier
{
public:
    Turn_Left_Id(Composite& composite, Define_List& defineList, Command_Factory& factory):
        Command_Identifier(composite, defineList, factory){}
    bool pushCommand(DS::list<DS::string>::iterator& wordIt) override;
};

class Turn_Right_Id: public Command_Identifier
{
public:
    Turn_Right_Id(Composite& composite, Define_List& defineList, Command_Factory& factory):
        Command_Identifier(composite, defineList, factory){}
    bool pushCommand(DS::list<DS::string>::iterator& wordIt) override;
};

class Turn_South_Id: public Command_Identifier
{
public:
    Turn_South_Id(Composite& composite, Define_List& defineList, Command_Factory& factory):
        Command_Identifier(composite, defineList, factory){}
    bool pushCommand(DS::list<DS::string>::iterator& wordIt) override;
};

class Turn_North_Id: public Command_Identifier
{
public:
    Turn_North_Id(Composite& composite, Define_List& defineList, Command_Factory& factory):
        Command_Identifier(composite, defineList, factory){}
    bool pushCommand(DS::list<DS::string>::iterator& wordIt) override;
};

class Turn_West_Id: public Command_Identifier
{
public:
    Turn_West_Id(Composite& composite, Define_List& defineList, Command_Factory& factory):
        Command_Identifier(composite, defineList, factory){}
    bool pushCommand(DS::list<DS::string>::iterator& wordIt) override;
};

class Turn_East_Id: public Command_Identifier
{
public:
    Turn_East_Id(Composite& composite, Define_List& defineList, Command_Factory& factory):
        Command_Identifier(composite, defineList, factory){}
    bool pushCommand(DS::list<DS::string>::iterator& wordIt) override;
};

class Pen_Down_Id: public Command_Identifier
{
public:
    Pen_Down_Id(Composite& composite, Define_List& defineList, Command_Factory& factory):
        Command_Identifier(composite, defineList, factory){}
    bool pushCommand(DS::list<DS::string>::iterator& wordIt) override;
};

class Pen_Up_Id: public Command_Identifier
{
public:
    Pen_Up_Id(Composite& composite, Define_List& defineList, Command_Factory& factory):
        Command_Identifier(composite, defineList, factory){}
    bool pushCommand(DS::list<DS::string>::iterator& wordIt) override;
};

class Do_Id: public Command_Identifier
{
public:
    Do_Id(Composite& composite, Define_List& defineList, Command_Factory& factory):
        Command_Identifier(composite, defineList, factory){}
    bool pushCommand(DS::list<DS::string>::iterator& wordIt) override;
};

class Again_Id: public Command_Identifier
{
public:
    Again_Id(Composite& composite, Define_List& defineList, Command_Factory& factory):
        Command_Identifier(composite, defineList, factory){}
    bool pushCommand(DS::list<DS::string>::iterator& wordIt) override;
};

class Pen_Definition_Id: public Command_Identifier
{
public:
    Pen_Definition_Id(Composite& composite, Define_List& defineList, Command_Factory& factory):
        Command_Identifier(composite, defineList, factory){}
    bool pushCommand(DS::list<DS::string>::iterator& wordIt) override;
};

class Pen_Selection_Id: public Command_Identifier
{
public:
    Pen_Selection_Id(Composite& composite, Define_List& defineList, Command_Factory& factory):
        Command_Identifier(composite, defineList, factory){}
    bool pushCommand(DS::list<DS::string>::iterator& wordIt) override;
};

class Canvas_Definition_Id: public Command_Identifier
{
public:
    Canvas_Definition_Id(Composite& composite, Define_List& defineList, Command_Factory& factory):
        Command_Identifier(composite, defineList, factory){}
    bool pushCommand(DS::list<DS::string>::iterator& wordIt) override;
};

#endif // COMMANDS_IDENTIFICATORS_HPP_INCLUDED
