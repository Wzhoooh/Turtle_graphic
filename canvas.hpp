#ifndef CANVAS_HPP_INCLUDED
#define CANVAS_HPP_INCLUDED

#include <memory>
#include "primitives.hpp"

class Drawer;
class Bit_Map;

class Bit_Map
{
public:
    Bit_Map(point_LL size, rgb canvasColor);
    ~Bit_Map();
    void drawPoint(point_LL point, rgb color);
    inline point_LL getSize() const { return _size; }
    void uploadToBmp(const char* fileName);

private:
    rgb* _buffer;
    point_LL _size;
};

class Canvas // all coordinates in pixels
{
public:
    Canvas(Drawer&& drawer);
    void drawLine(point_LL point1, point_LL point2, rgb color, unsigned width); // all coordinates in pixels
    point_LL getSizeBitMap() const;
    void createBitMap(point_LL sizeBitMap, rgb canvasColor);
    void uploadToBmp(const char* fileName);

    ~Canvas();

private:
    Drawer& _drawer;
    Bit_Map* _bitMap;
};

class Drawer
{
public:
    virtual void drawLine(Bit_Map& bitMap, point_LL point1, point_LL point2,
                      rgb color, unsigned width) const = 0;
};

class Logger: public Drawer
{
public:
    void drawLine(Bit_Map& bitMap, point_LL point1, point_LL point2,
              rgb color, unsigned width) const override;
};

class Round_Pen_Drawer: public Drawer
{
public:
    void drawLine(Bit_Map& bitMap, point_LL point1, point_LL point2,
              rgb color, unsigned width) const override;

private:
    void drawVerticalLine(Bit_Map& bitMap, point_LL point1, point_LL point2,
                          rgb color, unsigned width) const;
    void drawHorizontalLine(Bit_Map& bitMap, point_LL point1, point_LL point2,
                                         rgb color, unsigned width) const;
    void drawHorizontalLine(Bit_Map& bitMap, point_LL point1, point_LL point2,
                            rgb color) const;

    void drawCircle(Bit_Map& bitMap, point_LL center, rgb color, unsigned width) const;
    inline void drawPoint(Bit_Map& bitMap, point_LL point, rgb color) const
    { bitMap.drawPoint(point, color); }
};

class Log_Round_Pen_Drawer: public Drawer
{
public:
    void drawLine(Bit_Map& bitMap, point_LL point1, point_LL point2,
              rgb color, unsigned width) const override;

private:
    Round_Pen_Drawer _drawer;
    Logger _logger;
};

#endif // CANVAS_HPP_INCLUDED
