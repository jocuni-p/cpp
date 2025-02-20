#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"


int main() {
    try {

		Bureaucrat b1; // Creara un Bureaucrat 'Default'
		std::cout << b1 << std::endl; // El operador '<<' actuara segun defina mi sobrecarga

        Bureaucrat b2("b2", 149);
        std::cout << b2 << std::endl;

		Form f1;
		std::cout << f1 << std::endl;

		Form f2("f2", 1, 10, 5);
		std::cout << f2 << std::endl;

		b1.signForm(f1);
		std::cout << f1 << std::endl;

		b2.signForm(f1);
		std::cout << f1 << std::endl;

//		Bureaucrat b3("b3", 151);
//		std::cout << b3 << std::endl;

		Form f3("f3", 0, 180, 125);
		std::cout << f3 << std::endl;

		Bureaucrat b4("b4", 1);
		std::cout << b4 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught! : " << e.what() << std::endl;
    }
    return 0;
}
