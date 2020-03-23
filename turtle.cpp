#include <math.h>
#include "turtle.hpp"
#include "canvas.hpp"

Turtle::Turtle(std::shared_ptr<Canvas> canvas, std::shared_ptr<Define_List> defineList): _canvas(canvas), _defineList(defineList)
{
    _pos = {0, 0};
    _leftDownCorner = {0, 0};
    _rigtUpCorner = {1, 1};
}

void Turtle::move(long double distance)
{
    long double newX = _pos.x + distance*cosl(_direction), newY = _pos.y + distance*sinl(_direction);
    long double xAbsoluteInRegard = ((double)(_canvas->getSizeBitMap().x)) / (_rigtUpCorner.x - _leftDownCorner.x);
    long double yAbsoluteInRegard = ((double)(_canvas->getSizeBitMap().y)) / (_rigtUpCorner.y - _leftDownCorner.y);

    point_LL p1 = {(_pos.x - _leftDownCorner.x) * xAbsoluteInRegard, (_pos.y - _leftDownCorner.y) * yAbsoluteInRegard};
    point_LL p2 = {(newX - _leftDownCorner.x) * xAbsoluteInRegard,  (newY - _leftDownCorner.y) * yAbsoluteInRegard};
    _canvas->printLine(p1, p2, _color, _width);

    _pos.x = newX;
    _pos.y = newY;
}
void Turtle::moveTo(long double x, long double y)
{
    long double xAbsoluteInRegard = ((double)(_canvas->getSizeBitMap().x)) / (_rigtUpCorner.x - _leftDownCorner.x);
    long double yAbsoluteInRegard = ((double)(_canvas->getSizeBitMap().y)) / (_rigtUpCorner.y - _leftDownCorner.y);

    point_LL p1 = {(_pos.x - _leftDownCorner.x) * xAbsoluteInRegard, (_pos.y - _leftDownCorner.y) * yAbsoluteInRegard};
    point_LL p2 = {(x - _leftDownCorner.x) * xAbsoluteInRegard,  (y - _leftDownCorner.y) * yAbsoluteInRegard};
    _canvas->printLine(p1, p2, _color, _width);

    _pos.x = x;
    _pos.y = y;
}
void Turtle::changeDirection(long double addAngle)
{
    _direction += addAngle;
}
void Turtle::setDirection(long double angle)
{
    _direction = angle;
}
void Turtle::setPenStatus(bool newStatus)
{
    _penStatus = newStatus;
}
void Turtle::setPenWidth(unsigned width)
{
    _width = width;
}
void Turtle::setPenColor(rgb color)
{
    _color = color;
}
void Turtle::setCanvasParameters(point_LD p1, point_LD p2)
{
    _leftDownCorner = p1;
    _rigtUpCorner = p2;
}
