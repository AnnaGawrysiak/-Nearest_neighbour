#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Point.h"
#include "Neighbours.h"

bool operator==(const Point& P3, const Point& P2)
{
    if (P2.get_x() == P3.get_x() && P2.get_y() == P3.get_y() && P2.get_z() == P3.get_z() && P2.get_already_visited() == P3.get_already_visited())
        return true;

    else
        return false;
}


int main()
{
    /*

    std::fstream file;
    file.open("data.txt", std::fstream::in);

    if (!file.is_open())
    {	// jeœli nie ma podanego pliku
        std::cout << " File error. " << std::endl;
        return 1; // zakoñczenie pracy programu
    }
    
    const int rows = 6;

    const int columns = 2;

    float data[rows][columns];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            file >> data[i][j];
          
            if (file.eof()) break;
        }

        if (file.eof()) break;
    }

        file.close();
        */
    std::vector<Point> list_of_points;
    Point p1(1, 12, 0, false);
    list_of_points.push_back(p1);

    Point p2(2, 5, 0, false);
    list_of_points.push_back(p2);

    Point p3(5, 3, 1, false);
    list_of_points.push_back(p3);

    Point p4(3, 2, 1, false);
    list_of_points.push_back(p4);

    Point p5(3, 6, 2, false);
    list_of_points.push_back(p5);

    Point p6(4, 9, 3, false);
    list_of_points.push_back(p6);

    Neighbours Hamiltonian_cycle;

    Hamiltonian_cycle.find_cycle(list_of_points);

    std::cout << "The shortest possible route is: " << Hamiltonian_cycle.get_total_distance() << std::endl;

    std::cout << "The best point to start is: " << Hamiltonian_cycle.get_best_starting_point().get_x() << std::endl;

    return 0;
}
