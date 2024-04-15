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

void Parser::Parse(){

}

/* Checks token to see if it conforms syntax rules of current language 
   By generating Abstract Syntax Tree (AST)
*/
bool Parser::ValidateTokenExpressions(char token)
{
    // todo: make a AST 
    // Implement a tree strucutre 
    // Note: Typically the output of the front end is an AST
    //       This output will be provided as input to our middle-layer/backend.
    //       (AST is source code as tree structure)
    auto validate = [](char token){
        // count how many times a function variable component or prop
        // is used in source code
        // transform code from one syntax to another



        /*
        Ex: 2 + (4 * 10) Looks like this tree below:
        
         +
        / \
       /   *
      2     \
           / \
          4  10
        
        */

    };
   
}

