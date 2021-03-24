#pragma once
#include "Neighbours.h"
#include "Point.h"

class Test
{
private:
    Test();
    static Test* wsk;

public:
    void operator = (const Test&) = delete;
    Test(const Test&) = delete;

    static Test* get_instance();

    bool Test1();

    bool Test2();

    bool Test3();

    void run();

};