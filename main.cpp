
void main()
{
    Parser parser(SourceCode);

    // Parse the source code and generate LLVM IR
    parser.parse();

    // Get the LLVM module containing the generated IR
    llvm::Module* module = parser.getModule();

    // Emit LLVM IR to stdout for demonstration
    module->print(llvm::outs(), nullptr);
}