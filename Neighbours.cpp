#include "Neighbours.h"
#include <limits>
#include <iostream>

Neighbours::Neighbours()
{
}

Neighbours::Neighbours(float the_shortest_route_, Point best_starting_point_)
{
	the_shortest_route = the_shortest_route_;
	best_starting_point = best_starting_point_;
}

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
		if (all_points.at(i).get_already_visited() == false)
		{
			float distance = caclulate_distance(current_point, all_points.at(i));

			if (distance < the_smallest_distance)
			{
				the_smallest_distance = distance;
				neighbour = all_points.at(i);
			}
		}

	}

	return neighbour;

}


void Neighbours::find_cycle(std::vector<Point> all_points) // gives you starting point for the shortest route
{
	static float the_shortest_route = std::numeric_limits<float>::max();

	float total_distance = 0;

	for (unsigned int cycle = 0; cycle < all_points.size(); cycle++)
	{
		Point current_peak = all_points.at(cycle); 

		bool check_if_already_visited = false;

		// check if there are any nonvisited points left
		auto it = find_if(all_points.begin(), all_points.end(), [&check_if_already_visited](const Point& obj) {return obj.get_already_visited() == check_if_already_visited; });

		while (it != all_points.end())
		{
			current_peak.set_already_visited(true);
			Point neighbour = find_neighbour(all_points, current_peak); 
			total_distance += caclulate_distance(current_peak, neighbour);
			current_peak = neighbour;
			it = find_if(all_points.begin(), all_points.end(), [&check_if_already_visited](const Point& obj) {return obj.get_already_visited() == check_if_already_visited; });
		}

		if (total_distance < the_shortest_route)
		{
			the_shortest_route = total_distance;
			best_starting_point = all_points.at(cycle);
		}

		for (unsigned int i = 0; i < all_points.size(); i++)
		{
			all_points.at(i).set_already_visited(false);
		}
	}
	
}

float Neighbours::get_the_shortest_route()
{
	return the_shortest_route;
}


Point Neighbours::get_best_starting_point() const
{
	return best_starting_point;
}