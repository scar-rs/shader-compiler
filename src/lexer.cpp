#include "lexer.h"
#include <cctype>
#include <sstream>

Lexer::Lexer(const std::string& code) : code_(code), pos_(0) {}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (pos_ < code_.size()) {
        char current = code_[pos_];
        if (std::isspace(current)) {
            ++pos_;
        } else if (std::isalpha(current)) {
            tokens.push_back(lexIdentifier());
        } else if (std::isdigit(current)) {
            tokens.push_back(lexNumber());
        } else if (current == '{' || current == '}' || current == ';') {
            tokens.push_back({std::string(1, current), TokenType::SYMBOL});
            ++pos_;
        } else {
            throw std::runtime_error("Unexpected character");
        }
    }
    return tokens;
}

Token Lexer::lexIdentifier() {
    std::string value;
    while (pos_ < code_.size() && std::isalnum(code_[pos_])) {
        value += code_[pos_++];
    }
    return {value, TokenType::IDENTIFIER};
}

Token Lexer::lexNumber() {
    std::string value;
    while (pos_ < code_.size() && std::isdigit(code_[pos_])) {
        value += code_[pos_++];
    }
    return {value, TokenType::NUMBER};
}
