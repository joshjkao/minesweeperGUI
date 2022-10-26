#include "texturemap.h"
#include "texturemanager.h"

TextureMap::TextureMap(int** arr) {
    textures.push_back(TextureManager::loadTexture("assets/0.png"));
    textures.push_back(TextureManager::loadTexture("assets/1.png"));
    textures.push_back(TextureManager::loadTexture("assets/2.png"));
    textures.push_back(TextureManager::loadTexture("assets/3.png"));
    textures.push_back(TextureManager::loadTexture("assets/4.png"));
    textures.push_back(TextureManager::loadTexture("assets/5.png"));
    textures.push_back(TextureManager::loadTexture("assets/6.png"));
    textures.push_back(TextureManager::loadTexture("assets/blank.png"));
    textures.push_back(TextureManager::loadTexture("assets/flag.png"));
    textures.push_back(TextureManager::loadTexture("assets/mine.png"));

    loadMap(arr);

    src.x = src.y = 0;
    src.h = src.w = 32;
    dest.x = dest.y = 0;
    dest.h = dest.w = 32;
}

TextureMap::~TextureMap() {

}

void TextureMap::loadMap(int** arr) {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 30; j++) {
            array[i][j] = arr[i][j];
        }
    }
}

void TextureMap::render() {
    int id = 0;
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 30; j++) {
            id = array[i][j];
            dest.x = (j+1) * 32;
            dest.y = (i+2) * 32;
            switch (id)
            {
            case 0: {
                TextureManager::render(textures[0], src, dest);
                break;
            }
            case 1: {
                TextureManager::render(textures[1], src, dest);
                break;
            }
            case 2: {
                TextureManager::render(textures[2], src, dest);
                break;
            }
            case 3: {
                TextureManager::render(textures[3], src, dest);
                break;
            }
            case 4: {
                TextureManager::render(textures[4], src, dest);
                break;
            }
            case 5: {
                TextureManager::render(textures[5], src, dest);
                break;
            }
            case 6: {
                TextureManager::render(textures[6], src, dest);
                break;
            }
            case -1: {
                TextureManager::render(textures[7], src, dest);
                break;
            }
            case 10: {
                TextureManager::render(textures[8], src, dest);
                break;
            }
            case 20: {
                TextureManager::render(textures[9], src, dest);
                break;
            }
            default: {
                break;
            }
            }
        }
    }
}