# C++ Module 05 - Repetition and Exceptions

This repository focuses on **repetition** and **exceptions** in C++. The exercises are designed to deepen your understanding of error handling, class design, and polymorphism.

## Exercises Overview

### ex00
- **Description**: Implement a `Bureaucrat` class that represents a bureaucrat with a name and a grade. The grade must be within a valid range (1 to 150), and any attempt to set an invalid grade should throw an exception.
- **Key Concepts**: Exception handling, class design, operator overloading.

### ex01
- **Description**: Implement a `Form` class that represents a form with a name, a signing status, and required grades for signing and execution. The form can be signed by a `Bureaucrat` if their grade is high enough.
- **Key Concepts**: Exception handling, class interaction, method overloading.

### ex02
- **Description**: Extend the `Form` class to create specific forms (`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`) that perform different actions when executed. Ensure proper exception handling and class inheritance.
- **Key Concepts**: Inheritance, polymorphism, abstract classes, exception handling.

### ex03
- **Description**: Implement an `Intern` class that can create different types of forms based on a given name and target. The `Intern` should handle unknown form types gracefully.
- **Key Concepts**: Factory pattern, exception handling, class design.

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
- Proper exception handling must be demonstrated in all classes.
- The use of `using namespace <ns_name>` and `friend` keywords is forbidden unless explicitly allowed.
- The STL (Standard Template Library) is allowed only in cpp08 and cpp09.
