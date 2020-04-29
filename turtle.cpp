#include <cmath>
#include <iostream>
#include <iomanip>
#include "turtle.hpp"
#include "canvas.hpp"

const double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;

Turtle::Turtle(Canvas& canvas, Define_List& defineList): _canvas(canvas),
    _defineList(defineList),  _leftDownCorner(0, 0), _rigtUpCorner(1, 1),
    _pos(0, 0), _direction(90), _isPenDown(false), _width(1), _color(0, 0, 0){}

void Turtle::move(double distance)
{
    double newX = _pos.x + distance * std::cos(anglesToRadians(_direction));
    double newY = _pos.y + distance * std::sin(anglesToRadians(_direction));

std::cout << "\ndirection: " << _direction << "\n";
std::cout << "new x : " << std::setprecision(20) << newX << "\n";
std::cout << "new y : " << std::setprecision(20) << newY << "\n";

    double xRealInImmage = (double)(_canvas.getSizeBitMap().x) / (_rigtUpCorner.x - _leftDownCorner.x);
    double yRealInImmage = (double)(_canvas.getSizeBitMap().y) / (_rigtUpCorner.y - _leftDownCorner.y);

    point_LL pointFrom((_pos.x - _leftDownCorner.x) * xRealInImmage, (_pos.y - _leftDownCorner.y) * yRealInImmage);
    point_LL pointTo((newX - _leftDownCorner.x) * xRealInImmage, (newY - _leftDownCorner.y) * yRealInImmage);

    unsigned newWidth = unsigned((xRealInImmage + yRealInImmage) / 2 * _width);
    _canvas.drawLine(pointFrom, pointTo, _color, newWidth);

    _pos.x = newX;
    _pos.y = newY;
}
void Turtle::moveTo(point_D newPoint)
{
    double xRealInImmage = ((double)(_canvas.getSizeBitMap().x)) / (_rigtUpCorner.x - _leftDownCorner.x);
    double yRealInImmage = ((double)(_canvas.getSizeBitMap().y)) / (_rigtUpCorner.y - _leftDownCorner.y);

    point_LL pointFrom = {(_pos.x - _leftDownCorner.x) * xRealInImmage, (_pos.y - _leftDownCorner.y) * yRealInImmage};
    point_LL pointTo = {(newPoint.x - _leftDownCorner.x) * xRealInImmage, (newPoint.y - _leftDownCorner.y) * yRealInImmage};

    unsigned newWidth = unsigned((xRealInImmage + yRealInImmage) / 2 * _width);
    _canvas.drawLine(pointFrom, pointTo, _color, newWidth);

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
    _isPenDown = newStatus;
}
void Turtle::setPenWidth(double width)
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
