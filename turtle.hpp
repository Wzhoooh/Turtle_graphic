#ifndef TURTLE_H_INCLUDED
#define TURTLE_H_INCLUDED

#include <memory>

class Canvas;
class Define_List;

class Turtle
{
public:
    Turtle(std::shared_ptr<Canvas> canvas, std::shared_ptr<Define_List> defineList);
    void move(long double distance);
    void moveTo(long double x, long double y);
    void changeDirection(long double addAngle);
    void setDirection(long double angle);
    void setPenStatus(bool newStatus);

private:
    std::shared_ptr<Canvas> _canvas;
    long double _xPos;
    long double _yPos;
    long double _direction;
    bool _penStatus;
    long double _x1, _y1, _x2, _y2;
};

#endif // TURTLE_H_INCLUDED
