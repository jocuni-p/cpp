#include <iostream>
#include <exception>

class Bureaucrat {
	private:
		const std::string 	_name;
		int 				_grade;

	public:
		Bureaucrat(); // No lo implementare, para que no se pueda instanciar sin parametros.
		Bureaucrat(const std::string name, int grade); // const parametrizado
		Bureaucrat(const Bureaucrat& obj); // const de copia
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& obj);

		const std::string& getName() const; 
		int getGrade() const;

		
		void incrementGrade(); // es un setter
		void decrementGrade(); // es un setter

// Clases de excepciones
    	class GradeTooHighException : public std::exception {
        	public:
            	virtual const char* what() const throw();
    	};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};
/* La declaro fuera de la clase*/ //PORQUE???
/*=======overload "<<" operator definition========*/
std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

