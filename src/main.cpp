#include "../include/main.hpp"


int main() {
    /* Initialize the library */
    if (!glfwInit()) {
        std::cout << "Can't load GLFW!" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* pWindow = glfwCreateWindow(gWindowSizeX, gWindowSizeY, "BattleCity", nullptr, nullptr);
    if (!pWindow) {
        std::cout << "glfwCreateWindow() failed!" << std::endl;
        glfwTerminate();
        return -1;
    }

    /* Resize window */
    glfwSetWindowSizeCallback(pWindow, glfwWindowSizeCallback);

    /* Key Callback function */
    glfwSetKeyCallback(pWindow, glfwKeyCallback);

    /* Make the window's context current */
    glfwMakeContextCurrent(pWindow);

    if (!gladLoadGL()) {
        std::cout << "Can't load GLAD!" << std::endl;
        glfwTerminate();
        return -1;
    }

    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

    glClearColor(1, 1, 0, 1);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pWindow)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void glfwWindowSizeCallback(GLFWwindow* pWindow, const int widgh, const int height) {
    gWindowSizeX = widgh;
    gWindowSizeY = height;
    glViewport(0, 0, gWindowSizeX, gWindowSizeY);
}

void glfwKeyCallback(GLFWwindow* pWindow, const int key, const int scancode, const int action, const int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
    }
}
