#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class App
{
public:
    App();
    ~App();

    bool    is_ready_to_run() const;
    void    run();

private:
    GLFWwindow* m_window;
    bool        m_ready_to_run = true;
};
