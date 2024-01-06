
// scheduler.hpp
#pragma once
#include <iostream>
#include <deque>
#include "fiber.hpp"
#include "context.hpp"

class scheduler
{
public:
    scheduler(void *data = nullptr)
    {
        Context context_;
        data_ = data;
        std::deque<fiber *> fibers_;
    }

    void spawn(fiber *f, void *data)
    {
        fibers_.push_back(f);
    }

    void do_it()
    {
        get_context(&context_);
        if (!fibers_.empty())
        {
            this_fiber = fibers_.front();
            fibers_.pop_front();
            set_context(this_fiber->get_context());
        }

        // initial line
        //  this_fiber = nullptr;
        set_context(&context_);

        this_fiber = nullptr;
    }

    void *get_data()
    {
        return this_fiber->get_data();
    }

    void fiber_exit()
    {
        set_context(&context_);
    }

private:
    std::deque<fiber *> fibers_;
    Context context_;
    fiber *this_fiber = nullptr;
    void *data_ = nullptr;
};
