#include <iostream>
#include <fstream>
#include <sstream>

// Función para validar si una cadena representa un número decimal
bool isDecimal(const std::string& str) {
    std::istringstream iss(str);
    double num;
    return (iss >> num) && (iss.eof());
}

int main() {
    std::string filename = "./data/datos.txt";
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error al abrir el archivo: " << filename << std::endl;
        return 1;
    }

    double suma = 0.0;
    int count = 0;
    std::string linea;

    while (std::getline(inputFile, linea)) {
        if (isDecimal(linea)) {
            double num = std::stod(linea);
            suma += num;
            count++;
        }
    }

    inputFile.close();

    if (count == 0) {
        std::cout << "No se encontraron números válidos en el archivo." << std::endl;
        return 0;
    }

    // Calcular la media
    double media = suma / count;

    std::cout << "Media de los números encontrados: " << media << std::endl;

    return 0;
}
