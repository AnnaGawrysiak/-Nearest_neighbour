#pragma once
#include "Point.h"
#include <vector> 

class Neighbours
{
private:
	float the_shortest_route;
	Point best_starting_point;
	std::vector<Point> list_of_points;
public:
	Neighbours();
	Neighbours(std::vector<Point>& list_of_points);
	Point* find_neighbour(Point* current_point);
	float caclulate_distance(Point* first, Point* second);
	void find_cycle();
	float get_the_shortest_route();
	Point get_best_starting_point() const; 
	void set_list_of_points(std::vector<Point>& all_points);
};

