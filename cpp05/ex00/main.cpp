#include <iostream>
#include "Bureaucrat.hpp"


int main() {
    try {

		Bureaucrat a;
		std::cout << a << std::endl;

        Bureaucrat b("Alice", 149);
        std::cout << b << std::endl;

		Bureaucrat c("Maggy", 189);
        std::cout << c << std::endl;

        b.decrementGrade(); 
        std::cout << b << std::endl;

		b.decrementGrade();  
      	std::cout << b << std::endl;

        // Intento de crear un burócrata con grade inválido
        Bureaucrat b2("Bob", 151);  // Esto lanzará GradeTooLowException
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
