#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL); // crea un objeto de clase Array
    int* mirror = new int[MAX_VAL]; // crea un array dinamico int standart, para comparar con Array
    srand(time(NULL)); // inicializa semilla del generador de aleatorios, para que sea distinta en cada ejecucion
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand(); // genera un aleatorio
        numbers[i] = value; // se guarda el mismo aleatorio en cada elemento del array
        mirror[i] = value;
    }
	
	std::cout << "\nCall to 'size()':" << numbers.size() << std::endl;
	std::cout << "numbers[1] = " << numbers[1] << std::endl;
	std::cout << "mirror[1] = " << mirror[1] << std::endl;

	// SCOPE
	/*Se crean copias de 'numbers' en 'tmp' y 'test' dentro de un scope {}.
	Cuando este scope finaliza, 'tmp' y 'test' se destruyen, lo que prueba
	si el constructor de copia y el destructor funcionan correctamente.
	Si hubiese fugas de memoria, esto puede ser un problema.*/
	{
        Array<int> tmp = numbers; // Se declara 'tmp' e inicializa con 'numbers' → Esto invoca el constructor de copia.
        Array<int> test(tmp); // llama al constructor de copia. Otra forma de hacer lo mismo que linea anterior.
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i]) // compara que el valor de cada elemento sea igual en ambos
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
	}
	std::cout << "'numbers' and 'mirror' have the same values in their elements" << std::endl;
	try
    {
        numbers[-2] = 0; // trata de asignar valor a un indice que no existe
    }
    catch(const std::exception& e)
    {
        std::cerr << "[-2] " << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0; // trata de asignar valor a un indice que no existe
    }
    catch(const std::exception& e)
    {
        std::cerr << "[750] " << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand(); // prueba si permite reasignar los valores correctamente
    }
    delete [] mirror;// Libera la memoria dinamica
	/*NO se libera 'numbers' por que es un objeto de la clase Array 
	y su memoria dinamica se gestiona con el destructor*/
    return 0;
}