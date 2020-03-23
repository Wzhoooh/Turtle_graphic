#include <iostream>
#include "commands.hpp"
#include "turtle.hpp"
#include "define_list.hpp"
#include "canvas.hpp"

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

Pen_Definition::Pen_Definition(std::shared_ptr<Turtle> turtle, unsigned width, rgb color):
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

Pen_Selection::Pen_Selection(std::shared_ptr<Define_List> defList, int number): _defList(defList), _number(number)
{}
void Pen_Selection::execute()
{
    _defList->applyDefinition(_number);
}
const char* Pen_Selection::getName()
{
    return "Pen_Selection";
}

Canvas_Definition::Canvas_Definition(std::shared_ptr<Canvas> canvas, std::shared_ptr<Turtle> turtle, point_LL sizeBitMap,
    rgb color): _canvas(canvas), _turtle(turtle), _sizeBitMap(sizeBitMap), _p1({0, 0}), _p2({1, 1})
{}
Canvas_Definition::Canvas_Definition(std::shared_ptr<Canvas> canvas, std::shared_ptr<Turtle> turtle, point_LL sizeBitMap,
    rgb color, point_LD p1, point_LD p2): _canvas(canvas), _turtle(turtle), _sizeBitMap(sizeBitMap), _p1(p1), _p2(p2)
{}
void Canvas_Definition::execute()
{
    _canvas->setSizeBitMap(_sizeBitMap);
    _canvas->setCanvasColor(_color);
    _turtle->setCanvasParameters(_p1, _p2);
}
const char* Canvas_Definition::getName()
{
    return "Canvas_Definition";
}

