#include <iostream>
#include "commands.hpp"
#include "turtle.hpp"

Move::Move(std::shared_ptr<Turtle> turtle, long double distance): _turtle(turtle), _distance(distance)
{}
void Move::execute()
{
    _turtle->move(_distance);
}
const char* Move::getName()
{
    return "Move";
}

Move_To::Move_To(std::shared_ptr<Turtle> turtle, long double x, long double y): _turtle(turtle), _x(x), _y(y)
{}
void Move_To::execute()
{
    _turtle->moveTo(_x, _y);
}
const char* Move_To::getName()
{
    return "Move_To";
}

Turn_Left::Turn_Left(std::shared_ptr<Turtle> turtle): _turtle(turtle)
{}
void Turn_Left::execute()
{
    _turtle->changeDirection(-90);
}
const char* Turn_Left::getName()
{
    return "Turn_Left";
}

Turn_Right::Turn_Right(std::shared_ptr<Turtle> turtle): _turtle(turtle)
{}
void Turn_Right::execute()
{
    _turtle->changeDirection(90);
}
const char* Turn_Right::getName()
{
    return "Turn_Right";
}

Turn_South::Turn_South(std::shared_ptr<Turtle> turtle): _turtle(turtle)
{}
void Turn_South::execute()
{
    _turtle->setDirection(180);
}
const char* Turn_South::getName()
{
    return "Turn_South";
}

Turn_North::Turn_North(std::shared_ptr<Turtle> turtle): _turtle(turtle)
{}
void Turn_North::execute()
{
    _turtle->setDirection(0);
}
const char* Turn_North::getName()
{
    return "Turn_North";
}

Turn_West::Turn_West(std::shared_ptr<Turtle> turtle): _turtle(turtle)
{}
void Turn_West::execute()
{
    _turtle->setDirection(270);
}
const char* Turn_West::getName()
{
    return "Turn_West";
}

Turn_East::Turn_East(std::shared_ptr<Turtle> turtle): _turtle(turtle)
{}
void Turn_East::execute()
{
    _turtle->setDirection(90);
}
const char* Turn_East::getName()
{
    return "Turn_East";
}

Pen_Down::Pen_Down(std::shared_ptr<Turtle> turtle): _turtle(turtle)
{}
void Pen_Down::execute()
{
    _turtle->setPenStatus(true);
}
const char* Pen_Down::getName()
{
    return "Pen_Down";
}

Pen_Up::Pen_Up(std::shared_ptr<Turtle> turtle): _turtle(turtle)
{}
void Pen_Up::execute()
{
    _turtle->setPenStatus(false);
}
const char* Pen_Up::getName()
{
    return "Pen_Up";
}

Do::Do(std::shared_ptr<Turtle> turtle, unsigned int numReplays): _turtle(turtle), _numReplays(numReplays)
{}
void Do::execute()
{
    for (size_t i = 0; i < _numReplays; i++)
        for (auto&& i : *_commands)
            i->execute();
}
const char* Do::getName()
{
    return "Do";
}
void Do::addCommand(std::shared_ptr<Command> newCommand)
{
    _commands->push_back(newCommand);
}

Pen_Definition::Pen_Definition(std::shared_ptr<Turtle> turtle, unsigned width, char color):
_turtle(turtle), _width(width), _color(color)
{}
void Pen_Definition::execute()
{
    _turtle->setPenWidth(_width);
    _turtle->setPenColor(_color);
}
const char* Pen_Definition::getName()
{
    return "Pen_Definition";
}

Pen_Selection::Pen_Selection(std::shared_ptr<Turtle> turtle, int number): _number(number)
{}
void Pen_Selection::execute()
{
    _turtle->setPen(_number);
}
const char* Pen_Selection::getName()
{
    return "Pen_Selection";
}



