#pragma once


#include "Components.h"
#include "Helper/Types/Vector2.h"

class TransformComponent : public Component
{
private:
	PhysicsComponent* physicsComponent;
public:
	Vector2 Position;

	int height = 60;
	int width = 64;
	int scale = 1;


	TransformComponent()
	{
		Position.x = 0;
		Position.y = 0;
	}

	TransformComponent(int x, int y)
	{
		Position.x = x;
		Position.y = y;
	}

	TransformComponent(int x, int y, int w, int h)
	{
		Position.x = x;
		Position.y = y;
		height = h;
		width = w;
	}


	void Init()override 
	{
		physicsComponent = &entity->getComponent<PhysicsComponent>();
	}


	void Update() override
	{
		if (physicsComponent) {
			b2Vec2 physicsVector2 = physicsComponent->Body->GetPosition();
			SetPosition(Vector2(physicsVector2.x, physicsVector2.y));
		}
	}



	void SetPosition(Vector2 input_vec)
	{
		Position.x = input_vec.x;
		Position.y = input_vec.y;
	}


};