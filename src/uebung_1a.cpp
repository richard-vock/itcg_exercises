// Local Headers
#include "common.hpp"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 800;

void resize_callback(GLFWwindow* window, int width, int height);

int main(int, char* argv[]) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, argv[0], nullptr, nullptr);

    // Check for Valid Context
    if (window == nullptr) {
        std::cerr << "Failed to Create OpenGL Context" << std::endl;
        std::terminate();
    }

    // create context and load OpenGL functions
    glfwMakeContextCurrent(window);
    gladLoadGL();
    fprintf(stdout, "OpenGL %s\n", glGetString(GL_VERSION));

    glfwSetFramebufferSizeCallback(window, resize_callback);

    // rendering loop
    while (glfwWindowShouldClose(window) == false) {
        // set background color...
        glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
        // and fill screen with it (therefore clearing the window)
        glClear(GL_COLOR_BUFFER_BIT);

        // render something... (here: nothing)

        // swap buffers == show rendered content
        glfwSwapBuffers(window);
        // process window events
        glfwPollEvents();
    }

    glfwTerminate();
}

void resize_callback(GLFWwindow*, int width, int height)
{
    // set new width and height as viewport size
    glViewport(0, 0, width, height);
}
