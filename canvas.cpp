#include <iostream>
#include <exception>
#include "canvas.hpp"

Bit_Map::Bit_Map(point_LL size): _size(size)
{
    _data = new char[_size.x * _size.y];
}
Bit_Map::~Bit_Map()
{
    delete [] _data;
}
void printPoint(point_LL point)
{
    throw std::runtime_error("not realised featch");
}

Canvas::Canvas(std::shared_ptr<Drawer> drawer): _drawer(drawer){}
void Canvas::draw(point_LL point1, point_LL point2, rgb color, unsigned width)
{
    _drawer->draw(_bitMap, point1, point2, color, width);
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

void Loger::draw(std::shared_ptr<Bit_Map> bitMap, point_LL point1, point_LL point2,
                 rgb color, unsigned width) const
{
    std::cout << "line: from (" << point1.x << ", " << point1.y << ") to (";
    std::cout << point2.x << ", " << point2.y;
    std::cout << "); width: " << width << "; color: " << (int)color._red;
    std::cout << " " << (int)color._green << " " << (int)color._blue << "\n";
}
