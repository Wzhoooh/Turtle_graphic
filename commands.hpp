#ifndef COMMANDS_HPP_INCLUDED
#define COMMANDS_HPP_INCLUDED

#include <exception>
#include <memory>
#include "list.hpp"
#include "add_structures.hpp"

class Turtle;
class Canvas;
class Define_List;

class Command
{
public:
    virtual void execute() = 0;
    virtual const char* getName() = 0;
    virtual void addCommand(std::shared_ptr<Command> newCommand)
    {
        throw std::runtime_error("not \"Do\" command");
    }
};

class Move: public Command
{
public:
    Move(std::shared_ptr<Turtle> turtle, long double distance);
    void execute();
    const char* getName();

private:
    std::shared_ptr<Turtle> _turtle;
    long double _distance;
};

class Move_To: public Command
{
public:
    Move_To(std::shared_ptr<Turtle> turtle, long double x, long double y);
    void execute();
    const char* getName();

private:
    std::shared_ptr<Turtle> _turtle;
    long double _x;
    long double _y;
};

class Turn_Left: public Command
{
public:
    Turn_Left(std::shared_ptr<Turtle> turtle);
    void execute();
    const char* getName();

private:
    std::shared_ptr<Turtle> _turtle;
};

class Turn_Right: public Command
{
public:
    Turn_Right(std::shared_ptr<Turtle> turtle);
    void execute();
    const char* getName();

private:
    std::shared_ptr<Turtle> _turtle;
};

class Turn_South: public Command
{
public:
    Turn_South(std::shared_ptr<Turtle> turtle);
    void execute();
    const char* getName();

private:
    std::shared_ptr<Turtle> _turtle;
};

class Turn_North: public Command
{
public:
    Turn_North(std::shared_ptr<Turtle> turtle);
    void execute();
    const char* getName();

private:
    std::shared_ptr<Turtle> _turtle;
};

class Turn_West: public Command
{
public:
    Turn_West(std::shared_ptr<Turtle> turtle);
    void execute();
    const char* getName();

private:
    std::shared_ptr<Turtle> _turtle;
};

class Turn_East: public Command
{
public:
    Turn_East(std::shared_ptr<Turtle> turtle);
    void execute();
    const char* getName();

private:
    std::shared_ptr<Turtle> _turtle;
};

class Pen_Down: public Command
{
public:
    Pen_Down(std::shared_ptr<Turtle> turtle);
    void execute();
    const char* getName();

private:
    std::shared_ptr<Turtle> _turtle;
};

class Pen_Up: public Command
{
public:
    Pen_Up(std::shared_ptr<Turtle> turtle);
    void execute();
    const char* getName();

private:
    std::shared_ptr<Turtle> _turtle;
};

class Do: public Command
{
public:
    Do(std::shared_ptr<Turtle> turtle, unsigned int numReplays);
    void execute();
    const char* getName();
    void addCommand(std::shared_ptr<Command> newCommand) override;

private:
    std::shared_ptr<Turtle> _turtle;
    std::shared_ptr<dataStructures::list<std::shared_ptr<Command>>> _commands;
    unsigned int _numReplays;
};

class Pen_Definition: public Command
{
public:
    Pen_Definition(std::shared_ptr<Turtle> turtle, unsigned width, rgb color);
    void execute();
    const char* getName();

private:
    std::shared_ptr<Turtle> _turtle;
    unsigned _width;
    rgb _color;
};

class Pen_Selection: public Command
{
public:
    Pen_Selection(std::shared_ptr<Define_List> defList, int number);
    void execute();
    const char* getName();

private:
    std::shared_ptr<Define_List> _defList;
    int _number;
};

class Canvas_Definition: public Command
{
public:
    Canvas_Definition(std::shared_ptr<Canvas> canvas, std::shared_ptr<Turtle> turtle, point_LL sizeBitMap,
                      rgb color);
    Canvas_Definition(std::shared_ptr<Canvas> canvas, std::shared_ptr<Turtle> turtle, point_LL sizeBitMap,
                      rgb color, point_LD p1, point_LD p2);
    void execute();
    const char* getName();

private:
    std::shared_ptr<Turtle> _turtle;
    std::shared_ptr<Canvas> _canvas;
    point_LL _sizeBitMap;
    rgb _color;
    point_LD _p1, _p2;
};

#endif // COMMANDS_HPP_INCLUDED
