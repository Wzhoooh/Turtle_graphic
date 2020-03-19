#ifndef CANVAS_HPP_INCLUDED
#define CANVAS_HPP_INCLUDED

class Canvas
{
public:
    Canvas(long long LenVertical, long long lenGorisontal);
    void printLine(long long x1, long long y1, long long x2, long long y2);
    ~Canvas();

private:
    char* bitMap;
};

#endif // CANVAS_HPP_INCLUDED
