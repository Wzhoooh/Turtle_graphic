#include <cmath>
#include <iostream>
#include "turtle.hpp"
#include "canvas.hpp"

const double PI = 3.141592653589793238463;

Turtle::Turtle(std::shared_ptr<Canvas> canvas, std::shared_ptr<Define_List> defineList): _canvas(canvas), _defineList(defineList)
{
    _pos = {0, 0};
    _leftDownCorner = {0, 0};
    _rigtUpCorner = {1, 1};
    _direction = 0;
}

void Turtle::move(double distance)
{
    double newX = _pos.x + distance * std::cos(anglesToRadians(_direction));
    double newY = _pos.y + distance * std::sin(anglesToRadians(_direction));
std::cout << "\ndirection: " << _direction << "\n";
std::cout << "new x : " << newX << "\n";
std::cout << "new y : " << newY << "\n";

    double xAbsoluteInRegard = (double)(_canvas->getSizeBitMap().x) / (_rigtUpCorner.x - _leftDownCorner.x);
    double yAbsoluteInRegard = (double)(_canvas->getSizeBitMap().y) / (_rigtUpCorner.y - _leftDownCorner.y);

    point_LL pointFrom = {(_pos.x - _leftDownCorner.x) * xAbsoluteInRegard, (_pos.y - _leftDownCorner.y) * yAbsoluteInRegard};
    point_LL pointTo = {(newX - _leftDownCorner.x) * xAbsoluteInRegard,  (newY - _leftDownCorner.y) * yAbsoluteInRegard};
    _canvas->printLine(pointFrom, pointTo, _color, _width);

    _pos.x = newX;
    _pos.y = newY;
}
void Turtle::moveTo(point_D newPoint)
{
    double xAbsoluteInRegard = ((double)(_canvas->getSizeBitMap().x)) / (_rigtUpCorner.x - _leftDownCorner.x);
    double yAbsoluteInRegard = ((double)(_canvas->getSizeBitMap().y)) / (_rigtUpCorner.y - _leftDownCorner.y);

    point_LL pointFrom = {(_pos.x - _leftDownCorner.x) * xAbsoluteInRegard, (_pos.y - _leftDownCorner.y) * yAbsoluteInRegard};
    point_LL pointTo = {(newPoint.x - _leftDownCorner.x) * xAbsoluteInRegard,  (newPoint.y - _leftDownCorner.y) * yAbsoluteInRegard};
    _canvas->printLine(pointFrom, pointTo, _color, _width);

    _pos.x = newPoint.x;
    _pos.y = newPoint.y;
}
void Turtle::changeDirection(double addAngle)
{
    _direction += addAngle;
}
void Turtle::setDirection(double angle)
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
void Turtle::setCanvasParameters(point_D p1, point_D p2)
{
    _leftDownCorner = p1;
    _rigtUpCorner = p2;
}

double Turtle::anglesToRadians(double angle)
{
    return angle * PI / 180.0d;
}
