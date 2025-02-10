#include <iostream>
#include "Bureaucrat.hpp"


int main() {
    try {
        Bureaucrat b("Alice", 42);
        std::cout << b << std::endl;

        b.incrementGrade();  // Debería mejorar el grado (42 -> 41)
        std::cout << b << std::endl;

        // Intento de crear un burócrata con grade inválido
        Bureaucrat b2("Bob", 151);  // Esto lanzará GradeTooLowException
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
