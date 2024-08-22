#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include "parser.h"

class Optimizer {
public:
    AST optimize(const AST& ast);
};

#endif // OPTIMIZER_H
