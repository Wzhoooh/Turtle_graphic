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
    std::shared_ptr<Command> crMove(double distance);
    std::shared_ptr<Command> crMove_To(point_D newPoint);
    std::shared_ptr<Command> crTurn(double angle);
    std::shared_ptr<Command> crTurn_Left();
    std::shared_ptr<Command> crTurn_Right();
    std::shared_ptr<Command> crTurn_South();
    std::shared_ptr<Command> crTurn_North();
    std::shared_ptr<Command> crTurn_West();
    std::shared_ptr<Command> crTurn_East();
    std::shared_ptr<Command> crPen_Down();
    std::shared_ptr<Command> crPen_Up();
    std::shared_ptr<Command> crDo(unsigned int numReplays);
    std::shared_ptr<Command> crPen_Definition(unsigned width, rgb color);
    std::shared_ptr<Command> crPen_Selection(int number);
    std::shared_ptr<Command> crCanvas_Definition(point_LL sizeBitMap, rgb color);
    std::shared_ptr<Command> crCanvas_Definition(point_LL sizeBitMap, rgb color,
                                                     point_D p1, point_D p2);

private:
    Turtle* _turtle;
    Canvas* _canvas;
    Define_List* _defList;

    std::shared_ptr<Command> _turnSouth;
    std::shared_ptr<Command> _turnNorth;
    std::shared_ptr<Command> _turnWest;
    std::shared_ptr<Command> _turnEast;
    std::shared_ptr<Command> _penDown;
    std::shared_ptr<Command> _penUp;
};

#endif // COMMAND_FACTORY_HPP_INCLUDED
