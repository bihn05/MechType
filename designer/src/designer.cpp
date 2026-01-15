
#include "shader.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

const int WIDTH = 800;
const int HEIGHT = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

float vertices[] = {
    1.0f, 1.0f, 0.0f,
    1.0f,-1.0f, 0.0f,
   -1.0f,-1.0f, 0.0f,
   -1.0f, 1.0f, 0.0f
};
unsigned int indices[] = {0,1,3,1,2,3};
unsigned int VBO, VAO, EBO;
int main() {
    if (!glfwInit())return -1;

    glfwWindowHint(GLFW_SAMPLES, 0);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "MTD", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)return -1;

    Shader hgShader("../shaders/hg.vert", "../shaders/hg.frag");

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
 
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glDisable(GL_MULTISAMPLE);
    glClearColor(0.1f, 0.1f, 0.1f, 0.1f);

    while (!glfwWindowShouldClose(window)) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
        
        glClear(GL_COLOR_BUFFER_BIT);

        hgShader.use();

        int tightnessLoc = glGetUniformLocation(hgShader.ID, "u_tightness");
        glUniform1f(tightnessLoc, 0.4f); // 0.4 的收缩力度，类似凹透镜

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}