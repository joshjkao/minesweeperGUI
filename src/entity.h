#ifndef ENTITY_H
#define ENTITY_H
#include "app.h"
#include "texturemanager.h"

class Entity {
    public: 
        Entity(const char* texturefile, int x, int y);
        ~Entity();

        void update();
        void render();

    private:
        int xpos;
        int ypos;

        SDL_Texture* texture;
        SDL_Rect src_rect;
        SDL_Rect dest_rect;

};

#endif