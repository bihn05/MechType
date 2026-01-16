
#include "shader.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

const int WIDTH = 800;
const int HEIGHT = 800;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

float vertices[] = {
     1.0f,  1.0f, 0.0f,  // 右上
     1.0f, -1.0f, 0.0f,  // 右下
    -1.0f, -1.0f, 0.0f,  // 左下
    -1.0f,  1.0f, 0.0f   // 左上
};
unsigned int indices[] = {0,1,3,1,2,3};
unsigned int VBO, VAO, EBO;
void drawBone(Shader &s, glm::vec2 startPos, float length, glm::vec3 color) {
    s.use();

    glUniform3fv(glGetUniformLocation(s.ID, "u_color"), 1, glm::value_ptr(color));

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(startPos, 0.0f));
    model = glm::scale(model, glm::vec3(length, 1.0f, 1.0f));

    glUniformMatrix4fv(glGetUniformLocation(s.ID, "u_model"), 1, GL_FALSE, glm::value_ptr(model));

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
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

    Shader hgShader("shaders/hg.vert", "shaders/hg.frag");

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
        
        glm::vec2 start = glm::vec2({-0.7f, 0.0f});
        glm::vec3 color = glm::vec3({0.0f, 1.0f, 0.0f});
        drawBone(hgShader, start, 0.5f, color);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}