#include "llvm/IR/Value.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "Lexer.h"

class Parser : llvm::Module {
public:
    Parser(string SourceCode): lexer(SourceCode), builder(context){}

    class Node {
        virtual ~Node() {}
        virtual NodeType getType() const = 0;

        int data;
        Node* left;
        Node* right;
    };
    
    void Parse(){}
    
    bool ValidateTokenExpressions(char token);

private:
    
    Lexer lexer;

    // llvm::LLVMContext context;
    // llvm::IRBuilder<> builder;
    // llvm::Module* module;
}