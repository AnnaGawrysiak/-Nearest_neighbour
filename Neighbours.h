#pragma once
#include "Point.h"
#include <vector> 

class Neighbours
{
private:
	float total_distance;
	Point best_starting_point;
public:
	Neighbours();
	Neighbours(float total_distance_, Point best_starting_point_);
	Point find_neighbour(std::vector<Point> all_points, Point current_point);
	float caclulate_distance(Point first, Point second);
	void find_cycle(std::vector<Point> all_points);
	float get_total_distance();
	Point get_best_starting_point() const; 
};

