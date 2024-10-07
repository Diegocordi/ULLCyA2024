// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2
// Practica 2: Cadenas y lenguajes
// Autor: Diego Alejandro Cordido Figueroa
// Correo: alu0101229300@ull.edu.es
// Fecha: 17/09/2024
// Archivo cya-P02-strings.cc: programa cliente.
// Contiene la funcion main del proyecto que usa las clases X e Y
// para ... (indicar brevemente el objetivo)

// Historial de revisiones
// 17/09/2024 - Creaci ́on (primera versi ́on) del c ́odigo

// Iniciar guarda
#ifndef CADENA_H
#define CADENA_H

#include <string>
#include <set>

class Cadena {
  private:
    std::string cadena_;            // Almacena la cadena de caracteres
    std::set<char> alfabeto_;       // Almacena el alfabeto de la cadena

  public:
// Constructor que inicializa la cadena y su alfabeto
  Cadena(const std::string& cadena, const std::set<char>& alfabeto);

// Método que devuelve el alfabeto de la cadena
  std::set<char> ObtenerAlfabeto() const;

// Método que devuelve la longitud de la cadena
  int Longitud() const;

// Método que devuelve la inversa de la cadena
  std::string Inversa() const;

// Método que devuelve los prefijos de la cadena
  std::set<std::string> Prefijos() const;

// Método que devuelve los sufijos de la cadena
  std::set<std::string> Sufijos() const;
};

// Finalizar guarda
#endif CADENA_H
