#ifndef TEXTUREMAP_H
#define TEXTUREMAP_H
#include "app.h"

class TextureMap {
    public:
        TextureMap(int** arr);
        ~TextureMap();

        void loadMap(int** arr);
        void render();

    private:
        SDL_Rect src;
        SDL_Rect dest;
        std::vector <SDL_Texture*> textures;
        
        int array[16][30];
};

#endif