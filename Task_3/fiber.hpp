// fiber.hpp
#pragma once
#include <iostream>
#include "context.hpp"

class fiber
{
public:
    // void* data
    fiber(void (*function)(), void *data)
    {
        stack_bottom = new char[4096];
        stack_top = stack_bottom + 4096;
        stack_top = reinterpret_cast<char *>((reinterpret_cast<uintptr_t>(stack_top)) & -16L);
        stack_top -= 128;
        data_ = data;
        context_.rip = reinterpret_cast<void *>(function);
        context_.rsp = stack_top;
    }

    ~fiber()
    {
        // fill later
        delete[] stack_bottom;
    }

    Context *get_context()
    {
        return &context_;
    }

    void *get_data()
    {
        return data_;
    }

private:
    // Context context_ = {0};
    Context context_;
    char *stack_bottom;
    char *stack_top;
    void *data_;
};
