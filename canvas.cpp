#include <iostream>
#include "canvas.hpp"

void Canvas::printLine(point_LL point1, point_LL point2, rgb color, unsigned width)
{
    std::cout << "line: from (" << point1.x << ", " << point1.y << ") to " << point2.x << ", " << point2.y;
    std::cout << "); width: " << width << "; color: " << color._red << " " << color._green << " " << color._blue << "\n";
}
point_LL Canvas::getSizeBitMap() const
{
    return _sizeBitMap;
}
void Canvas::setSizeBitMap(point_LL sizeBitMap)
{
    _sizeBitMap = sizeBitMap;
}
void Canvas::setCanvasColor(rgb canvasColor)
{
    _canvasColor = canvasColor;
}
Canvas::~Canvas()
{
    std::cout << "Destructor canvas\n";
}
