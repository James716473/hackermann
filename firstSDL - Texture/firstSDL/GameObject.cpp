#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, int x, int y) {

	objTexture = TextureManager::LoadTexture(textureSheet);
	xpos = x;
	ypos = y;

	// Get the dimensions of the loaded texture
	SDL_QueryTexture(objTexture, NULL, NULL, &srcR.w, &srcR.h);

	destR.x = xpos;
	destR.y = ypos;
	destR.w = srcR.w;
	destR.h = srcR.h;
}

void GameObject::update() {

	xpos++;
	ypos++;

	destR.x = xpos;
	destR.y = ypos;
}

void GameObject::render() {
	SDL_RenderCopy(Game::renderer, objTexture, NULL, &destR);
}
