#include "Test.h"
#include <iostream>
#include <string>
#include <vector>

Test::Test()
{
}

Test* Test::wsk = nullptr;

Test* Test::get_instance()
{
	if (!wsk)
		wsk = new Test();

	return wsk;

}

bool Test::Test1()
{
	Point* first = new Point(1, -3, 0, false);
	Point* second = new Point(3, -5, 1, false);
	float expected_result = 3;

	Neighbours tester;

	float result = tester.calculate_distance(first, second);

	if (result == expected_result)
		return true;

	return false;
}


bool Test::Test2()
{	
	Point zero(1, 1, 0, true);
	Point first(3, 4, -1, false);
	Point second (6, 7, 1, false);
	Point third(2, 2, 0, false);

	std::vector<Point> points;
	points.push_back(zero);
	points.push_back(first);
	points.push_back(second);
	points.push_back(third);
	
	Point* current_point = &zero;

	Neighbours tester(points);
	Point* result = tester.find_neighbour(current_point);
	Point* expected_result = &points.at(3);
	
	if (*result == *expected_result)
		return true;

	return false;
}

/*
bool Test::Test3()
{

	std::string cypher = "ABc";
	std::string expected_result = "DEf";

	Caesar test(cypher);

	int overlap = 3;

	First_Cylinder* first = new First_Cylinder(overlap, cypher);
	first->rotate();

	std::string result = first->get_text();

	if (result == expected_result)
		return true;

	return false;
}

*/

void Test::run()
{
	if (Test1())
		std::cout << "Test 1: Sukces! " << std::endl;
	else
		std::cout << "Test 1: Porazka " << std::endl;

	if (Test2())
		std::cout << "Test 2: Sukces! " << std::endl;
	else
		std::cout << "Test 2: Porazka " << std::endl;

	/*
	if (Test3())
		std::cout << "Test 3: Sukces! " << std::endl;
	else
		std::cout << "Test 3: Porazka " << std::endl;

	*/

}
