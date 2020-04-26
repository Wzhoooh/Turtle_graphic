#ifndef COMMAND_FACTORY_HPP_INCLUDED
#define COMMAND_FACTORY_HPP_INCLUDED

#include <memory>
#include "primitives.hpp"

class Turtle;
class Canvas;
class Define_List;
class Command;

class Command_Factory
{
public:
    Command_Factory(Turtle* turtle, Canvas* canvas, Define_List* defList);
    Command* crMove(double distance);
    Command* crMove_To(point_D newPoint);
    Command* crTurn(double angle);
    Command* crTurn_Left();
    Command* crTurn_Right();
    Command* crTurn_South();
    Command* crTurn_North();
    Command* crTurn_West();
    Command* crTurn_East();
    Command* crPen_Down();
    Command* crPen_Up();
    Command* crDo(unsigned int numReplays);
    Command* crPen_Definition(unsigned width, rgb color);
    Command* crPen_Selection(int number);
    Command* crCanvas_Definition(point_LL sizeBitMap, rgb color);
    Command* crCanvas_Definition(point_LL sizeBitMap, rgb color, point_D p1, point_D p2);

private:
    Turtle* _turtle;
    Canvas* _canvas;
    Define_List* _defList;
};

#endif // COMMAND_FACTORY_HPP_INCLUDED
