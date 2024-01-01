# ASP - Assignment
## (Students: 21047697 & 20225626)
## Fiber Scheduler Implementation

## Overview

This project aims to implement a fiber scheduler using cooperative multitasking with custom context management. Fibers, lightweight cooperative threads, are scheduled and executed in a non-preemptive manner. This README provides an overview of the code structure and highlights key features in the `main.cpp` file that contribute to the functionality of the program.

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

