# C++ Module 02

## Description
This repository is focused on ad-hoc polymorphism, operator overloading, and the Orthodox Canonical Form for classes. These exercises build upon previous modules and introduce more advanced object-oriented programming concepts in C++98.

## Exercises

### ex00
- **Description:** Implementation of a `Fixed` class in Orthodox Canonical Form with an integer value representing a fixed-point number. Includes getter and setter functions for raw bit values.

### ex01
- **Description:** Enhancement of the `Fixed` class with constructors for integer and floating-point inputs. Includes functions to convert the fixed-point value back to float and int, as well as an overload for the insertion (`<<`) operator.

### ex02
- **Description:** Implementation of operator overloading for comparison (`>`, `<`, `>=`, `<=`, `==`, `!=`), arithmetic (`+`, `-`, `*`, `/`), and increment/decrement (`++`, `--`). Also includes static member functions `min` and `max` to return the smallest or largest of two fixed-point numbers.

## Rules and Requirements
- All classes must follow the Orthodox Canonical Form (default constructor, copy constructor, copy assignment operator, and destructor).
- Compile with `c++` using the flags `-Wall -Wextra -Werror`.
- All code must be compatible with `-std=c++98`.
- External libraries and prohibited functions such as `printf()`, `alloc()`, and `free()` are not allowed.
- Memory leaks must be handled correctly when using `new`.
- STL containers cannot be used until Module 08.

## Compilation and Execution
Each exercise includes a `Makefile`. To compile and run the programs:
```sh
make && ./executable_name
```
To clean generated files:
```sh
make clean
```

## License
This project is part of the 42 curriculum and is intended for educational use.

