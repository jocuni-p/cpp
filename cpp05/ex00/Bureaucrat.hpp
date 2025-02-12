#include <iostream>
#include <exception>

class Bureaucrat {
	private:
		const std::string 	_name;
		int 				_grade;

	public:
		Bureaucrat(); // Constructor por default. Lo exije la forma canonica
		Bureaucrat(const std::string name, int grade); // const parametrizado
		Bureaucrat(const Bureaucrat& obj); // const de copia
		virtual ~Bureaucrat(); 
		// virtual me asegura una correcta destruccion en caso de posibles herencias
		Bureaucrat& operator=(const Bureaucrat& obj);

		const std::string& getName() const; 
		int getGrade() const;

		
		void incrementGrade();
		void decrementGrade();

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

//La declaro fuera de la clase Bureaucrat PORQUE RETORNA UN OBJETO DE LA CLASE ostream
/*======= "<<" insertion operator overload========*/
std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

