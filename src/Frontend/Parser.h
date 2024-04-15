#include "llvm/IR/Value.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "Lexer.h"

using namespace std;

// Parser uses LLVM's Module in order to not have to make own intermediate representation. We're
// just using their's.

class Parser : llvm::Module {
public:
    Parser(string SourceCode):  llvm::Module("", context), lexer(SourceCode), builder(context) {}

    class ExprAST {
        //virtual ~ExprAST() = default;              // destructor
    };

    class NumberExprAST : public ExprAST {
        double Val;
        NumberExprAST(double Val) : Val(Val) {} // constructor
    };
    /* Variables capture the variable name */
    class VariableExprAST : public ExprAST {
        string Name;
        VariableExprAST(const string &Name) : Name(Name) {}

    };
    /* Binary operators capture their opcode (e.g. ‘+’) */
    class BinaryExprAST : public ExprAST {
        char Op;
        unique_ptr<ExprAST> LHS, RHS; // left hand side, right hand side
        BinaryExprAST(char Op, unique_ptr<ExprAST> LHS,unique_ptr<ExprAST> RHS) : Op (Op), LHS(move(LHS)), RHS (move(RHS)){}
    };

    class CallExprAst : public ExprAST {
        string Callee;
        vector<unique_ptr<ExprAST>> Args;
        CallExprAst(string &Callee, vector<unique_ptr<ExprAST>> Args) : Callee(Callee), Args(move(Args)) {}
    };

    class PrototypeAST {
        string Name;
        vector<string> Args;

        PrototypeAST(const string &Name, vector<string> Args): Name(Name), Args(Args){}
    };

    class FunctionAST {
        unique_ptr<PrototypeAST> Prototype;
        unique_ptr<ExprAST> FunctionBody;
        FunctionAST(unique_ptr<PrototypeAST> Prototype, unique_ptr<ExprAST> FunctionBody): Prototype(move(Prototype)), FunctionBody(move(FunctionBody)){}
    };

    void Parse();
    
    bool ValidateTokenExpressions(char token);

private:
    Lexer lexer;

    llvm::LLVMContext context;
    llvm::IRBuilder<> builder;
    llvm::Module* module;
};