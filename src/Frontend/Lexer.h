#include "llvm/IR/Value.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"

#include "Parser.h"

enum class TokenType {
    IDENTIFIER,
    INTEGER,
    PLUS,
    MINUS,
    KEYWORD,
    STRING_LITERAL,
    CHARACTER_LITERAL,
    BOOLEAN_LITERAL,
    OPERATOR,
    COMMENT,
    
    // Keywords
    IF_STATEMENT,
    ELSE_STATEMENT,
    WHILE_LOOP,
    FOR_LOOP,

    PREPROCESSOR_DIRECTIVE,
    END_OF_FILE,
    COMMA,
    SEMICOLON,
    COLON,
    ASSIGNMENT,
    EQUALS,
    NOT_EQUALS,
    GREATER_THAN,
    LESS_THAN,
    GREATER_THAN_OR_EQUAL,
    LESS_THAN_OR_EQUAL,
    AND,
    OR,
    NOT,
    INCREMENT,
    DECREMENT,
    ADD_ASSIGNMENT,
    SUBTRACT_ASSIGNMENT,
    MULTIPLY_ASSIGNMENT,
    DIVIDE_ASSIGNMENT,
    MODULO_ASSIGNMENT,
    FUNCTION_DECLARATION,
    ARRAY_DECLARATION,
    RETURN_STATEMENT,
    BREAK_STATEMENT,
    CONTINUE_STATEMENT,
    SWITCH_STATEMENT,
    CASE_STATEMENT,
    DEFAULT_STATEMENT,
    CLASS_DECLARATION,
    STRUCT_DECLARATION,
    ENUM_DECLARATION,
    TYPEDEF_DECLARATION,
    USING_DIRECTIVE,
    IMPORT_DIRECTIVE,
    EXPORT_DIRECTIVE,
    ATTRIBUTE,
    ANNOTATION,
    ACCESS_MODIFIER,
    STATIC_MODIFIER,
    CONST_MODIFIER,
    FINAL_MODIFIER,
    VIRTUAL_MODIFIER,
    OVERRIDE_MODIFIER,
    ABSTRACT_MODIFIER,
    PRIVATE_ACCESS,
    PROTECTED_ACCESS,
    PUBLIC_ACCESS
};

struct Token {
    TokenType type;
    string value;
};

class Lexer {
public:
    Lexer(const string SourceCode): sourceCode(SourceCode), position(0) {}
    Token GetNextToken(){}

private:
    string SourceCode;
    size_t position;
    
    // Helper functions

    /* Looks ahead at the next character in input source without consuming it*/
    char peek(); 
    
    /* Reads and consumes the current character in the input source code string */
    char consume();

    /* Skips over whitespace characters in input source code*/
    void skipWhitespace();
    
    /* Skips over comments in the input source code */
    void skipComment();

    /* Reads an token from input source code. Continues until non-alphanumeric
    or underscore character is encountered */
    Token readToken();

}