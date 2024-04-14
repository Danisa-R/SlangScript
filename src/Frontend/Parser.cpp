#include <string>
#include <vector>
#include "Parser.h"

using namespace std;

/* Parser class parses input source code and generates LLVM intermediate representation
   by using Bakus Naur Form (BNF), a notation to describe syntax and grammars of 
   languages.

   The parser is responsible for analyzing the sequence of tokens produced by the 
   lexer and determining whether the input conforms to the syntax rules of the SlangScript. 
*/


// Parses string into an abstract syntax tree
Parser::Parser(string SourceCode){}

void Parser::Parse(){

}

/* Checks token to see if it conforms syntax rules of current language 
   By generating Abstract Syntax Tree (AST)
*/
bool ValidateTokenExpressions(char token)
{
    // todo: make a AST 
    // Implement a tree strucutre 
   
}

