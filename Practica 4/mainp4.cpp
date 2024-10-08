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
