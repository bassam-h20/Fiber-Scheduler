#pragma once

#include <iostream>
#include <deque>
#include "fiber.hpp"
#include "context.hpp"

// Forward declaration of the fiber class
class fiber;

// Class definition for the scheduler
class scheduler
{
public:
    // Constructor initializes an empty deque of fibers
    scheduler()
    {
        std::deque<fiber *> fibers_;
    }

    // Function to spawn a new fiber and add it to the deque
    void spawn(fiber *f)
    {
        fibers_.push_back(f);
    }

    // Main function to execute fibers in the scheduler
    void do_it()
    {
        // Save the current context
        get_context(&context_);

        // Check if there are fibers in the deque
        if (!fibers_.empty())
        {
            // Get the next fiber to execute
            this_fiber_ = fibers_.front();
            fibers_.pop_front();

            // Switch to the context of the selected fiber
            set_context(this_fiber_->get_context());
        }

        // Terminate the program with success status
        std::exit(EXIT_SUCCESS);

        // Restore the original context
        set_context(&context_);
    }

    // Function to retrieve data from the currently executing fiber
    void *get_data()
    {
        return this_fiber_->get_data();
    }

    // Function to exit the currently executing fiber
    void fiber_exit()
    {
        set_context(&context_);
    }

    // Function to get the currently executing fiber
    fiber *current_fiber()
    {
        return this_fiber_;
    }

    // Function to yield control to the next fiber in the deque
    void yield()
    {
        if (!fibers_.empty())
        {
            // Save the current context
            auto current_context = this_fiber_->get_context();

            // Add the current fiber back to the deque
            fibers_.push_back(this_fiber_);

            // Get the next fiber to execute
            this_fiber_ = fibers_.front();
            fibers_.pop_front();

            // Switch to the context of the next fiber
            swap_context(current_context, this_fiber_->get_context());
        }
    }

private:
    // Deque to store fibers
    std::deque<fiber *> fibers_;

    // Context for the scheduler
    Context context_;

    // Pointer to the currently executing fiber
    fiber *this_fiber_;
};
