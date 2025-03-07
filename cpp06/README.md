
## **README.md**  


# CPP06 - Type Conversion in C++

## Overview
The **CPP06** module at **42 Barcelona** focuses on **type conversions** in C++, particularly between **scalar types** (`char`, `int`, `float`, `double`).  
The goal is to understand how to safely convert values while avoiding common issues such as **precision loss or invalid conversions**.

---

## **Exercises**
### **ex00: ScalarConverter**
- Implement a `ScalarConverter` class that converts a **string** into different scalar types (`char`, `int`, `float`, `double`).
- Correctly handle special values such as `nan`, `inf`, `-inf`.
- Ensure the output format follows the **subject**.

---

### **ex01: Serialization**
- Implement a **simple data serialization and deserialization** mechanism.
- Convert a `Data` structure into a `uintptr_t` and back without losing information.

---

### **ex02: Dynamic Casting**
- Implement **polymorphism and dynamic casting** using `dynamic_cast`.
- Create a base class and multiple derived classes.
- Generate random objects and identify them at runtime.

---

## **Compilation & Execution**
To compile and execute the exercises, run:

```sh
$ make
$ ./ex00 <value>
$ ./ex01
$ ./ex02
```
To clean generated files:  
```sh
$ make fclean
```

---

## **Key Concepts**
✅ Implicit and explicit type conversions between `char`, `int`, `float`, `double`.  
✅ Safe casting with `static_cast`, `reinterpret_cast`, `const_cast`, and `dynamic_cast`.  
✅ Handling special floating-point values like `NaN` and `Inf`.  
✅ Understanding memory representation and serialization.  
✅ Using **polymorphism** and **dynamic casting** in C++.  

 **Master type conversions and casting in C++ with `cpp06`!**  
