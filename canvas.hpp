#ifndef CANVAS_HPP_INCLUDED
#define CANVAS_HPP_INCLUDED

#include "primitives.hpp"

class Canvas // all coordinates in pixels
{
public:
    void printLine(point_LL point1, point_LL point2, rgb color, unsigned width); // all coordinates in pixels
    point_LL getSizeBitMap() const;
    void setSizeBitMap(point_LL sizeBitMap);
    void setCanvasColor(rgb canvasColor);
    ~Canvas();

private:
    char* _bitMap;
    point_LL _sizeBitMap;
    rgb _canvasColor;
};

#endif // CANVAS_HPP_INCLUDED
