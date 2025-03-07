# C++ Module 03 - Inheritance

This repository contains my solutions for the exercises of the C++ Module 03, which focuses on **Inheritance** in C++. The exercises are designed to introduce and practice the concepts of object-oriented programming (OOP) in C++, specifically inheritance, class design, and polymorphism.

## Exercises Overview

### Exercise 00: Aaaaand... OPEN!
- **Description**: Implement a class named `ClapTrap` with specific attributes and member functions. The class should simulate a simple robot that can attack, take damage, and repair itself.
- **Key Concepts**: Class implementation, constructors, destructors, member functions.

### Exercise 01: Serena, my love!
- **Description**: Create a derived class `ScavTrap` that inherits from `ClapTrap`. The `ScavTrap` class should have its own unique attributes and a special function `guardGate()`.
- **Key Concepts**: Inheritance, constructor/destructor chaining, overriding member functions.

### Exercise 02: Repetitive work
- **Description**: Implement another derived class `FragTrap` that inherits from `ClapTrap`. The `FragTrap` class should have different attributes and a special function `highFivesGuys()`.
- **Key Concepts**: Inheritance, constructor/destructor chaining, overriding member functions.

### Exercise 03: Now it’s weird!
- **Description**: Create a `DiamondTrap` class that inherits from both `FragTrap` and `ScavTrap`. The `DiamondTrap` class should have its own unique attributes and a special function `whoAmI()`.
- **Key Concepts**: Multiple inheritance, virtual inheritance, overriding member functions.

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

For more details, refer to the cpp03_subject.pdf provided.
