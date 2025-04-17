#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "PmergeMe.hpp"

/**
 * En binaryInsert uso 'std::lower_bound()' que por debajo actua como binary_search,
 *  dividiendo el rango en mitades hasta encontrar la posicion correcta
 * y luego coloco el valor con 'insert'. Sin embargo, la insercion no se 
 * realiza en todo el rango sino en sub-rangos acotados, usando la informacion
 *  de las parejas iniciales, para reducir el num de comparaciones.
 */
template <typename T>
typename T::iterator PmergeMe::binaryInsert(T& container,
                                          typename T::value_type value,
                                          typename T::iterator begin,
                                          typename T::iterator end) {
											
#ifdef PMERGEME_DEBUG
    std::cout << "  Insertando " << value << " en rango [";
    for (typename T::iterator it = begin; it != end; ++it)
        std::cout << *it << " ";
    std::cout << "]\n";
#endif

	typename T::iterator pos = std::lower_bound(begin, end, value);
    return container.insert(pos, value);
}


template <typename T>
void PmergeMe::mergeInsertSort(T& container) {
    if (container.size() <= 1)
        return;

    typedef typename T::value_type Value;
    T larger;
    T pendings;

#ifdef PMERGEME_DEBUG
    std::cout << "Dividiendo en pares...\n";
#endif

    // Paso 1: Formar pares y separar mayores/menores
    for (size_t i = 0; i < container.size(); i += 2) {
        if (i + 1 < container.size()) {
            if (container[i] < container[i + 1]) {
                larger.push_back(container[i + 1]);
                pendings.push_back(container[i]);
            } else {
                larger.push_back(container[i]);
                pendings.push_back(container[i + 1]);
            }
        } else {
            pendings.push_back(container[i]); // si hay elemento impar lo envio a pendings
        }
    }

#ifdef PMERGEME_DEBUG
    std::cout << "Larger: ";
    for (size_t i = 0; i < larger.size(); ++i){
        std::cout << larger[i] << " ";
	}
    std::cout << "\nPendings: ";
    for (size_t i = 0; i < pendings.size(); ++i){
		std::cout << pendings[i] << " ";
	}
	std::cout << std::endl
			  << std::endl;
#endif

	// Paso 2: Ordenar recursivamente los mayores
    mergeInsertSort(larger);

    // Paso 3: Generar secuencia de Jacobsthal para inserciones (Jacobsthal puros + intermedios descendentes)
    std::vector<size_t> jacob = generateJacobsthalSequence(pendings.size());
    std::vector<bool> inserted(pendings.size(), false); //nos dice que indices se han insertado ya

#ifdef PMERGEME_DEBUG
    std::cout << "Jacobsthal: ";
    for (size_t i = 0; i < jacob.size(); ++i)
		std::cout << jacob[i] << " ";
	std::cout << "(pendings.size() = " << pendings.size() << ")";
    std::cout << "\nInsertando con Jacobsthal...\n";
#endif

    // Insertar segun el orden de Jacobsthal
    for (size_t j = 0; j < jacob.size(); ++j) {
		size_t idx = jacob[j]-1; // Convierte a indice 0-based
		if (idx < pendings.size() && !inserted[idx]) { // si indice valido y no insertado aun
            typename T::iterator start = larger.begin();
            typename T::iterator end = larger.end();  // rango completo
            
            //Si tiene pareja, acota el rango de busqueda
            if (idx * 2 + 1 < container.size()) {
                Value partner = container[idx * 2 + 1];
                end = std::upper_bound(start, end, partner);
			}	
            
            binaryInsert(larger, pendings[idx], start, end); //inserta el pendiente en rango acotado de busqueda
            inserted[idx] = true; 
        }
    }

#ifdef PMERGEME_DEBUG
    std::cout << "Insertando pendientes restantes...\n";
#endif

    // Insertar los elementos restantes, no cubiertos por Jacobsthal
    for (size_t i = 0; i < pendings.size(); ++i) {
        if (!inserted[i]) {
            typename T::iterator start = larger.begin();
            typename T::iterator end = larger.end(); // rango completo
            
            if (i * 2 + 1 < container.size()) { // si tiene pareja, acotamos rango
                Value partner = container[i * 2 + 1];
                end = std::upper_bound(start, end, partner); //ponemos el end donde estaria la pareja
            }

            binaryInsert(larger, pendings[i], start, end);
        }
    }

#ifdef PMERGEME_DEBUG
    std::cout << "Resultado final: ";
    for (typename T::iterator it = larger.begin(); it != larger.end(); ++it){
        std::cout << *it << " ";
	}
	std::cout << "\n" << std::endl;
#endif

    container = larger;
}

#endif

