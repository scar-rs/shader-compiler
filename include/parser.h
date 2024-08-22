#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include <vector>
#include <string>

struct Statement {
    std::string name;
    std::vector<std::string> body;
};

using AST = std::vector<Statement>;

class Parser {
public:
    Parser(const std::vector<Token>& tokens);
    AST parse();

private:
    std::vector<Token> tokens_;
    size_t pos_;

    Statement parseStatement();
};

#endif // PARSER_H
