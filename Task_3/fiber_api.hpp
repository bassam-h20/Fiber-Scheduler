#include "scheduler.hpp"

// Global scheduler instance
scheduler s;

// Function to exit the current fiber
void fiber_exit()
{
    s.fiber_exit();
}

// Function to get data from the currently executing fiber
void *get_data()
{
    return s.get_data();
}

// Function to spawn a new fiber
void spawn(fiber *f)
{
    s.spawn(f);
}

// Function to execute fibers in the scheduler
void do_it()
{
    s.do_it();
}

// Function to yield control to the next fiber in the deque
void yield()
{
    s.yield();
}
