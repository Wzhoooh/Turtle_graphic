#ifndef COMMAND_FACTORY_HPP_INCLUDED
#define COMMAND_FACTORY_HPP_INCLUDED

#include <memory>

class Turtle;
class Command;

class Command_Factory
{
public:
    Command_Factory(std::shared_ptr<Turtle> turtle);
    std::shared_ptr<Command> createMove(long double distance);
    std::shared_ptr<Command> createMove_To(long double x, long double y);
    std::shared_ptr<Command> createTurn_Left();
    std::shared_ptr<Command> createTurn_Right();
    std::shared_ptr<Command> createTurn_South();
    std::shared_ptr<Command> createTurn_North();
    std::shared_ptr<Command> createTurn_West();
    std::shared_ptr<Command> createTurn_East();
    std::shared_ptr<Command> createPen_Down();
    std::shared_ptr<Command> createPen_Up();
    std::shared_ptr<Command> createDo(unsigned int numReplays);
    std::shared_ptr<Command> createPen_Definition(int number, unsigned width, char color);

private:
    std::shared_ptr<Command> _turnSouth;
    std::shared_ptr<Command> _turnNorth;
    std::shared_ptr<Command> _turnWest;
    std::shared_ptr<Command> _turnEast;
    std::shared_ptr<Command> _penDown;
    std::shared_ptr<Command> _penUp;
};

#endif // COMMAND_FACTORY_HPP_INCLUDED
