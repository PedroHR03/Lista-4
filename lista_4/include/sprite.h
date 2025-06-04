#ifndef SPRITE_H
#define SPRITE_H

class Sprite {
public:
    Sprite(const char* imagePath, float x, float y, float width, float height);
    void draw();
    bool isLoaded() const;

private:
    unsigned int textureID;
    float posX, posY, width, height;
    bool loaded;

    void loadTexture(const char* imagePath);
};

#endif
