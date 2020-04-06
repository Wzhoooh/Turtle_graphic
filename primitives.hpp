#ifndef PRIMITIVES_HPP_INCLUDED
#define PRIMITIVES_HPP_INCLUDED

struct rgb
{
    rgb() = default;
    rgb(const rgb&) = default;
    rgb(rgb&&) = default;
    rgb& operator =(const rgb&) = default;
    rgb& operator =(rgb&&) = default;
    rgb(char red, char green, char blue): red(red), green(green), blue(blue){}

    char red;
    char green;
    char blue;
};

struct point_D
{
    point_D() = default;
    point_D(const point_D&) = default;
    point_D(point_D&&) = default;
    point_D& operator =(const point_D&) = default;
    point_D& operator =(point_D&&) = default;
    point_D(double x, double y): x(x), y(y){}

    double x;
    double y;
};

struct point_LL
{
    point_LL() = default;
    point_LL(const point_LL&) = default;
    point_LL(point_LL&&) = default;
    point_LL& operator =(const point_LL&) = default;
    point_LL& operator =(point_LL&&) = default;
    point_LL(double x, double y): x(x), y(y){}

    long long x;
    long long y;
};

#endif // PRIMITIVES_HPP_INCLUDED
