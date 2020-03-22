#include "turtle.hpp"


Turtle::Turtle(std::shared_ptr<Canvas> canvas, std::shared_ptr<Define_List> defineList): _canvas(canvas), _defineList(defineList)
{}

void Turtle::move(long double distance)
{
    long double newX = _xPos + distance*cosh(_direction), newY = _yPos + distance*sinh(_direction);
    long double xAbsoluteInRegard = ((double)(_canvas->getlenGorisontal())) / (_x2 - _x1);
    long double yAbsoluteInRegard = ((double)(_canvas->getLenVertical())) / (_y2 - _y1);
    _canvas->printLine((_xPos - _x1) * xAbsoluteInRegard, (_yPos - _y1) * yAbsoluteInRegard,
                    (newX - _x1) * xAbsoluteInRegard,  (newY - _y1) * yAbsoluteInRegard, _color, _width);

    _xPos = newX;
    _yPos = newY;
}
void Turtle::moveTo(long double x, long double y)
{
    long double xAbsoluteInRegard = ((double)(_canvas->getlenGorisontal())) / (_x2 - _x1);
    long double yAbsoluteInRegard = ((double)(_canvas->getLenVertical())) / (_y2 - _y1);
    _canvas->printLine((_xPos - _x1) * xAbsoluteInRegard, (_yPos - _y1) * yAbsoluteInRegard,
                    (x - _x1) * xAbsoluteInRegard,  (y - _y1) * yAbsoluteInRegard, _color, _width);

    _xPos = x;
    _yPos = y;
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
void setPen(int penNumber)
{
    _defineList->applyDefinitioin(penNumber);
}
void Turtle::setPenWidth(unsigned width)
{
    _width = width;
}
void Turtle::setPenColor(char color)
{
    _color = color;
}
void setCanvasParameters(long double x1, long double y1, long double x2, long double y2, char canvasColor)
{
    _x1 = x1;
    _y1 = y1;
    _x2 = x2;
    _y2 = y2;
    _canvasColor = canvasColor;
}
