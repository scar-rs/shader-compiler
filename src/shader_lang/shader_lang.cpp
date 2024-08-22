#include "shader_lang.h"
#include <sstream>

// Example shader language constructs

// A basic class representing a shader variable
ShaderVariable::ShaderVariable(const std::string& name, const std::string& type)
    : name(name), type(type) {}

std::string ShaderVariable::to_string() const {
    std::ostringstream oss;
    oss << type << " " << name;
    return oss.str();
}

// A basic class representing a shader function
ShaderFunction::ShaderFunction(const std::string& name)
    : name(name) {}

void ShaderFunction::add_variable(const ShaderVariable& var) {
    variables.push_back(var);
}

void ShaderFunction::add_statement(const std::string& statement) {
    statements.push_back(statement);
}

std::string ShaderFunction::to_string() const {
    std::ostringstream oss;
    oss << "void " << name << "() {\n";
    for (const auto& var : variables) {
        oss << "    " << var.to_string() << ";\n";
    }
    for (const auto& stmt : statements) {
        oss << "    " << stmt << "\n";
    }
    oss << "}";
    return oss.str();
}

// Example usage
void define_example_shader() {
    ShaderVariable var1("color", "vec4");
    ShaderVariable var2("position", "vec3");

    ShaderFunction func("main");
    func.add_variable(var1);
    func.add_variable(var2);
    func.add_statement("color = vec4(1.0, 0.0, 0.0, 1.0);");
    func.add_statement("position = vec3(0.0, 0.0, 0.0);");

    std::string shader_code = func.to_string();
    // Output or use the shader code
    std::cout << shader_code << std::endl;
}
