#include "App.hpp"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

App::App()
{
    if (!glfwInit())
    {
        std::cerr << "GLFW Initialization failed\n";
        glfwTerminate();
        m_ready_to_run = false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    m_window = glfwCreateWindow(640, 480, "Voxel Engine", NULL, NULL);
    if (!m_window) {
        std::cerr << "ERROR: Couldn't create GLFW window\n";
        glfwTerminate();
        m_ready_to_run = false;
    }

    glfwMakeContextCurrent(m_window);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "ERROR: Failed to initialize GLAD\n";
        glfwTerminate();
        m_ready_to_run = false;
    }

    if (m_ready_to_run) {
        glClearColor(
            50.0f  / 255.0f,
            102.0f / 255.0f,
            122.0f / 255.0f,
            1.0f
        );
    }
}

App::~App()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

bool App::is_ready_to_run() const
{
    return m_ready_to_run;
}

void App::run()
{
    while (!glfwWindowShouldClose(m_window)) {
        if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(m_window, true);
        }

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}
