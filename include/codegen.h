#ifndef CODEGEN_H
#define CODEGEN_H

#include "parser.h"
#include <string>

class Codegen {
public:
    std::string generate(const AST& ast);
};

#endif // CODEGEN_H
