#include <string>
#include <vector>
#include "Lexer.h"

/* Lexer class tokenizes input source code*/

Lexer::Lexer(const string SourceCode) : sourceCode(SourceCode), position(0) {}

/* Reads character from source code and recognizes tokens based on lexical rules */
Token GetNextToken(){
    // Tokenize the string
    while (peek() != '\0') {
        skipWhitespace();
        skipComment();
        
        char currentChar = peek();
        switch (currentChar) {
            case '+':
                consume();
                return {TokenType::PLUS, "+"};
            case '-':
                consume();
                return {TokenType::MINUS, "-"};
            default:
                if (isalpha(currentChar) || currentChar == '_') {
                    return readIdentifier();
                } else if (isdigit(currentChar)) {
                    return readInteger();
                } else {
                    // Unrecognized character, skip
                    consume();
                }
        }
    }
    // End of file
    return {TokenType::END_OF_FILE, ""};
}

char Lexer::peek() {
    if (position < sourceCode.length()) {
        return sourceCode[position];
    }
    return '\0';
}

char Lexer::consume() {
    if (position < sourceCode.length()) {
        return sourceCode[position++];
    }
    return '\0';
}

void Lexer::skipWhitespace() {
    while (isspace(peek())) {
        consume();
    }
}

void Lexer::skipComment() {
    if (peek() == '/' && peek() == '/') {
        // Skip single-line comment
        while (peek() != '\n' && peek() != '\0') {
            consume();
        }
    }
}

Token Lexer::readIdentifier() {
    std::string identifier;
    while (isalnum(peek()) || peek() == '_') {
        identifier += consume();
    }
    return {TokenType::IDENTIFIER, identifier};
}

Token Lexer::readInteger() {
    std::string integer;
    while (isdigit(peek())) {
        integer += consume();
    }
    return {TokenType::INTEGER, integer};
}

