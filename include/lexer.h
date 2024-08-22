#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

enum class TokenType {
    IDENTIFIER,
    NUMBER,
    SYMBOL
};

struct Token {
    std::string value;
    TokenType type;
};

class Lexer {
public:
    Lexer(const std::string& code);
    std::vector<Token> tokenize();

private:
    std::string code_;
    size_t pos_;

    Token lexIdentifier();
    Token lexNumber();
};

#endif // LEXER_H
