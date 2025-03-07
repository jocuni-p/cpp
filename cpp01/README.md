# C++ Module 01

## Description
This repository contains my solutions for C++ Module 01 exercises, focusing on memory allocation, pointers to members, references, and the switch statement. These exercises help reinforce fundamental C++98 concepts.

## Exercises

### Exercise 00: BraiiiiiiinnnzzzZ
- **Directory:** `ex00/`
- **Files:** `Makefile`, `main.cpp`, `Zombie.{h, hpp}`, `Zombie.cpp`, `newZombie.cpp`, `randomChump.cpp`
- **Description:** Implementation of a `Zombie` class with a `name` attribute and an `announce()` function. Includes functions to create zombies dynamically (`newZombie`) or on the stack (`randomChump`).

### Exercise 01: Moar brainz!
- **Directory:** `ex01/`
- **Files:** `Makefile`, `main.cpp`, `Zombie.{h, hpp}`, `Zombie.cpp`, `zombieHorde.cpp`
- **Description:** Creation of a horde of zombies using dynamic allocation. Implements `zombieHorde()` to generate `N` zombies with the same name in a single allocation.

### Exercise 02: HI THIS IS BRAIN
- **Directory:** `ex02/`
- **Files:** `Makefile`, `main.cpp`
- **Description:** Demonstrates memory addresses and value storage using a string, a pointer (`stringPTR`), and a reference (`stringREF`).

### Exercise 03: Unnecessary violence
- **Directory:** `ex03/`
- **Files:** `Makefile`, `main.cpp`, `Weapon.{h, hpp}`, `Weapon.cpp`, `HumanA.{h, hpp}`, `HumanA.cpp`, `HumanB.{h, hpp}`, `HumanB.cpp`
- **Description:** Implementation of `Weapon`, `HumanA`, and `HumanB` classes. `HumanA` always has a weapon, while `HumanB` may not. Both have an `attack()` function displaying the weapon type.

### Exercise 04: Sed is for losers
- **Directory:** `ex04/`
- **Files:** `Makefile`, `main.cpp`, `*.cpp`, `*.h`, `*.hpp`
- **Description:** Reads a file and creates a new file with all occurrences of `s1` replaced by `s2`. Usage of `std::string::replace` is forbidden.

### Exercise 05: Harl 2.0
- **Directory:** `ex05/`
- **Files:** `Makefile`, `main.cpp`, `Harl.{h, hpp}`, `Harl.cpp`
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

