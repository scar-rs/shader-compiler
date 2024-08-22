
### `src/main.cpp`

```cpp
#include <iostream>
#include "lexer.h"
#include "parser.h"
#include "optimizer.h"
#include "codegen.h"

int main() {
    std::string shader_code = "int main() { return 0; }";
    
    Lexer lexer(shader_code);
    auto tokens = lexer.tokenize();

    Parser parser(tokens);
    auto ast = parser.parse();

    Optimizer optimizer;
    auto optimized_ast = optimizer.optimize(ast);

    Codegen codegen;
    auto assembly_code = codegen.generate(optimized_ast);

    std::cout << "Generated Assembly Code:\n" << assembly_code << std::endl;
    
    return 0;
}
