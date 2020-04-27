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
void Bit_Map::drawPoint(point_LL point)
{
    throw std::runtime_error("not realised featch");
}
point_LL Bit_Map::getSize() const
{
    return _size;
}

Canvas::Canvas(Drawer&& drawer): _drawer(drawer){}
void Canvas::draw(point_LL point1, point_LL point2, rgb color, unsigned width)
{
    _drawer.draw(*_bitMap, point1, point2, color, width);
}
point_LL Canvas::getSizeBitMap() const
{
    return _bitMap->getSize();
}
void Canvas::createBitMap(point_LL sizeBitMap)
{
    _bitMap = new Bit_Map(sizeBitMap);
}
void Canvas::setCanvasColor(rgb canvasColor)
{
    _canvasColor = canvasColor;
}
Canvas::~Canvas()
{
    delete _bitMap;
}

void Loger::draw(Bit_Map& bitMap, point_LL point1, point_LL point2,
                 rgb color, unsigned width) const
{
    std::cout << "Loger: from (" << point1.x << ", " << point1.y << ") to (";
    std::cout << point2.x << ", " << point2.y;
    std::cout << "); width: " << width << "; color: " << (int)color.red;
    std::cout << " " << (int)color.green << " " << (int)color.blue << "\n";
}
