#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

// Función para validar si una cadena representa un número decimal
bool isDecimal(const std::string& str) {
    std::istringstream iss(str);
    double num;
    return (iss >> num) && (iss.eof());
}

int main() {
    std::string filename = "./data/datos.txt"; // Cambia esto al nombre de tu archivo de texto
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error al abrir el archivo: " << filename << std::endl;
        return 1;
    }

    std::vector<double> numeros;
    std::string linea;

    while (std::getline(inputFile, linea)) {
        if (isDecimal(linea)) {
            double num = std::stod(linea);
            numeros.push_back(num);
        }
    }

    inputFile.close();

    if (numeros.empty()) {
        std::cout << "No se encontraron números válidos en el archivo." << std::endl;
        return 0;
    }

    // Calcular la media
    double suma = 0.0;
    for (double num : numeros) {
        suma += num;
    }
    double media = suma / numeros.size();

    std::cout << "Media de los números encontrados: " << media << std::endl;

    return 0;
}