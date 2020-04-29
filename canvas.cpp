#include <iostream>
#include <exception>
#include "canvas.hpp"

Bit_Map::Bit_Map(point_LL size, rgb canvasColor): _size(size)
{
    _buffer = new rgb[_size.x * _size.y];
    for (size_t i = 0; i < _size.x * _size.y; ++i)
        _buffer[i] = canvasColor;
}
Bit_Map::~Bit_Map()
{
    delete [] _buffer;
}
inline void Bit_Map::drawPoint(point_LL point, rgb color)
{
    if (point.x >= 0 && point.x < _size.x && point.y >= 0 && point.y < _size.y)
        _buffer[point.x + point.y * _size.x] = color;
}
point_LL Bit_Map::getSize() const
{
    return _size;
}
const rgb* Bit_Map::getBuffer() const
{
    return _buffer;
}

Canvas::Canvas(Drawer&& drawer): _drawer(drawer){}
void Canvas::drawLine(point_LL point1, point_LL point2, rgb color, unsigned width)
{
    _drawer.drawLine(*_bitMap, point1, point2, color, width);
}
point_LL Canvas::getSizeBitMap() const
{
    return _bitMap->getSize();
}
void Canvas::createBitMap(point_LL sizeBitMap, rgb canvasColor)
{
    _bitMap = new Bit_Map(sizeBitMap, canvasColor);
}
const rgb* Canvas::getBuffer() const
{
    return _bitMap->getBuffer();
}
Canvas::~Canvas()
{
    delete _bitMap;
}

void Logger::drawLine(Bit_Map& bitMap, point_LL point1, point_LL point2,
                 rgb color, unsigned width) const
{
    std::cout << "Loger: line from (" << point1.x << ", " << point1.y << ") to (";
    std::cout << point2.x << ", " << point2.y;
    std::cout << "); width: " << width << "; color: " << (int)color.red;
    std::cout << " " << (int)color.green << " " << (int)color.blue << "\n";
}

void Round_Pen_Drawer::drawVerticalLine(Bit_Map& bitMap, point_LL point1, point_LL point2, rgb color) const
{
    if (point1.y > point2.y)
        std::swap(point1.y, point2.y);
    for (int y = point1.y; y <= point2.y; ++y)
        drawPoint(bitMap, point_LL(point1.x, y), color);
}

void Round_Pen_Drawer::drawHorizontalLine(Bit_Map& bitMap, point_LL point1, point_LL point2, rgb color) const
{
    if (point1.x > point2.x)
        std::swap(point1.x, point2.x);
    for (int x = point1.x; x <= point2.x; ++x)
        drawPoint(bitMap, point_LL(x, point1.y), color);
}

void Round_Pen_Drawer::drawLine(Bit_Map& bitMap, point_LL point1, point_LL point2,
              rgb color, unsigned width) const
{
    if (point1.x == point2.x)
    {
        drawVerticalLine(bitMap, point1, point2, color);
        return;
    }

    if (point1.y == point2.y)
    {
        drawHorizontalLine(bitMap, point1, point2, color);
        return;
    }

    // по Брезенхэму
    int deltaX = std::abs(point2.x - point1.x);
    int deltaY = std::abs(point2.y - point1.y);
    int signX = point1.x < point2.x ? 1 : -1;
    int signY = point1.y < point2.y ? 1 : -1;
    int error = deltaX - deltaY;

    drawCircle(bitMap, point2, color, width);
    while ((point1.x != point2.x) || (point1.y != point2.y))
    {
        drawCircle(bitMap, point1, color, width);

        int error2 = error * 2;

        if (error2 > -deltaY)
        {
            error -= deltaY;
            point1.x += signX;
        }

        if (error2 < deltaX)
        {
            error += deltaX;
            point1.y += signY;
        }
    }
}
void Round_Pen_Drawer::drawCircle(Bit_Map& bitMap, point_LL center, rgb color, unsigned width) const
{
    if (width <= 1)
    {
        drawPoint(bitMap, center, color);
        return;
    }

    int radius = width/2;
    int d = 1 - radius;
    int x = radius;
    int y = 0;
    while (y <= x)
    {
        // основная линия
        drawHorizontalLine(bitMap, point_LL(center.x - x, center.y - y), point_LL(center.y - y, center.x + x), color);
        drawHorizontalLine(bitMap, point_LL(center.x - x, center.y + y), point_LL(center.y + y, center.x + x), color);
        // отражение концов относительно линии y=x
        drawHorizontalLine(bitMap, point_LL(center.x - y, center.y - x), point_LL(center.x + y, center.y - x), color);
        drawHorizontalLine(bitMap, point_LL(center.x - y, center.y + x), point_LL(center.x + y, center.y + x), color);

        if (d <= 0)
        {
            ++y;
            d += 2 * y + 1;
        }
        else
        {
            --x;
            ++y;
            d += 2 * (y - x) + 1;
        }
    }
}

inline void Round_Pen_Drawer::drawPoint(Bit_Map& bitMap, point_LL point, rgb color) const
{
    bitMap.drawPoint(point, color);
}
