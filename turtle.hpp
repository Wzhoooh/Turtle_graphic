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
    void setPen(int penNumber);
    void setPenWidth(unsigned width);
    void setPenColor(char color);
    void setCanvasParameters(long double x1, long double y1, long double x2, long double y2, char canvasColor);

private:
    std::shared_ptr<Canvas> _canvas;
    std::shared_ptr<Define_List> _defineList;
    long double _xPos = 0;
    long double _yPos = 0;
    long double _direction = 0;
    bool _penStatus = true;
    unsigned _width = 1;
    char _color = 0;

    long double _x1 = 0, _y1 = 0, _x2 = 1, _y2 = 1; // coordinates of regading grid of canvas
    char _canvasColor = 0;
};

#endif // TURTLE_H_INCLUDED
