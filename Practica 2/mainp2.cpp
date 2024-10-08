// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: [Tu Nombre]
// Correo: alu0101229300@ull.edu.es
// Fecha: [Fecha Actual]
// Archivo: main.cc
// Descripción: Programa principal que utiliza la clase Cadena para
// realizar operaciones sobre cadenas y sus alfabetos a partir de un
// archivo de entrada y un código de operación.
// Historial de revisiones:
// [Fecha Actual] - Creación del archivo (primera versión).

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "cadena.h"

int main(int argc, char* argv[]) {
    // Verificamos el número de argumentos
    if (argc != 4) {
        std::cerr << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode\n";
        return 1; // Salida con error
    }

    // Abrimos los archivos de entrada y salida
    std::ifstream archivo_entrada(argv[1]);
    std::ofstream archivo_salida(argv[2]);
    int opcode = std::stoi(argv[3]); // Convertimos el argumento a entero

    // Verificamos si los archivos se abrieron correctamente
    if (!archivo_entrada.is_open() || !archivo_salida.is_open()) {
        std::cerr << "Error al abrir los archivos.\n";
        return 1; // Salida con error
    }

    // Variables para almacenar la cadena y el alfabeto
    std::string cadena;
    std::string alfabeto_str;

    // Leemos las líneas del archivo de entrada
    while (archivo_entrada >> cadena >> alfabeto_str) {
        // Convertimos el string de alfabeto a un set de caracteres
        std::set<char> alfabeto(alfabeto_str.begin(), alfabeto_str.end());
        
        // Creamos un objeto de la clase Cadena
        Cadena mi_cadena(cadena, alfabeto);

        // Ejecutamos la operación según el código
        switch (opcode) {
            case 1:  // Alfabeto
                archivo_salida << "{ ";
                for (auto c : mi_cadena.ObtenerAlfabeto()) {
                    archivo_salida << c << " "; // Imprimimos cada símbolo
                }
                archivo_salida << "}\n";
                break;
            case 2:  // Longitud
                archivo_salida << mi_cadena.Longitud() << "\n"; // Imprimimos la longitud
                break;
            case 3:  // Inversa
                archivo_salida << mi_cadena.Inversa() << "\n"; // Imprimimos la inversa
                break;
            case 4:  // Prefijos
                {
                    auto prefijos = mi_cadena.Prefijos(); // Obtenemos los prefijos
                    archivo_salida << "{ ";
                    for (const auto& pref : prefijos) {
                        archivo_salida << pref << " "; // Imprimimos cada prefijo
                    }
                    archivo_salida << "}\n";
                }
                break;
            case 5:  // Sufijos
                {
                    auto sufijos = mi_cadena.Sufijos(); // Obtenemos los sufijos
                    archivo_salida << "{ ";
                    for (const auto& suf : sufijos) {
                        archivo_salida << suf << " "; // Imprimimos cada sufijo
                    }
                    archivo_salida << "}\n";
                }
                break;
            default:
                std::cerr << "Código de operación no válido.\n";
                return 1; // Salida con error
        }
    }

    // Cerramos los archivos
    archivo_entrada.close();
    archivo_salida.close();

    return 0; // Salida exitosa
}
