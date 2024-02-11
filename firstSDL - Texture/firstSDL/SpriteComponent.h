#pragma once

#include "Components.h"
#include "ECS.h"

class SpriteComponent : public Component {
private:
    TransformComponent* transform;
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;

public:
    SpriteComponent(const char* path) {
        setTex(path);
    }

    void setTex(const char* path) {
        texture = TextureManager::LoadTexture(path);
    }

    void init() override {
        transform = &entity->getComponent<TransformComponent>();

        // Set the source rectangle to cover the entire texture
        SDL_QueryTexture(texture, NULL, NULL, &srcRect.w, &srcRect.h);

        destRect.w = srcRect.w;  // Destination rectangle size
        destRect.h = srcRect.h;
    }

    void update() override {
        destRect.x = static_cast<int>((int)transform->position.x);
        destRect.y = static_cast<int>((int)transform->position.y);
    }

    void draw() override {
        TextureManager::Draw(texture, srcRect, destRect);
    }
};
