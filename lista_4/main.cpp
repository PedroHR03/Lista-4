// Projeto: Sprite com textura usando OpenGL Fixo (sem shaders)

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <GL/gl.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Sprite.h"

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(800, 600, "Sprite com OpenGL Fixo", nullptr, nullptr);
    if (!window) return -1;
    glfwMakeContextCurrent(window);

if (glewInit() != GLEW_OK) {
    std::cerr << "Erro ao inicializar GLEW." << std::endl;
    return -1;
}

// Ativa suporte a transparência
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Configura projeção ortográfica 2D
    glViewport(0, 0, 800, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 0, 600, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    Sprite sprite("imagens/4.png", 0, 00, 800, 600);
    Sprite sprite2("imagens/2.png", 300, 400, 200, 150);
    Sprite sprite3("imagens/1.png", 0, 0, 1000, 1000);
    Sprite sprite4("imagens/3.png", 200, 10, 100, 100);
    if (!sprite.isLoaded() || !sprite2.isLoaded() || !sprite3.isLoaded() || !sprite4.isLoaded()) return -1;

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.1f, 0.2f, 0.25f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        sprite3.draw();
        sprite.draw();
        sprite2.draw();
        sprite4.draw();


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;

}
