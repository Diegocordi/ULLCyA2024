// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Diego Alejandro Cordido Figueroa
// Correo: alu0101229300@ull.edu.es
// Fecha: 
// Archivo: CodeAnalyzer.h

#ifndef CODEANALYZER_H
#define CODEANALYZER_H

#include <string>
#include <regex>
#include <vector>
#include <iostream>
#include <fstream>

class Variable {
public:
    std::string name;
    std::string type;
    int line;
    bool initialized;

    Variable(std::string n, std::string t, int l, bool init)
        : name(n), type(t), line(l), initialized(init) {}
};

class Loop {
public:
    std::string type;
    int line;

    Loop(std::string t, int l) : type(t), line(l) {}
};

class Comment {
public:
    std::string content;
    std::vector<int> lines;

    Comment(std::string c, int line) : content(c) {
        lines.push_back(line);
    }
};

class CodeAnalyzer {
private:
    std::vector<Variable> variables;
    std::vector<Loop> loops;
    std::vector<Comment> comments;
    bool mainExists = false;

public:
    void analyze(const std::string& inputFile);
    void printResults(const std::string& outputFile);
};

#endif
