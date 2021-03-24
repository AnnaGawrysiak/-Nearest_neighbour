#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Point.h"
#include "Neighbours.h"
#include "Test.h"

int main()
{
    Test* testowa =Test::get_instance();
    testowa->run(); 
  
    std::vector<Point> points;

    /*
     Point p1(1, 12, 0, false);
    points.push_back(p1);

    Point p2(2, 5, 0, false);
    points.push_back(p2);

    Point p3(5, 3, 1, false);
    points.push_back(p3);

    Point p4(3, 2, 1, false);
   points.push_back(p4);

    Point p5(3, 6, 2, false);
    points.push_back(p5);

    Point p6(4, 9, 3, false);
    points.push_back(p6);
    */

    Point p1(0, 2, 0, false);
    points.push_back(p1);

    Point p2(0, 3, 0, false);
    points.push_back(p2);

    Point p3(0, 7, 0, false);
    points.push_back(p3);

    Point p4(0, 0, 0, false);
    points.push_back(p4);

    Neighbours coordinates(points);

    coordinates.find_cycle();

    std::cout << "The shortest possible route length is: " << coordinates.get_the_shortest_route() << std::endl;

    std::cout << "The best starting point coordinates are: x: " << coordinates.get_best_starting_point().get_x() << " y: "<< coordinates.get_best_starting_point().get_y() << "z: " << coordinates.get_best_starting_point().get_z() << std::endl;

    return 0;
}
