#include "llvm/IR/Value.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"

class Parser{
public:
    Parser(string SourceCode): lexer(SourceCode), builder(context){}

    void Parse(){}

    llvm:Module* GetModule(){
        return module;
    }
    
    bool ValidateToken(char token);

private:
    llvm::LLVMContext context;
    llvm::IRBuilder<> builder;
    llvm::Module* module;

    Lexer lexer;

}