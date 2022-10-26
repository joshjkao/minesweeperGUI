#include "entity.h"

Entity::Entity(const char* texturefile, int x, int y):
xpos(x), ypos(y), texture(TextureManager::loadTexture(texturefile))
{
    src_rect.h = 900;
    src_rect.w = 900;
    src_rect.x = 0;
    src_rect.y = 0;

    dest_rect.x = xpos;
    dest_rect.y = ypos;
    dest_rect.h = 300;
    dest_rect.w = 300;
    std::cout << "created entity" << std::endl;
}

Entity::~Entity() {

}

void Entity::update() {
    src_rect.h = 900;
    src_rect.w = 900;
    src_rect.x = 0;
    src_rect.y = 0;

    dest_rect.x = xpos;
    dest_rect.y = ypos;
    dest_rect.h = 300;
    dest_rect.w = 300;
}

void Entity::render() {
    SDL_RenderCopy(App::renderer, texture, NULL, NULL);
}