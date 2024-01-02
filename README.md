# ASP - Assignment
## (Students: 21047697 & 20225626)
## Fiber Scheduler Implementation

## Overview

This project aims to implement a fiber scheduler using cooperative multitasking with custom context management. Fibers, lightweight cooperative threads, are scheduled and executed in a non-preemptive manner. This README provides an overview of the code structure and highlights key features in the implementation that contributes to the functionality of the program.

## Task 1
### Main Implementation
---
### Data Structures

- **Context Objects**: Two `Context` objects, `c` and `c_main`, are declared for managing task states.
- **Task Counter**: An integer `tasks_done` is used to count the number of completed tasks.

### Functions

1. **`foo()`**: This function is a sample task that performs the following:
   - Prints a message.
   - Increments the task counter (`tasks_done`).
   - Swaps the context back to `c_main` using `swap_context`.

2. **`goo()`**: Another sample function similar to `foo()`.

3. **`main()` Function**:
   - **Stack Setup**: Allocates and initializes the stack for fibers, adjusting the stack pointer for alignment.
   - **Fiber Scheduling Loop**: Enters a loop to alternate between calling `foo` and `goo` based on the parity of `tasks_done`.
   - **Context Setting**: Sets the context for each function by configuring the instruction pointer (`rip`) and stack pointer (`rsp`).
   - **Context Swapping**: Swaps contexts using custom context management functions until `tasks_done` reaches 2.

### Building and Running

- Ensure that the appropriate build tools and dependencies are available for your platform.

### Note


## Task 2

## Overview

This README extends the description of the Fiber Scheduler implementation to include Task-2. Task-2 introduces a scheduler class (`scheduler`) and two example fiber functions (`func1` and `func2`) that demonstrate the functionality of the cooperative multitasking system.

## `scheduler` Class

The `scheduler` class manages the execution of fibers using a deque data structure for fiber storage. Key features of the `scheduler` class include:

- **Constructor**: The class constructor initializes the scheduler with optional initial data and creates a deque for storing fibers.

- **`spawn` Method**: This method allows the scheduler to spawn a new fiber by adding it to the deque.

- **`do_it` Method**: The `do_it` method performs the fiber scheduling. It retrieves the context of the current execution, checks if there are fibers in the deque, and if so, selects the first fiber for execution. The context is then set to that of the selected fiber, and after execution, the original context is restored.

- **`get_data` Method**: A getter method to retrieve the data associated with the current fiber.

- **`fiber_exit` Method**: Signals the exit of the current fiber by setting the context back to the original execution context.

## `fiber` Class

The `fiber` class represents a fiber, which includes a function pointer and associated data. Key features of the `fiber` class include:

- **Constructor**: Allocates a new stack for the fiber, adjusts the stack top for function execution, and initializes the context with the provided function pointer and adjusted stack top.

- **Destructor**: Cleans up the allocated stack memory.

- **`get_context` Method**: A getter method to retrieve the context of the fiber.

- **`get_data` Method**: A getter method to retrieve the data associated with the fiber.

## `fiber_api` Module

The `fiber_api` module provides API functions that interface with the scheduler:

- **`fiber_exit` Function**: Signals the exit of the current fiber, invoking the scheduler's `fiber_exit` method.

- **`get_data` Function**: Retrieves the data associated with the current fiber using the scheduler's `get_data` method.

- **`spawn` Function**: Spawns a new fiber by invoking the scheduler's `spawn` method.

- **`do_it` Function**: Performs fiber scheduling by invoking the scheduler's `do_it` method.

## Example Usage (`main.cpp`)

The `main.cpp` file showcases the usage of the fiber scheduler and the example fiber functions:

- Creates two fiber instances (`f1` and `f2`) with associated functions and data.

- Spawns the first fiber (`f1`) and then the second fiber (`f2`).

- Invokes the `do_it` function to perform fiber scheduling.

- The fiber functions (`func1` and `func2`) demonstrate interaction with the scheduler using API functions (`get_data` and `fiber_exit`).

## Building and Running

- Ensure that the appropriate build tools and dependencies are available for your platform.


## Note

- Task-2 introduces a basic scheduler and demonstrates the interaction between fibers and the scheduler using API functions.

