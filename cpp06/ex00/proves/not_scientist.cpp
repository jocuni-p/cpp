#include <iostream>
#include <cfloat>
#include <cmath> // para NAN

#include <sstream> // para notacion cientifica -> decimal
#include <iomanip> // para notacion cientifica -> decimal

using namespace std;

std::string scientificToDecimal(double number) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(10) << number; // Ajusta la precisión según sea necesario
    return oss.str();
}

std::string scientificToDecimal(float number) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(10) << number; // Ajusta la precisión según sea necesario
    return oss.str();
}
/*
int main() {
    double num = 1.23e+05;
    std::string decimalStr = scientificToDecimal(num);
    std::cout << "Número en notación decimal: " << decimalStr << std::endl;
    return 0;
}
*/

int main() {
    // Declaring variables
    float a = FLT_MAX;
    double b = NAN;
	double c = DBL_MAX;

    // Printing the values of the variables
	cout << "Float value: " << a << endl;
    cout << "Float value (NOTACION DECIMAL): " << scientificToDecimal(a) << endl;
    cout << "Double value: " << b << endl;
	cout << "Double value: " << c << endl;
	cout << "Double value (NOTACION DECIMAL): " << scientificToDecimal(c) << endl;

    return 0;
}