#pragma once

#include "Components.h"
#include "SDL.h"


class SpriteRendererComponent : public Component
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;



public:

	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

	SpriteRendererComponent() = default;

	SpriteRendererComponent(const char* path, SDL_RendererFlip flip)
	{
		texture = TextureManager::LoadTexture(path);
		spriteFlip = flip;
	}

	void Init() override
	{

		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = 0; srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
	}




	void Update() override 
	{
		
		destRect.x = static_cast<int>(transform->Position.x - Game::Camera.x);
		destRect.y = static_cast<int>(transform->Position.y - Game::Camera.y);
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;
	}


	void Draw() override 
	{
		TextureManager::Draw(texture, srcRect, destRect,spriteFlip);
	}
};