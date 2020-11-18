#pragma once


#include "box2d.h"
#include "Helper/Handlers/ContactListener.h"


class PhysicsComponent : public Component
{
private:

	b2BodyDef BodyDefinition;// Holds All Settings to RigidBody
	b2PolygonShape boxShape;
	b2FixtureDef boxFixtureDef;
	ContactListener contactListener;


public:
	b2Body* Body;


	PhysicsComponent() = delete;
	PhysicsComponent(float posx, float posy, float sizex, float sizey, b2Vec2 center, b2BodyType bodyType)
	{
		InitPhysics(bodyType, posx, posy, sizex, sizey, center);
	}






	void Init() override
	{


	}


	void Update() override
	{

	}


	void Draw() override
	{

	}


#pragma region Utility
	void InitPhysics(b2BodyType bodyType, float posx, float posy, float sizex, float sizey, b2Vec2& center)
	{
		BodyDefinition.type = bodyType;
		BodyDefinition.position.Set(posx, posy);
		BodyDefinition.gravityScale = 10;

		Body = Game::World->CreateBody(&BodyDefinition);
		boxShape.SetAsBox(sizex, sizey, center, 0);

		boxFixtureDef.shape = &boxShape;
		boxFixtureDef.density = 1;

		Body->CreateFixture(&boxFixtureDef);

		Game::World->SetContactListener(&contactListener);
	}



#pragma endregion

};

