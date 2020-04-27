#ifndef TURTLE_H_INCLUDED
#define TURTLE_H_INCLUDED

#include <memory>
#include "primitives.hpp"

class Canvas;
class Define_List;

class Turtle
{
public:
    Turtle(Canvas* canvas, Define_List* defineList);
    void move(double distance);
    void moveTo(point_D newPoint);
    void changeDirection(double addAngle);
    void setDirection(double angle);
    void setPenStatus(bool newStatus);
    void setPenWidth(double width);
    void setPenColor(rgb color);
    void setCanvasParameters(point_D p1, point_D p2);

private:
    double anglesToRadians(double angle);

private:
    Canvas* _canvas;
    Define_List* _defineList;
    point_D _pos;
    double _direction;
    bool _isPenDown;
    double _width;
    rgb _color;

    point_D _leftDownCorner;
    point_D _rigtUpCorner; // coordinates of regading grid of canvas
};

#endif // TURTLE_H_INCLUDED
