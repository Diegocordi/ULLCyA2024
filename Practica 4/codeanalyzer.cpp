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

#include "CodeAnalyzer.h"

void CodeAnalyzer::analyze(const std::string& inputFile) {
    std::ifstream file(inputFile);
    std::string line;
    int lineNumber = 0;

    std::regex varRegex(R"((int|double)\s+([a-zA-Z_]\w*)(\s*=\s*[^;]*)?;)");
    std::regex loopRegex(R"(for\s*\(.*\)|while\s*\(.*\))");
    std::regex mainRegex(R"\bmain\s*\(\s*\)");
    std::regex commentSingleRegex(R"(//.*)");
    std::regex commentMultiRegex(R"(\/\*.*?\*\/)");

    while (std::getline(file, line)) {
        lineNumber++;
        if (std::regex_search(line, mainRegex)) {
            mainExists = true;
        }

        // Match variable declarations
        std::smatch varMatch;
        if (std::regex_search(line, varMatch, varRegex)) {
            bool initialized = varMatch[3].matched; // Check if initialized
            variables.emplace_back(varMatch[2], varMatch[1], lineNumber, initialized);
        }

        // Match loops
        if (std::regex_search(line, loopRegex)) {
            loops.emplace_back(loopRegex.str(), lineNumber);
        }

        // Match single-line comments
        if (std::regex_search(line, commentSingleRegex)) {
            comments.emplace_back(line, lineNumber);
        }

        // Match multi-line comments
        if (std::regex_search(line, commentMultiRegex)) {
            comments.emplace_back(line, lineNumber);
        }
    }
}

void CodeAnalyzer::printResults(const std::string& outputFile) {
    std::ofstream out(outputFile);
    out << "PROGRAM: " << outputFile << "\n";
    out << "MAIN: " << (mainExists ? "True" : "False") << "\n\n";

    out << "VARIABLES:\n";
    for (const auto& var : variables) {
        out << "[Line " << var.line << "] " << var.type << ": " << var.name << (var.initialized ? " (initialized)" : "") << "\n";
    }
    
    out << "\nSTATEMENTS:\n";
    for (const auto& loop : loops) {
        out << "[Line " << loop.line << "] LOOP: " << loop.type << "\n";
    }

    out << "\nCOMMENTS:\n";
    for (const auto& comment : comments) {
        out << "[Line " << comment.lines[0] << "] " << comment.content << "\n";
    }
    out.close();
}
