#pragma once



#include "../Game.h"
#include "ECS.h"
#include "Components.h"




class BirdController : public Component
{
public:
	PhysicsComponent* physicsReference;


	void Init() override {
		physicsReference = &entity->getComponent<PhysicsComponent>();
	}

	void Update() override
	{

		if (GameState::Lost) return;
		physicsReference->Body->ApplyForceToCenter(b2Vec2(500, 0), true);
		MakeBirdJump();
	}







	void MakeBirdJump()
	{
		if (Game::event.type == SDL_EventType::SDL_KEYDOWN) {

			switch (Game::event.key.keysym.sym)
			{
			case SDLK_SPACE:
				if (physicsReference->Body->GetLinearVelocity().y > 0) {
					physicsReference->Body->ApplyLinearImpulseToCenter(b2Vec2(0, -1000000000), true);
				}
				break;

			default:
				break;
			}


		}
	}


};