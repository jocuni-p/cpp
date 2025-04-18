## 📄 `README_ES.md`

```markdown
# CPP Module 09 - STL y Algoritmos Avanzados

Este módulo se centra en el uso de la **STL (Standard Template Library)** y en la aplicación de algoritmos avanzados de ordenamiento, manipulación de datos y estructuras.

---

## 🎓 ¿Qué se aprende en este módulo?

- Uso práctico de contenedores estándar (`vector`, `deque`, `map`, etc.).
- Implementación de algoritmos eficientes respetando restricciones de C++98.
- Análisis y diseño de estructuras de datos.
- Tratamiento de entradas complejas (archivos, argumentos de consola).
- Manipulación de expresiones en notación postfija (RPN).
- Aplicación del algoritmo **Merge-Insertion Sort** usando la **secuencia de Jacobsthal**.
- Medición de rendimiento de algoritmos.

---

## 📦 Contenido del módulo

- `ex00` – Bitcoin Exchange  
- `ex01` – Reverse Polish Notation (RPN)  
- `ex02` – PmergeMe (Ordenamiento eficiente)

---

## 🔧 Requisitos

- Compilador: `c++`
- Estándar: `-std=c++98`
- Flags: `-Wall -Wextra -Werror`

Cada ejercicio cuenta con su propio `Makefile` que incluye: `all`, `clean`, `fclean`, `re`.

---

## 🪙 ex00: Bitcoin Exchange

### Descripción:
Este ejercicio procesa datos históricos del precio del bitcoin y los cruza con fechas introducidas por el usuario.

### Uso:
```bash
./btc input.txt
```

### Formato del archivo:
```
YYYY-MM-DD | valor
```

---

## ➕ ex01: Reverse Polish Notation

### Descripción:
Simula una calculadora que evalúa expresiones matemáticas en notación polaca inversa.

### Uso:
```bash
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

---

## 📊 ex02: PmergeMe

### Descripción:
Implementación del algoritmo Merge-Insertion Sort. Ordena eficientemente una gran secuencia de enteros positivos y mide el rendimiento con diferentes contenedores.

### Uso:
```bash
./PmergeMe 3 5 9 7 4
```

- Se requiere soportar al menos 3000 elementos.
- La ordenación debe realizarse tanto con `std::vector` como con `std::deque`.
- El orden de inserción sigue la secuencia de Jacobsthal.
- Mostrar el tiempo de ejecución de cada contenedor.

### Ejemplo de salida:
```
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::vector : 0.00031 us
Time to process a range of 5 elements with std::deque  : 0.00014 us
```

---

## 🧪 Pruebas rápidas

En macOS puedes generar una prueba con 3000 enteros aleatorios:

```bash
./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
```

---

## 🧠 Reglas y restricciones

- Sin `printf`, `malloc`, `free`, ni librerías externas.
- Sin fugas de memoria.
- Clases en **Canonical Orthodox Form**, incluso si no se instancian.
- Código modular, limpio y bien organizado.

---

## 📚 Recursos recomendados

- Knuth, *The Art of Computer Programming Vol. 3 - Sorting and Searching*, sección Merge-Insertion Sort.

---

## 🧠 Evaluación esperada

- Correcta implementación de estructuras STL.
- Algoritmos eficientes.
- Validación de errores y entradas.
- Rendimiento medido correctamente.
```

---

## 📄 `README_EN.md` (in English)

```markdown
# CPP Module 09 - STL and Advanced Algorithms

This module focuses on using the **Standard Template Library (STL)** and applying efficient data algorithms, fully written in C++98.

---

## 🎓 What You Will Learn

- Practical use of STL containers (`vector`, `deque`, `map`, etc.).
- Implementing efficient algorithms under C++98 constraints.
- Designing and using custom data structures.
- Handling complex input (files, CLI arguments).
- Parsing and evaluating expressions in Reverse Polish Notation (RPN).
- Applying the **Merge-Insertion Sort** algorithm using the **Jacobsthal sequence**.
- Measuring performance of container-based algorithms.

---

## 📦 Module Structure

- `ex00` – Bitcoin Exchange  
- `ex01` – Reverse Polish Notation  
- `ex02` – PmergeMe (Efficient Sorting)

---

## 🔧 Requirements

- Compiler: `c++`
- Standard: `-std=c++98`
- Flags: `-Wall -Wextra -Werror`

Each exercise includes its own `Makefile` with rules: `all`, `clean`, `fclean`, `re`.

---

## 🪙 ex00: Bitcoin Exchange

### Description:
Reads historical bitcoin prices and matches them with input values by date.

### Usage:
```bash
./btc input.txt
```

### Input format:
```
YYYY-MM-DD | value
```

---

## ➕ ex01: Reverse Polish Notation

### Description:
Simulates a calculator using Reverse Polish Notation.

### Usage:
```bash
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

---

## 📊 ex02: PmergeMe

### Description:
Implements Merge-Insertion Sort to sort a large sequence of positive integers efficiently, using both `std::vector` and `std::deque`.

### Usage:
```bash
./PmergeMe 3 5 9 7 4
```

- Must support at least 3000 integers.
- Use both `std::vector` and `std::deque`.
- Insertion order must follow the Jacobsthal sequence.
- Show processing time for both containers.

### Example output:
```
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::vector : 0.00031 us
Time to process a range of 5 elements with std::deque  : 0.00014 us
```

---

## 🧪 Quick stress test (macOS)

```bash
./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
```

---

## 🧠 Constraints

- No use of `printf`, `malloc`, `free`, or external libraries.
- No memory leaks.
- Classes must follow Canonical Orthodox Form.
- Clean, modular, and readable code.

---

## 📚 Recommended reading

- Knuth, *The Art of Computer Programming Vol. 3 – Sorting and Searching*, Merge-Insertion Sort.

---

## ✅ Evaluation Criteria

- Correct use of STL containers
- Efficient and readable algorithms
- Input validation and error handling
- Performance measurement
```

---
