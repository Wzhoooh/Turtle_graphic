#ifndef CANVAS_HPP_INCLUDED
#define CANVAS_HPP_INCLUDED

class Canvas
{
public:
    Canvas(long long LenVertical, long long lenGorisontal); // all coordinates in pixels
    void printLine(long long x1, long long y1, long long x2, long long y2, char color, int width); // all coordinates in pixels
    long long getLenVertical();
    long long getlenGorisontal();
    ~Canvas();

private:
    char* _bitMap;
    long long _LenVertical;
    long long _lenGorisontal;
};

#endif // CANVAS_HPP_INCLUDED
