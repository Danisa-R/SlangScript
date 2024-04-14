#include <string>
#include <vector>
#include "Lexer.h"

/* Lexer class breaks up input source code into tokens */

Lexer::Lexer(const string SourceCode) : sourceCode(SourceCode), position(0) {}

/* Reads char from source code and recognizes tokens based on lexical rules */
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
                } 
                // todo: how do u determine if this is a string
                // Strings in this language will be determined by $ signs 
                // should i use regular expressions to determine if something is a string?
                else {
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
    string identifier;
    while (isalnum(peek()) || peek() == '_') {
        identifier += consume();
    }

    // Token type in LLVM is defined as {TokenType Type: string Value}
    if (identifier.lower() == "for"){
        return {TokenType::FOR_LOOP, identifier};
    } else if (identifier.lower() == "if"){
        return {TokenType::IF_STATEMENT, identifier};
    } else if (identifier.lower() == "while"){
        return {TokenType::WHILE_LOOP, identifier};
    } else {
        return {TokenType::IDENTIFIER, identifier};
    }
}

Token Lexer::IsLiteral(){
    
}

Token Lexer::readInteger() {
    string integer;
    while (isdigit(peek())) {
        integer += consume();
    }
    return {TokenType::INTEGER, integer};
}

