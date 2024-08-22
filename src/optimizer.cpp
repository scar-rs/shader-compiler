#include "optimizer.h"

AST Optimizer::optimize(const AST& ast) {
    AST optimized_ast;
    for (const auto& stmt : ast) {
        // Simple optimization: Remove unnecessary statements
        if (stmt.name != "return") {
            optimized_ast.push_back(stmt);
        }
    }
    return optimized_ast;
}
