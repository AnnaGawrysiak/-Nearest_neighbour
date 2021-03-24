#include "Neighbours.h"
#include <limits>
#include <iostream>

Neighbours::Neighbours()
{
	the_shortest_route = std::numeric_limits<float>::max();
}

Neighbours::Neighbours(std::vector<Point>& list_of_points_)
{
	list_of_points = list_of_points_;
	the_shortest_route = std::numeric_limits<float>::max();
}

float Neighbours::calculate_distance(Point* first, Point* second)
{
	float distance = sqrt((first->get_x() - second->get_x()) * (first->get_x() - second->get_x()) + (first->get_y() - second->get_y()) * (first->get_y() - second->get_y()) + (first->get_z() - second->get_z()) * (first->get_z() - second->get_z()));
	
	return distance;
}

Point* Neighbours::find_neighbour(Point* current_point)
{
	float the_smallest_distance = std::numeric_limits<float>::max();

	Point* neighbour = current_point;

	for (unsigned int i = 0; i < list_of_points.size(); i++)
	{
		if (list_of_points.at(i).get_already_visited() == false)
		{
			float distance = calculate_distance(current_point, &list_of_points.at(i));

			if (distance < the_smallest_distance)
			{
				the_smallest_distance = distance;
				neighbour = &list_of_points.at(i);
			}
		}

	}

	return neighbour;
}


void Neighbours::find_cycle() // gives you starting point for the shortest route
{
	static unsigned int cycle = 0;

	Point* point = &list_of_points.at(cycle);

	float distance = 0;

	for (unsigned int i = 0; i < list_of_points.size(); i++)
	{
		//std::cout << "point" << &point << std::endl;
		point->set_already_visited(true);
		Point* current_peak = find_neighbour(point);
		//std::cout << "current peak" << &current_peak << std::endl;
		distance += calculate_distance(current_peak, point);
		//std::cout << "distance: " << distance << std::endl;
		point = current_peak;
		//std::cout << "point end" << &point << std::endl;
	}
	std::cout <<std::endl;

	if (distance < the_shortest_route)
	{
		the_shortest_route = distance;
		best_starting_point = list_of_points.at(cycle);
	}

	//std::cout << " the_shortest_route after: " << the_shortest_route << std::endl;

	cycle++;

	if (cycle >= list_of_points.size())
		return;

	return find_cycle();

	/*
	cycle++;

	if (cycle >= list_of_points.size())
		return;

	return find_cycle();

	/*
	static unsigned int cycle = 0;

	Point* peak = &list_of_points.at(cycle);

	float distance = 0;

	for (unsigned int i = 0; i < list_of_points.size(); i++)
	{
		peak->set_already_visited(true);
		Point* current_peak = find_neighbour(peak);
		distance += caclulate_distance(current_peak, peak);
		peak = current_peak;
	}

	if (distance < the_shortest_route)
	{
		the_shortest_route = distance;
		best_starting_point = list_of_points.at(cycle);
	}

	cycle++;

	if (cycle >= list_of_points.size())
		return;
	
	return find_cycle();
	*/
}

	
float Neighbours::get_the_shortest_route()
{
	return the_shortest_route;
}


Point Neighbours::get_best_starting_point() const
{
	return best_starting_point;
}

void Neighbours::set_list_of_points(std::vector<Point>& all_points)
{
	list_of_points = all_points;
}