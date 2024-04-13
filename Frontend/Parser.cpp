#include "string"
#include "vector"

#include "Parser.h"

/* Parser class parses input source code and generates LLVM intermediate representation
   by using Bakus Naur Form (BNF), a notation to describe syntax and grammars of 
   languages
*/

class Parser{
    // Parses string into an abstract syntax tree
    void Parse(string SourceCode){}
    bool ValidateToken(char token){
        return true;
    }

}