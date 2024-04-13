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
    FLOAT,
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
    WHITESPACE,
    END_OF_FILE,
    COMMA,
    SEMICOLON,
    COLON,
    DOT,
    ARROW,
    OPEN_PAREN,
    CLOSE_PAREN,
    OPEN_BRACE,
    CLOSE_BRACE,
    OPEN_BRACKET,
    CLOSE_BRACKET,
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
    BITWISE_AND,
    BITWISE_OR,
    BITWISE_XOR,
    BITWISE_NOT,
    SHIFT_LEFT,
    SHIFT_RIGHT,
    INCREMENT,
    DECREMENT,
    ADD_ASSIGNMENT,
    SUBTRACT_ASSIGNMENT,
    MULTIPLY_ASSIGNMENT,
    DIVIDE_ASSIGNMENT,
    MODULO_ASSIGNMENT,
    BITWISE_AND_ASSIGNMENT,
    BITWISE_OR_ASSIGNMENT,
    BITWISE_XOR_ASSIGNMENT,
    SHIFT_LEFT_ASSIGNMENT,
    SHIFT_RIGHT_ASSIGNMENT,
    QUESTION_MARK,
    COLON,
    VAR_DECLARATION,
    FUNCTION_DECLARATION,
    ARRAY_DECLARATION,
    RETURN_STATEMENT,
    BREAK_STATEMENT,
    CONTINUE_STATEMENT,
    SWITCH_STATEMENT,
    CASE_STATEMENT,
    DEFAULT_STATEMENT,
    TRY_STATEMENT,
    CATCH_STATEMENT,
    THROW_STATEMENT,
    CLASS_DECLARATION,
    STRUCT_DECLARATION,
    ENUM_DECLARATION,
    UNION_DECLARATION,
    TYPEDEF_DECLARATION,
    NAMESPACE_DECLARATION,
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
    /* Looks ahead at the next character in input source w/o consuming it*/
    char peek(); 
    
    /* Reads and consumes the current character in the input source code string */
    char consume();

    /* Skips over whitespace characters in input source code*/
    void skipWhitespace();
    
    /* Skips over comments in the input source code */
    void skipComment();

    /* Reads an identifier token from input source code. Continues until non-alphanumeric
    or underscore character is encountered */
    Token readIdentifier();

    /* Reads an integer literal token from input source code */
    Token readInteger();

}