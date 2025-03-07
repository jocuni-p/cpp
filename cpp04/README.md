
# C++ Module 04 - Subtype Polymorphism, Abstract Classes, Interfaces

This repository contains my solutions for the exercises of the C++ Module 04, which focuses on **subtype polymorphism**, **abstract classes**, and **interfaces** in C++. The exercises are designed to deepen your understanding of object-oriented programming (OOP) concepts, particularly polymorphism and class design.

## Exercises Overview

### Exercise 00: Polymorphism
- **Description**: Implement a base class `Animal` and two derived classes `Dog` and `Cat`. Each class should have a `makeSound()` function that prints a specific sound. Demonstrate polymorphism by calling `makeSound()` through base class pointers.
- **Key Concepts**: Polymorphism, inheritance, virtual functions.

### Exercise 01: I don’t want to set the world on fire
- **Description**: Implement a `Brain` class and modify the `Dog` and `Cat` classes to include a `Brain` attribute. Ensure proper memory management and demonstrate deep copying.
- **Key Concepts**: Memory management, deep copying, destructors.

### Exercise 02: Abstract class
- **Description**: Modify the `Animal` class to make it abstract by adding a pure virtual function. Ensure that `Animal` objects cannot be instantiated directly.
- **Key Concepts**: Abstract classes, pure virtual functions.


## Compilation and Execution

To compile the code, use the following command in the terminal:

```bash
make
```

This will compile all the necessary files and generate the executable. To run the program, use:

```bash
./program_name
```

Replace `program_name` with the appropriate executable name for each exercise.

## Requirements

- The code should comply with the C++98 standard.
- Use the following flags for compilation: `-Wall -Wextra -Werror`.
- Avoid memory leaks and ensure proper resource management.
- Follow the Orthodox Canonical Form for class design (unless stated otherwise).

## Notes

- Each exercise builds upon the previous one, so make sure to complete them in order.
- Proper construction and destruction chaining must be demonstrated in the derived classes.
- The use of `using namespace <ns_name>` and `friend` keywords is forbidden unless explicitly allowed.
- The STL (Standard Template Library) is allowed only in Modules 08 and 09.

## Additional Information

For more details, refer to the cpp04_subject.pdf provided.
