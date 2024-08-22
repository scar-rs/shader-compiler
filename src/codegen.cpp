#include "codegen.h"

std::string Codegen::generate(const AST& ast) {
    std::string assembly_code;
    for (const auto& stmt : ast) {
        assembly_code += "MOV " + stmt.name + "\n";
        for (const auto& line : stmt.body) {
            assembly_code += line + "\n";
        }
    }
    return assembly_code;
}
