// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Diego Alejandro Cordido Figueroa
// Correo: alu0101229300@ull.edu.es
// Fecha: 
// Archivo: main.cpp

#include "CodeAnalyzer.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>\n";
        return 1;
    }

    CodeAnalyzer analyzer;
    analyzer.analyze(argv[1]);
    analyzer.printResults(argv[2]);

    return 0;
}
