#ifndef TURTLE_H_INCLUDED
#define TURTLE_H_INCLUDED

#include <memory>
#include "primitives.hpp"

class Canvas;
class Define_List;

class Turtle
{
public:
    Turtle(std::shared_ptr<Canvas> canvas, std::shared_ptr<Define_List> defineList);
    void move(double distance);
    void moveTo(point_D newPoint);
    void changeDirection(double addAngle);
    void setDirection(double angle);
    void setPenStatus(bool newStatus);
    void setPenWidth(unsigned width);
    void setPenColor(rgb color);
    void setCanvasParameters(point_D p1, point_D p2);

private:
    double anglesToRadians(double angle);

private:
    std::shared_ptr<Canvas> _canvas;
    std::shared_ptr<Define_List> _defineList;
    point_D _pos;
    double _direction;
    bool _penStatus = false;
    unsigned _width = 1;
    rgb _color;

    point_D _leftDownCorner;
    point_D _rigtUpCorner; // coordinates of regading grid of canvas
};

#endif // TURTLE_H_INCLUDED
