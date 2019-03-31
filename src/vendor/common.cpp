#include <common.hpp>

#include <fstream>


GLFWwindow*
initOpenGL(int width, int height, const char* title) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif
    GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);

    // Check for Valid Context
    if (window == nullptr) {
        std::cerr << "Failed to Create OpenGL Context" << std::endl;
        std::terminate();
    }

    // create context and load OpenGL functions
    glfwMakeContextCurrent(window);
    gladLoadGL();

    return window;
}

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
