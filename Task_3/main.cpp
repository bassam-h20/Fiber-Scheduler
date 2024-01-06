#include <iostream>
#include "fiber_api.hpp"

//scheduler instance
scheduler y;

// Function for the first fiber
void func1()
{
    // Retrieve data from the current fiber
    auto dp = y.current_fiber()->get_data();

    // Display information about the first fiber before yielding
    std::cout << "fiber 1 before, " << *(int*)dp << std::endl;

    // Yield control to the scheduler to execute the next fiber
    y.yield();

    // Modify the data and display information about the first fiber after resuming
    *(int*)dp = *(int*)dp + 1;
    std::cout << "fiber 1 after, " << *(int*)dp <<std::endl;

    // Exit the first fiber
    y.fiber_exit();
}

// Function for the second fiber
void func2()
{
    // Retrieve data from the current fiber
    auto dp = y.current_fiber()->get_data();

    // Display information about the second fiber
    std::cout << "fiber 2, " << *(int*)dp << std::endl;

    // Exit the second fiber
    y.fiber_exit();
}

int main()
{
    // Initialize data for fibers
    int x = 10;
    int *dp = &x;

    // Create two fibers with their respective functions and data
    fiber f2(func2, dp);
    fiber f1(func1, dp);

    // Add the fibers to the scheduler
    y.spawn(&f1);
    y.spawn(&f2);

    // Execute fibers in the scheduler
    y.do_it();

    // Return from the main function
    return 0;
}
