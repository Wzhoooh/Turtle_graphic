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
    void setWiew(long double x1, long double y1, long double x2, long double y2);

private:
    std::shared_ptr<Canvas> _canvas;
    long double _xPos;
    long double _yPos;
    long double _direction;
    bool _penStatus;
    long double _x1, _y1, _x2, _y2;
};

#endif // TURTLE_H_INCLUDED
