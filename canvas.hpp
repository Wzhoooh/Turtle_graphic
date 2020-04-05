#ifndef CANVAS_HPP_INCLUDED
#define CANVAS_HPP_INCLUDED

#include <memory>
#include "primitives.hpp"

class Drawer;
class Bit_Map;

class Canvas // all coordinates in pixels
{
public:
    Canvas(std::shared_ptr<Drawer> drawer);
    void draw(point_LL point1, point_LL point2, rgb color, unsigned width); // all coordinates in pixels
    point_LL getSizeBitMap() const;
    void setSizeBitMap(point_LL sizeBitMap);
    void setCanvasColor(rgb canvasColor);

    ~Canvas();

private:
    std::shared_ptr<Drawer> _drawer;
    std::shared_ptr<Bit_Map> _bitMap;
    point_LL _sizeBitMap;
    rgb _canvasColor;
};

class Bit_Map
{
public:
    Bit_Map(point_LL size);
    ~Bit_Map();
    void printPoint(point_LL point);

private:
    char* _data;
    point_LL _size;
};

class Drawer
{
public:
    virtual void draw(std::shared_ptr<Bit_Map> bitMap, point_LL point1, point_LL point2,
                      rgb color, unsigned width) const = 0;
};

class Loger: public Drawer
{
public:
    void draw(std::shared_ptr<Bit_Map> bitMap, point_LL point1, point_LL point2,
              rgb color, unsigned width) const override;
};

#endif // CANVAS_HPP_INCLUDED
