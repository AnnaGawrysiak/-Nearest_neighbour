#include "Neighbours.h"
#include <limits>
#include <iostream>

float Neighbours::caclulate_distance(Point first, Point second)
{
	float distance = sqrt((first.get_x() - second.get_x()) * (first.get_x() - second.get_x()) + (first.get_y() - second.get_y()) * (first.get_y() - second.get_y()) + (first.get_z() - second.get_z()) * (first.get_z() - second.get_z()));

	return distance;
}

Point Neighbours::find_neighbour(std::vector<Point> all_points, Point current_point)
{
	float the_smallest_distance = std::numeric_limits<float>::max();

	Point neighbour = current_point;

	for (unsigned int i = 0; i < all_points.size(); i++)
	{
		float distance = caclulate_distance(current_point, all_points.at(i));

		if (distance < the_smallest_distance)
		{
			the_smallest_distance = distance;
			neighbour = all_points.at(i);
		}

	}

	return neighbour;
	// find some intelligent method of searching for neighbours
}


void Neighbours::find_cycle(std::vector<Point> all_points) // gives you starting point for the shortest route
{
	static float the_shortest_route = std::numeric_limits<float>::max();

	static unsigned int cycle = 0;
	static Point best_starting_point = all_points.at(0);

	unsigned int i = cycle;

		/*
		// Check if "sprawdzana" exists in vector
		vector<int>::iterator it = find(myvector.begin() + 1, myvector.end(), sprawdzana);

		if (it != myvector.end())
		{
			//cout << "Element Found" << endl;
		*/
	Point current_peak = all_points.at(cycle); // starting point
	
	bool check_if_already_visited = false;

	std::vector<Point>::iterator it = find(all_points.begin() + 1, all_points.end(), check_if_already_visited);

	while(it != all_points.end()) // jest chociaz jeden punkt bez pola already_visited zaznaczonego jako true
	{
		current_peak.set_already_visited(true);
		Point neighbour = find_neighbour(all_points, current_peak);
		total_distance += caclulate_distance(current_peak, neighbour);
		current_peak = neighbour;
		i++;
		it = find(all_points.begin() + 1, all_points.end(), check_if_already_visited);
	}

	cycle++;

	if (total_distance < the_shortest_route)
	{
		the_shortest_route = total_distance;
		best_starting_point = all_points.at(cycle);
	}

	for (unsigned int i = 0; i < all_points.size(); i++)
	{
		all_points.at(i).set_already_visited(false);
	}


	cycle++;

	if (cycle = all_points.size())
		return;

	return find_cycle(all_points);
}

float Neighbours::get_total_distance()
{
	return total_distance;
}

Neighbours::Neighbours()
{
	total_distance = 0;
	best_starting_point = Point(0, 0, 0, false);
}

Neighbours::Neighbours(float total_distance_, Point best_starting_point_)
{
	total_distance = total_distance_;
	best_starting_point = best_starting_point_;
}

Point Neighbours::get_best_starting_point() const
{
	return best_starting_point;
}