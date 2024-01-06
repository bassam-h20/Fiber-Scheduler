#include <iostream>
#include "fiber_api.hpp"
#include "simpletest.h"

char const* groups[] = {
    "FiberScheduler",
};

//increments dp
void func1()
{
    int *dp = (int*)get_data();
    *dp = *dp + 1;
    fiber_exit();
}


//assigns string to fiber
void func2_1()
{
    std::cout << "Fiber 1 before, " << std::endl;
    yield();
    std::cout << "Fiber 1 after, " << std::endl;
    fiber_exit();
}
void func2_2()
{
    std::cout << "Fiber 2 before, " << std::endl;
    yield();
    std::cout << "Fiber 2 after, " << std::endl;
    fiber_exit();
}

//change value of dp
void func3()
{
    int*dp = (int*)get_data();
    *dp = 20;
    fiber_exit();
}

DEFINE_TEST_G(IncrementValueTest, FiberScheduler)
{
    int d = 12;
    int* dp = &d;
    spawn(func1, dp);
    TEST_MESSAGE(*dp != 13, "Fiber data is incorrect");
}

DEFINE_TEST_G(StringTest, FiberScheduler)
{
    spawn(func2_1);
    spawn(func2_2);
    do_it();
}

int main()
{
    bool pass = true;

    for (auto group : groups)
    {
        pass &= TestFixture::ExecuteTestGroup(group, TestFixture::Verbose);
    }
    return pass ? 0 : 1;
}

