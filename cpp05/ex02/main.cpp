#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat b1("John", 1);
        Bureaucrat b2("Alice", 150);

        ShrubberyCreationForm f1("home");
        RobotomyRequestForm f2("Bender");
        PresidentialPardonForm f3("Zaphod");

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << f3 << std::endl;

        b1.signForm(f1);
        b1.signForm(f2);
        b1.signForm(f3);

        b1.executeForm(f1);
        b1.executeForm(f2);
        b1.executeForm(f3);

        b2.executeForm(f1); // This should fail due to low grade

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
