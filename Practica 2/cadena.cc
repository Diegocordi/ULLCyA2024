// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: [Tu Nombre]
// Correo: aluXXXXX@ull.edu.es
// Fecha: [Fecha Actual]
// Archivo: cadena.cc
// Descripción: Implementación de la clase Cadena que maneja cadenas de
// caracteres y su alfabeto, permitiendo realizar varias operaciones.
// Historial de revisiones:
// [Fecha Actual] - Creación del archivo (primera versión).

#include "cadena.h"
#include <algorithm> // Para std::reverse
#include <iterator>  // Para std::inserter

// Constructor que inicializa la cadena y su alfabeto
Cadena::Cadena(const std::string& cadena, const std::set<char>& alfabeto)
    : cadena_(cadena), alfabeto_(alfabeto) {}

// Método que devuelve el alfabeto de la cadena
std::set<char> Cadena::ObtenerAlfabeto() const {
    return alfabeto_;
}

// Método que devuelve la longitud de la cadena
int Cadena::Longitud() const {
    return cadena_.size();
}

// Método que devuelve la inversa de la cadena
std::string Cadena::Inversa() const {
    std::string inversa = cadena_; // Copiamos la cadena original
    std::reverse(inversa.begin(), inversa.end()); // Invertimos la cadena
    return inversa; // Devolvemos la cadena invertida
}

// Método que devuelve los prefijos de la cadena
std::set<std::string> Cadena::Prefijos() const {
    std::set<std::string> prefijos; // Conjunto para almacenar los prefijos
    for (size_t i = 0; i <= cadena_.size(); ++i) {
        prefijos.insert(cadena_.substr(0, i)); // Agregamos los prefijos al conjunto
    }
    return prefijos; // Devolvemos el conjunto de prefijos
}

// Método que devuelve los sufijos de la cadena
std::set<std::string> Cadena::Sufijos() const {
    std::set<std::string> sufijos; // Conjunto para almacenar los sufijos
    for (size_t i = 0; i < cadena_.size(); ++i) {
        sufijos.insert(cadena_.substr(i)); // Agregamos los sufijos al conjunto
    }
    sufijos.insert(""); // Agregamos la cadena vacía como sufijo
    return sufijos; // Devolvemos el conjunto de sufijos
}
