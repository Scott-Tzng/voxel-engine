#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void glfw_error_callback(int error, const char* description);
void glfw_framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main()
{
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
    {
        std::cerr << "GLFW Initialization failed\n";
        glfwTerminate();
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(640, 480, "Voxel Engine", NULL, NULL);
    if (!window)
    {
        std::cerr << "Couldn't create GLFW window\n";
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, glfw_framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD\n";
        glfwTerminate();
        return -1;
    }

    glClearColor(90.0f / 255.0f, 90.0f / 255.0f, 90.0f / 255.0f, 1.0f);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

void glfw_error_callback(int error, const char* description)
{
    std::cerr << "Error: " << description << '\n';
}

void glfw_framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}