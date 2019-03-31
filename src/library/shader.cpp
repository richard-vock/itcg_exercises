#include <shader.hpp>

#include <fstream>

const char*
loadShaderFile(const char* filename) {
    std::string actualFile = SHADER_ROOT + filename;
    std::ifstream in(actualFile.c_str());
    std::string str((std::istreambuf_iterator<char>(in)),
                     std::istreambuf_iterator<char>());
    char* code = new char[str.size()+1];
    code[str.size()] = '\0';
    str.copy(code, str.size());
    return code;
}
