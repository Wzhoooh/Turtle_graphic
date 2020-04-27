#include <iostream>
#include "commands.hpp"
#include "turtle.hpp"
#include "define_list.hpp"
#include "canvas.hpp"

Move::Move(Turtle* turtle, double distance): _turtle(turtle), _distance(distance){}
void Move::execute(){ _turtle->move(_distance); }
const char* Move::getName(){ return "Move"; }

Move_To::Move_To(Turtle* turtle, point_D newPoint): _turtle(turtle), _newPoint(newPoint){}
void Move_To::execute(){ _turtle->moveTo(_newPoint); }
const char* Move_To::getName(){ return "Move_To"; }

Turn::Turn(Turtle* turtle, double angle): _turtle(turtle), _angle(angle){}
void Turn::execute(){ _turtle->changeDirection(_angle); }
const char* Turn::getName(){ return "Turn"; }

Turn_Left::Turn_Left(Turtle* turtle): _turtle(turtle){}
void Turn_Left::execute(){ _turtle->changeDirection(-90); }
const char* Turn_Left::getName(){ return "Turn_Left"; }

Turn_Right::Turn_Right(Turtle* turtle): _turtle(turtle){}
void Turn_Right::execute(){ _turtle->changeDirection(90); }
const char* Turn_Right::getName(){ return "Turn_Right"; }

Turn_South::Turn_South(Turtle* turtle): _turtle(turtle){}
void Turn_South::execute(){ _turtle->setDirection(270); }
const char* Turn_South::getName(){ return "Turn_South"; }

Turn_North::Turn_North(Turtle* turtle): _turtle(turtle){}
void Turn_North::execute(){ _turtle->setDirection(90); }
const char* Turn_North::getName(){ return "Turn_North"; }

Turn_West::Turn_West(Turtle* turtle): _turtle(turtle){}
void Turn_West::execute(){ _turtle->setDirection(180); }
const char* Turn_West::getName(){ return "Turn_West"; }

Turn_East::Turn_East(Turtle* turtle): _turtle(turtle){}
void Turn_East::execute(){ _turtle->setDirection(0); }
const char* Turn_East::getName(){ return "Turn_East"; }

Pen_Down::Pen_Down(Turtle* turtle): _turtle(turtle){}
void Pen_Down::execute(){ _turtle->setPenStatus(true); }
const char* Pen_Down::getName(){ return "Pen_Down";}

Pen_Up::Pen_Up(Turtle* turtle): _turtle(turtle){}
void Pen_Up::execute(){ _turtle->setPenStatus(false); }
const char* Pen_Up::getName(){ return "Pen_Up"; }

Do::Do(Turtle* turtle, unsigned int numReplays): _turtle(turtle), _numReplays(numReplays){}
void Do::execute()
{
    for (size_t i = 0; i < _numReplays; i++)
        for (auto&& i : _commands)
            i->execute();
}
const char* Do::getName(){ return "Do"; }
void Do::addCommand(Command* newCommand){ _commands.push_back(newCommand); }

Pen_Definition::Pen_Definition(Turtle* turtle, double width, rgb color):
    _turtle(turtle), _width(width), _color(color){}
void Pen_Definition::execute()
{
    _turtle->setPenWidth(_width);
    _turtle->setPenColor(_color);
}
const char* Pen_Definition::getName(){ return "Pen_Definition"; }

Pen_Selection::Pen_Selection(Define_List* defList, int number):
    _defList(defList), _number(number){}
void Pen_Selection::execute()
{
    _defList->applyDefinition(_number);
}
const char* Pen_Selection::getName(){ return "Pen_Selection"; }

Canvas_Definition::Canvas_Definition(Canvas* canvas, Turtle* turtle, point_LL sizeBitMap,
    rgb color): _canvas(canvas), _turtle(turtle), _sizeBitMap(sizeBitMap),
    _color(color), _p1({0, 0}), _p2({1, 1}){}
Canvas_Definition::Canvas_Definition(Canvas* canvas, Turtle* turtle, point_LL sizeBitMap,
    rgb color, point_D p1, point_D p2): _canvas(canvas), _turtle(turtle),
    _sizeBitMap(sizeBitMap), _color(color), _p1(p1), _p2(p2){}
void Canvas_Definition::execute()
{
    _canvas->createBitMap(_sizeBitMap);
    _canvas->setCanvasColor(_color);
    _turtle->setCanvasParameters(_p1, _p2);
    _turtle->moveTo(_p1);
}
const char* Canvas_Definition::getName(){ return "Canvas_Definition"; }
