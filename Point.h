#pragma once
class Point
{
private:
    int x, y, z;     // Coordinates of a point 
    bool already_visited;

public:
    Point();

    Point(int x_, int y_, int z_, bool already_visited_);
 
    Point(const Point& P1);

    Point& operator=(const Point& P3);

    bool operator== (const Point& rhs);

    void set_x(int x_);

    int get_x() const;

    void set_y(int y_);

    int get_y() const;
   
    void set_z(int z__);

    int get_z() const;

    bool get_already_visited() const;

    void set_already_visited(bool already_visited_);

};