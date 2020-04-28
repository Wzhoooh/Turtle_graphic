#ifndef COMMANDS_HPP_INCLUDED
#define COMMANDS_HPP_INCLUDED

#include <exception>
#include <memory>
#include "list.hpp"
#include "primitives.hpp"

class Turtle;
class Canvas;
class Define_List;

class Command
{
public:
    virtual void execute() = 0;
    virtual const char* getName() = 0;
    virtual void addCommand(Command* newCommand)
    {
        throw std::runtime_error("not \"Do\" command");
    }
};

class Move: public Command
{
public:
    Move(Turtle& turtle, double distance);
    void execute();
    const char* getName();

private:
    Turtle& _turtle;
    double _distance;
};

class Move_To: public Command
{
public:
    Move_To(Turtle& turtle, point_D newPoint);
    void execute();
    const char* getName();

private:
    Turtle& _turtle;
    point_D _newPoint;
};

class Turn: public Command
{
public:
    Turn(Turtle& turtle, double angle);
    void execute();
    const char* getName();

private:
    Turtle& _turtle;
    double _angle;
};

class Turn_Left: public Command
{
public:
    Turn_Left(Turtle& turtle);
    void execute();
    const char* getName();

private:
    Turtle& _turtle;
};

class Turn_Right: public Command
{
public:
    Turn_Right(Turtle& turtle);
    void execute();
    const char* getName();

private:
    Turtle& _turtle;
};

class Turn_South: public Command
{
public:
    Turn_South(Turtle& turtle);
    void execute();
    const char* getName();

private:
    Turtle& _turtle;
};

class Turn_North: public Command
{
public:
    Turn_North(Turtle& turtle);
    void execute();
    const char* getName();

private:
    Turtle& _turtle;
};

class Turn_West: public Command
{
public:
    Turn_West(Turtle& turtle);
    void execute();
    const char* getName();

private:
    Turtle& _turtle;
};

class Turn_East: public Command
{
public:
    Turn_East(Turtle& turtle);
    void execute();
    const char* getName();

private:
    Turtle& _turtle;
};

class Pen_Down: public Command
{
public:
    Pen_Down(Turtle& turtle);
    void execute();
    const char* getName();

private:
    Turtle& _turtle;
};

class Pen_Up: public Command
{
public:
    Pen_Up(Turtle& turtle);
    void execute();
    const char* getName();

private:
    Turtle& _turtle;
};

class Do: public Command
{
public:
    Do(Turtle& turtle, unsigned int numReplays);
    void execute();
    const char* getName();
    void addCommand(Command* newCommand) override;

private:
    Turtle& _turtle;
    DS::list<Command*> _commands;
    unsigned int _numReplays;
};

class Pen_Definition: public Command
{
public:
    Pen_Definition(Turtle& turtle, double width, rgb color);
    void execute();
    const char* getName();

private:
    Turtle& _turtle;
    double _width;
    rgb _color;
};

class Pen_Selection: public Command
{
public:
    Pen_Selection(Define_List& defList, int number);
    void execute();
    const char* getName();

private:
    Define_List& _defList;
    int _number;
};

class Canvas_Definition: public Command
{
public:
    Canvas_Definition(Canvas& canvas, Turtle& turtle, point_LL sizeBitMap,
                      rgb color);
    Canvas_Definition(Canvas& canvas, Turtle& turtle, point_LL sizeBitMap,
                      rgb color, point_D p1, point_D p2);
    void execute();
    const char* getName();

private:
    Turtle& _turtle;
    Canvas& _canvas;
    point_LL _sizeBitMap;
    rgb _color;
    point_D _p1, _p2;
};

#endif // COMMANDS_HPP_INCLUDED
