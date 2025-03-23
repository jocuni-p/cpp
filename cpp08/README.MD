# CPP Module 08 - Templated Containers, Iterators, Algorithms

## Description
This C++ module focuses on the use of **containers**, **iterators**, and **algorithms** from the STL (*Standard Template Library*). Through the exercises, you will learn to manipulate data structures efficiently using C++ tools.

## General Rules
- The code must compile with `c++` and the following flags:
  ```sh
  -Wall -Wextra -Werror -std=c++98
  ```
- The use of the **STL** is allowed in this module.
- Forbidden functions: `printf()`, `alloc()`, `free()`.
- The class structure must follow the **Orthodox Canonical Form**.

---

## Exercises
### **ex00 - Easy Find**
**Objective:** Implement a template function `easyfind` that searches for a number within an integer container.

**Key Points:**
- Use of iterators.
- Exception handling if the number is not found.

### **ex01 - Span**
**Objective:** Implement a `Span` class that stores a fixed number of integers and finds the shortest and longest span between them.

**Key Points:**
- Use of `std::vector` to store values.
- Implementation of algorithms to find minimum and maximum differences.
- Allow addition of multiple elements using iterators.

### **ex02 - MutantStack**
**Objective:** Create a `MutantStack` class based on `std::stack` that allows iteration over its elements.

**Key Points:**
- Inheriting from `std::stack`.
- Using `container_type` to access iterators of the underlying container.
- Defining `iterator` and `const_iterator` to iterate over the stack.

**Example Usage:**
```cpp
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
```

---

## How to Compile and Run
1. Navigate to the corresponding exercise directory.
2. Run `make` to compile the program.
3. Execute the generated binary:
   ```sh
   ./ex0X  # Replace X with the exercise number
   ```
4. To clean compiled files:
   ```sh
   make clean
   ```

---

## Conclusion
This module is an excellent introduction to using the STL in C++. By completing it, you should feel more comfortable working with **containers**, **iterators**, and **standard algorithms**, which will facilitate the development of efficient and well-structured C++ software.

