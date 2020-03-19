#ifndef TURTLE_H_INCLUDED
#define TURTLE_H_INCLUDED

#include <memory>

class Canvas;

class Turtle
{
public:
    Turtle(std::shared_ptr<Canvas> canvas);
    void move(long double distance);
    void moveTo(long double x, long double y);
    void changeDirection(long double anglePlus);
    void setDirection(long double angle);
    void setPenStatus(bool newStatus);

private:
    std::shared_ptr<Canvas> _canvas;
    long double _x;
    long double _y;
    long double _direction;
    bool _penStatus;
};

#endif // TURTLE_H_INCLUDED
