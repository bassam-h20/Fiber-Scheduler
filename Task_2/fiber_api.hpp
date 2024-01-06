// fiber_api.hpp
#include "scheduler.hpp"

scheduler s;

void fiber_exit()
{
    s.fiber_exit();
}

void *get_data()
{
    return s.get_data();
}

void spawn(fiber *f, void *data)
{
    // fiber* f = new fiber(f, data);
    s.spawn(f, data);
}

void do_it()
{
    s.do_it();
}