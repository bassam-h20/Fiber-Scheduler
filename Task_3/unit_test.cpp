#include "fiber_api.hpp"
#include "simpletest.h"

char const* groups[] = {
    "FiberTest1",
};

void func1()
{
    std::cout << "\nfiber 1 started" << std::endl;
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

DEFINE_TEST_G(Fibertesting, FiberTest1)
{
    // Set up data for the fiber
    int d = 10;

    // Create two fiber instances with associated functions and data
    fiber* f2 = new fiber(&func2, &d);
    
    fiber* f1 = new fiber(&func1, &d);

    spawn(f1, &d);
    TEST_MESSAGE( &d ,"Data pointers match after spawn func1");

    spawn(f2, &d);
    TEST_MESSAGE(d == 11, "Data pointers match after spawn func1");
    
    do_it();

    //TEST_EQ(d, 11);
    TEST_MESSAGE(d == 11, "Data pointers match after spawn func1");

}

DEFINE_TEST_G(Func1Test, Func1)
{
    int d = 10;
    func1();
    TEST_EQ(d, 11);
}

DEFINE_TEST_G(Func2Test, Func2)
{
    int d = 10;
    func2();
    TEST_EQ(d, 10);
}



int main()
{   

    
    if (!TestFixture::Verbose)
    {
        throw std::runtime_error ("Running tests...\n");
    }

    // Call Func2Test
    //func1();
    //func2();
    
    bool pass = true;
    for (auto group : groups)
    {
        pass &= TestFixture::ExecuteTestGroup(group, TestFixture::Verbose);
    }

    return pass ? 0 : 1;
}

