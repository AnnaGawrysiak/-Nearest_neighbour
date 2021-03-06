#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Point.h"
#include "Neighbours.h"
#include "Test.h"

std::vector<Point> parser(std::string filename);

int main()
{
    Test* testowa =Test::get_instance();
    testowa->run(); 

    std::string filename;
    std::cout << "Type in name of a file which contains coordinates of your points: ";
    std::cin >> filename;

    std::vector <Point> mypoints = parser(filename);

    Neighbours coordinates(mypoints);

    coordinates.find_cycle();

    std::cout << "The shortest possible route length is: " << coordinates.get_the_shortest_route() << std::endl;

    std::cout << "The best starting point coordinates are: x: " << coordinates.get_best_starting_point().get_x() << " y: "<< coordinates.get_best_starting_point().get_y() << "z: " << coordinates.get_best_starting_point().get_z() << std::endl;

    return 0;
}

std::vector<Point> parser(std::string filename)
{
    std::ifstream file;
    file.open(filename);

    if (!file.is_open())
        std::cout << "Error! File could not be opened" << std::endl;

    int x = 0;
    int y = 0;
    int z = 0;

    std::string line;
    std::string myString;

    std::vector<Point> points;

    while (getline(file, line))
    {
        std::stringstream ss(line);
        getline(ss, myString, ',');
        x = std::stoi(myString);
        getline(ss, myString, ',');
        y = std::stoi(myString);
        getline(ss, myString);
        z = std::stoi(myString);

        //std::cout << x << " " << y << " " << z << " " << std::endl;
        Point p1(x, y, z, false);

        points.push_back(p1);
    }

    file.close();

return points;
}