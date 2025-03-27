# C++ Module 00

## Description
This module introduces basic concepts of the language, such as namespaces, classes, member functions, input/output streams, initialization lists, `static`, `const`, and other fundamental features of C++98.

## Exercises

### ex00
- **Description:** A program that converts input to uppercase and displays it on the screen. If no input is provided, it prints a "loud and unbearable feedback noise" message.
- **Usage example:**
  ```sh
  ./megaphone "Hello World"
  HELLO WORLD
  ```

### ex01
- **Description:** Implement a contact book with a maximum of 8 entries. Supports the commands `ADD`, `SEARCH`, and `EXIT`.
- **Usage example:**
  ```sh
  > ADD
  > SEARCH
  > EXIT
  ```

### ex02
- **Description:** Reconstruction of a lost implementation of the `Account` class based on a header file and an execution log.

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

