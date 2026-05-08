#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "App.hpp"

const char *vertex_shader_source = 
    "#version 330 core\n"
    "layout (location = 0) in vec3 a_pos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(a_pos, 1.0);\n"
    "}\n";
const char *fragment_shader_source =
    "#version 330\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n";

void glfw_error_callback(int error, const char* description);
void glfw_framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main()
{
    //float vertices[] = {
    //     -0.5f, -0.5f, 0.0f, // left  
    //      0.5f, -0.5f, 0.0f, // right 
    //      0.0f,  0.5f, 0.0f  // top   
    //};

    //unsigned vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    //glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
    //glCompileShader(vertex_shader);

    //unsigned int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    //glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
    //glCompileShader(fragment_shader);

    //unsigned int shader_program = glCreateProgram();
    //glAttachShader(shader_program, vertex_shader);
    //glAttachShader(shader_program, fragment_shader);
    //glLinkProgram(shader_program);

    //glDeleteShader(vertex_shader);
    //glDeleteShader(fragment_shader);

    //unsigned int VBO;
    //unsigned int VAO;

    //glGenVertexArrays(1, &VAO);
    //glGenBuffers(1, &VBO);
    //glBindVertexArray(VAO);

    //glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    //glEnableVertexAttribArray(0);

    //glBindBuffer(GL_ARRAY_BUFFER, 0);

    //glBindVertexArray(0);

    //while (!glfwWindowShouldClose(window))
    //{
    //    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    //    {
    //        glfwSetWindowShouldClose(window, true);
    //    }

    //    glClear(GL_COLOR_BUFFER_BIT);

    //    glUseProgram(shader_program);
    //    glBindVertexArray(VAO);
    //    glDrawArrays(GL_TRIANGLES, 0, 3);

    //    glfwSwapBuffers(window);
    //    glfwPollEvents();
    //}

    //glfwDestroyWindow(window);
    //glfwTerminate();
    
    App app;
    if (app.is_ready_to_run()) {
        app.run();
    }

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
