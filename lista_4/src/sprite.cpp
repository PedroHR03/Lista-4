#include "Sprite.h"
#include <GL/glew.h>
#include <stb_image.h>
#include <iostream>

Sprite::Sprite(const char* imagePath, float x, float y, float w, float h)
    : posX(x), posY(y), width(w), height(h), textureID(0), loaded(false) {
    loadTexture(imagePath);
}

void Sprite::loadTexture(const char* imagePath) {
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    int widthImg, heightImg, channels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(imagePath, &widthImg, &heightImg, &channels, STBI_rgb_alpha);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthImg, heightImg, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        stbi_image_free(data);
        loaded = true;
    } else {
        std::cerr << "Erro ao carregar a textura: " << imagePath << std::endl;
        loaded = false;
    }

    glBindTexture(GL_TEXTURE_2D, 0);
}

bool Sprite::isLoaded() const {
    return loaded;
}

void Sprite::draw() {
    if (!loaded) return;

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();  // Impede acúmulo de transformações

    glBindTexture(GL_TEXTURE_2D, textureID);
    glEnable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex2f(posX, posY);
        glTexCoord2f(1.0f, 0.0f); glVertex2f(posX + width, posY);
        glTexCoord2f(1.0f, 1.0f); glVertex2f(posX + width, posY + height);
        glTexCoord2f(0.0f, 1.0f); glVertex2f(posX, posY + height);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
}

