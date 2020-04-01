#include "command_factory.hpp"
#include "commands.hpp"
#include "turtle.hpp"
#include "canvas.hpp"

Command_Factory::Command_Factory(std::shared_ptr<Turtle> turtle, std::shared_ptr<Canvas> canvas,
std::shared_ptr<Define_List> defList): _turtle(turtle), _canvas(canvas), _defList(defList)
{
    _turnSouth  = std::make_shared<Turn_South>(_turtle);
    _turnNorth  = std::make_shared<Turn_North>(_turtle);
    _turnWest   = std::make_shared<Turn_West>(_turtle);
    _turnEast   = std::make_shared<Turn_East>(_turtle);
    _penDown    = std::make_shared<Pen_Down>(_turtle);
    _penUp      = std::make_shared<Pen_Up>(_turtle);
}

std::shared_ptr<Command> Command_Factory::crMove(double distance)
{
    return std::make_shared<Move>(_turtle, distance);
}
std::shared_ptr<Command> Command_Factory::crMove_To(point_D newPoint)
{
    return std::make_shared<Move_To>(_turtle, newPoint);
}
std::shared_ptr<Command> Command_Factory::crTurn(double angle)
{
    return std::make_shared<Turn>(_turtle, angle);
}
std::shared_ptr<Command> Command_Factory::crTurn_Left()
{
    return std::make_shared<Turn_Left>(_turtle);
}
std::shared_ptr<Command> Command_Factory::crTurn_Right()
{
    return std::make_shared<Turn_Right>(_turtle);
}
std::shared_ptr<Command> Command_Factory::crTurn_South()
{
    return _turnSouth;
}
std::shared_ptr<Command> Command_Factory::crTurn_North()
{
    return _turnNorth;
}
std::shared_ptr<Command> Command_Factory::crTurn_West()
{
    return _turnWest;
}
std::shared_ptr<Command> Command_Factory::crTurn_East()
{
    return _turnEast;
}
std::shared_ptr<Command> Command_Factory::crPen_Down()
{
    return _penDown;
}
std::shared_ptr<Command> Command_Factory::crPen_Up()
{
    return _penUp;
}
std::shared_ptr<Command> Command_Factory::crDo(unsigned int numReplays)
{
    return std::make_shared<Do>(_turtle, numReplays);
}
std::shared_ptr<Command> Command_Factory::crPen_Definition(unsigned width, rgb color)
{
    return std::make_shared<Pen_Definition>(_turtle, width, color);
}
std::shared_ptr<Command> Command_Factory::crPen_Selection(int number)
{
    return std::make_shared<Pen_Selection>(_defList, number);
}
std::shared_ptr<Command> Command_Factory::crCanvas_Definition(point_LL sizeBitMap, rgb color)
{
    return std::make_shared<Canvas_Definition>(_canvas, _turtle, sizeBitMap, color);
}
std::shared_ptr<Command> Command_Factory::crCanvas_Definition(point_LL sizeBitMap, rgb color,
point_D p1, point_D p2)
{
    return std::make_shared<Canvas_Definition>(_canvas, _turtle, sizeBitMap, color, p1, p2);
}
