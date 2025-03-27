# C++ Module 01

## Description
This module focuses on memory allocation, pointers to members, references, and the switch statement, and helps reinforce fundamental C++98 concepts.

## Exercises

### ex00
- **Description:** Implementation of a `Zombie` class with a `name` attribute and an `announce()` function. Includes functions to create zombies dynamically (`newZombie`) or on the stack (`randomChump`).

### ex01
- **Description:** Creation of a horde of zombies using dynamic allocation. Implements `zombieHorde()` to generate `N` zombies with the same name in a single allocation.

### ex02
- **Description:** Demonstrates memory addresses and value storage using a string, a pointer (`stringPTR`), and a reference (`stringREF`).

### ex03
- **Description:** Implementation of `Weapon`, `HumanA`, and `HumanB` classes. `HumanA` always has a weapon, while `HumanB` may not. Both have an `attack()` function displaying the weapon type.

### ex04
- **Description:** Reads a file and creates a new file with all occurrences of `s1` replaced by `s2`. Usage of `std::string::replace` is forbidden.

### ex05
- **Description:** Implementation of `Harl`, a class with different logging levels (`DEBUG`, `INFO`, `WARNING`, `ERROR`). Uses pointers to member functions instead of `if-else` statements.

## Rules and Requirements
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

