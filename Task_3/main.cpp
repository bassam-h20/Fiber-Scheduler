#include <iostream>
#include "fiber_api.hpp"
#include <cstdlib>

void func1()
{
    std::cout << "fiber 1 started" << std::endl;
    int *dp = (int *)get_data();
    std::cout << "fiber 1, " << *dp << std::endl;
    *dp = *dp + 1;
    fiber_exit();
}

void func2()
{
    std::cout << "fiber 2 started" << std::endl;
    int *dp = (int *)get_data();
    std::cout << "fiber 2, " << *dp << std::endl;

    if (*dp == 11)
        std::exit(EXIT_SUCCESS);
}

int main()
{
    std::cout << "entered main" << std::endl;
    int d = 10;

    fiber *f2 = new fiber(&func2, &d);
    fiber *f1 = new fiber(&func1, &d);
    spawn(f1, &d);
    std::cout << "after spawn func1" << std::endl;
    spawn(f2, &d);
    std::cout << "after spawn func2" << std::endl;

    do_it();
    std::cout << "after do_it()" << std::endl;

    return 0;
}
