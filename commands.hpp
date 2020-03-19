#ifndef COMMANDS_HPP_INCLUDED
#define COMMANDS_HPP_INCLUDED

#include <exception>
#include <memory>
#include "list.hpp"

class Turtle;

class Command
{
public:
    virtual void execute() = 0;
    virtual const char* getName() = 0;
    virtual addCommand(Command&&)
    {
        throw std::runtime_error("not \"Do\" command");
    }
//    virtual ~Command() = 0;
};

class Move: public Command
{
public:
    Move(std::shared_ptr<Turtle> turtle, long double distance);
    Move(const Move&);
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
    Move_To(const Move_To&);
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
    Turn_Left(const Turn_Left&);
    void execute();
    const char* getName();

private:
    std::shared_ptr<Turtle> _turtle;
};

class Turn_Right: public Command
{
public:
    Turn_Right(std::shared_ptr<Turtle> turtle);
    Turn_Right(const Turn_Right&);
    void execute();
    const char* getName();

private:
    std::shared_ptr<Turtle> _turtle;
};

class Turn_South: public Command
{
public:
    Turn_South(std::shared_ptr<Turtle> turtle);
    Turn_South(const Turn_South&);
    void execute();
    const char* getName();

private:
    std::shared_ptr<Turtle> _turtle;
};

class Turn_North: public Command
{
public:
    Turn_North(std::shared_ptr<Turtle> turtle);
    Turn_North(const Turn_North&);
    void execute();
    const char* getName();

private:
    std::shared_ptr<Turtle> _turtle;
};

class Turn_West: public Command
{
public:
    Turn_West(std::shared_ptr<Turtle> turtle);
    Turn_West(const Turn_West&);
    void execute();
    const char* getName();

private:
    std::shared_ptr<Turtle> _turtle;
};

class Turn_East: public Command
{
public:
    Turn_East(std::shared_ptr<Turtle> turtle);
    Turn_East(const Turn_East&);
    void execute();
    const char* getName();

private:
    std::shared_ptr<Turtle> _turtle;
};

class Pen_Down: public Command
{
public:
    Pen_Down(std::shared_ptr<Turtle> turtle);
    Pen_Down(const Pen_Down&);
    void execute();
    const char* getName();

private:
    std::shared_ptr<Turtle> _turtle;
};

class Pen_Up: public Command
{
public:
    Pen_Up(std::shared_ptr<Turtle> turtle);
    Pen_Up(const Pen_Up&);
    void execute();
    const char* getName();

private:
    std::shared_ptr<Turtle> _turtle;
};

class Do: public Command
{
public:
    Do(std::shared_ptr<Turtle> turtle, unsigned int numReplays);
    Do(const Do&);
    void execute();
    const char* getName();
    virtual addCommand(Command&&);

private:
    std::shared_ptr<Turtle> _turtle;
    dataStructures::list<Command> _commands;
    unsigned int _numReplays;
};

#endif // COMMANDS_HPP_INCLUDED
