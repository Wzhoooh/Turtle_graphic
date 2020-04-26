#include "command_factory.hpp"
#include "commands.hpp"
#include "turtle.hpp"
#include "canvas.hpp"

Command_Factory::Command_Factory(Turtle* turtle, Canvas* canvas, Define_List* defList):
    _turtle(turtle), _canvas(canvas), _defList(defList){}

Command* Command_Factory::crMove(double distance)
{
    return new Move(_turtle, distance);
}
Command* Command_Factory::crMove_To(point_D newPoint)
{
    return new Move_To(_turtle, newPoint);
}
Command* Command_Factory::crTurn(double angle)
{
    return new Turn(_turtle, angle);
}
Command* Command_Factory::crTurn_Left()
{
    return new Turn_Left(_turtle);
}
Command* Command_Factory::crTurn_Right()
{
    return new Turn_Right(_turtle);
}
Command* Command_Factory::crTurn_South()
{
    return new Turn_South(_turtle);
}
Command* Command_Factory::crTurn_North()
{
    return new Turn_North(_turtle);
}
Command* Command_Factory::crTurn_West()
{
    return new Turn_West(_turtle);
}
Command* Command_Factory::crTurn_East()
{
    return new Turn_East(_turtle);
}
Command* Command_Factory::crPen_Down()
{
    return new Pen_Down(_turtle);
}
Command* Command_Factory::crPen_Up()
{
    return new Pen_Up(_turtle);
}
Command* Command_Factory::crDo(unsigned int numReplays)
{
    return new Do(_turtle, numReplays);
}
Command* Command_Factory::crPen_Definition(unsigned width, rgb color)
{
    return new Pen_Definition(_turtle, width, color);
}
Command* Command_Factory::crPen_Selection(int number)
{
    return new Pen_Selection(_defList, number);
}
Command* Command_Factory::crCanvas_Definition(point_LL sizeBitMap, rgb color)
{
    return new Canvas_Definition(_canvas, _turtle, sizeBitMap, color);
}
Command* Command_Factory::crCanvas_Definition(point_LL sizeBitMap, rgb color,
    point_D p1, point_D p2)
{
    return new Canvas_Definition(_canvas, _turtle, sizeBitMap, color, p1, p2);
}
