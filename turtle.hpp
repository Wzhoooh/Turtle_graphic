#ifndef TURTLE_H_INCLUDED
#define TURTLE_H_INCLUDED

#include <memory>
#include "add_structures.hpp"

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
    void setPenWidth(unsigned width);
    void setPenColor(rgb color);
    void setCanvasParameters(point_LD p1, point_LD p2);

private:
    std::shared_ptr<Canvas> _canvas;
    std::shared_ptr<Define_List> _defineList;
    point_LD _pos;
    long double _direction = 0;
    bool _penStatus = false;
    unsigned _width = 1;
    rgb _color;

    point_LD _leftDownCorner;
    point_LD _rigtUpCorner; // coordinates of regading grid of canvas
};

#endif // TURTLE_H_INCLUDED
