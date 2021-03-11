#include "Point.h"
#include <cmath>
#include <iostream>

Point::Point()
{
    x = 0;
    y = 0;
    z = 0;
    already_visited = false;
}

Point::Point(int x_, int y_, int z_, bool already_visited_)
{
    x = x_;
    y = y_;
    z = z_;
    already_visited = already_visited_;
}

Point::Point(const Point& P1)
{
    x = P1.x;
    y = P1.y;
    z = P1.z;
    already_visited = P1.already_visited;
}

Point& Point::operator=(const Point& P3)
{
    if (&P3 != this)
    {
        x = P3.x;
        y = P3.y;
        z = P3.z;
        already_visited = P3.already_visited;
    }

    return *this;
}

bool Point::operator== (const Point& rhs)
{
    return x == rhs.x && y == rhs.y && z == rhs.z;
}

void Point::set_x(int x_)
{
    x = x_;
}


int Point::get_x()  const
{
    return x;
}

void Point::set_y(int y_)
{
    y = y_;
}


int Point::get_y() const
{
    return y;
}

void Point::set_z(int z_)
{
    z = z_;
}


int Point::get_z() const
{
    return z;
}

void Point::set_already_visited(bool already_visited_)
{
    already_visited = already_visited_;
}


bool Point::get_already_visited() const
{
    return already_visited;
}

