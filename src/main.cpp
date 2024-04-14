#include "Frontend/Parser.h"
#include "Frontend/Lexer.h"

void main()
{
    Parser parser(SourceCode);

    // Parse the source code and generate LLVM IR
    parser.Parse();

    // Get the LLVM module containing the generated IR
    // LLVM IR takes my parser code and turns it into their low-level code..ish
    // llvm::Module* module = parser.getModuleIdentifier(); 

    // Emit LLVM IR to stdout for demonstration
    // module->print(llvm::outs(), nullptr);
}