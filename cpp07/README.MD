# C++ Module 07 - Templates

## 📌 Overview
This repository focuses on **templates** in C++. The exercises cover function templates and class templates, demonstrating how to create reusable and generic code.

Each exercise is structured with a `Makefile`, a main test file, and the necessary headers and implementation files.

## 📂 Exercises
### **ex00**
- **Description:**
  - Implements three function templates:
    - `swap`: Swaps two given arguments.
    - `min`: Returns the smallest of two arguments.
    - `max`: Returns the largest of two arguments.
  - These functions work with any type that supports comparison operators.

### **ex01**
- **Description:**
  - Implements a function template `iter` that:
    - Takes a pointer to an array, its size, and a function.
    - Applies the function to each element of the array.
  - Works with any data type and callable function.

### **ex02**
- **Files:** added a new type of file `Array.tpp` to implement the class template members.
- **Description:**
  - Implements a class template `Array<T>` with:
    - Default constructor (empty array).
    - Constructor with an `unsigned int n` parameter (creates an array of size `n`).
    - Copy constructor and assignment operator (ensuring deep copy).
    - Subscript operator `[]` with bounds checking (throws `std::exception` if out of range).
    - `size()` function to get the number of elements.
  - Uses `new[]` for memory allocation and prevents memory leaks.

## 🛠 Compilation & Execution
Each exercise includes a `Makefile` for easy compilation. To compile and run an exercise, use:
```sh
make
./program_name
```
Replace `program_name` with the corresponding executable file generated.

To clean up object files and executables:
```sh
make clean
```

