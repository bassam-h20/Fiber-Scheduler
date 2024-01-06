#pragma once

#include <iostream>
#include "context.hpp"
#include "scheduler.hpp"

// Fiber class definition
class fiber
{
public:
    // Constructor for the fiber
    fiber(void (*function)(), void *data2_ = nullptr)
    {
        // Allocate memory for the fiber's stack
        stack_bottom = new char[4096];
        stack_top = stack_bottom + 4096;
        stack_top = reinterpret_cast<char *>((reinterpret_cast<uintptr_t>(stack_top)) & -16L);
        stack_top -= 128;

        // Set the initial values for the fiber's context
        context_.rip = reinterpret_cast<void *>(function);
        context_.rsp = stack_top;

        // Set additional data for the fiber
        data_ = data2_;
    }

    // Destructor for the fiber
    ~fiber()
    {
        // Clean up the allocated stack memory
        delete[] stack_bottom;
    }

    // Function to get the context of the fiber
    Context *get_context()
    {
        return &context_;
    }

    // Function to get the additional data associated with the fiber
    void *get_data()
    {
        return data_;
    }

private:
    // Fiber context
    Context context_;

    // Pointers to the stack memory
    char *stack_bottom;
    char *stack_top;

    // Additional data associated with the fiber
    void *data_;
};
