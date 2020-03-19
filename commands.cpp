#include <iostream>
#include "commands.hpp"

Move::Move(std::shared_ptr<Turtle> turtle, long double distance): _turtle(turtle), _distance(distance)
{}
Move::Move(const Move& s): _turtle(s._turtle), _distance(s._distance)
{}

void Move::execute()
{
    std::cout << "i move" << _distance << "\n";
}
const char* Move::getName()
{
    return "move";
}
