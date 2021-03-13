#pragma once
#include "Point.h"
#include <vector> 

class Neighbours
{
private:
	float the_shortest_route;
	Point best_starting_point;
public:
	Neighbours();
	Neighbours(float the_shortest_route_, Point best_starting_point_);
	Point* find_neighbour(std::vector<Point> all_points, Point* current_point);
	float caclulate_distance(Point* first, Point* second);
	void find_cycle(std::vector<Point> all_points);
	float get_the_shortest_route();
	Point get_best_starting_point() const; 
};

