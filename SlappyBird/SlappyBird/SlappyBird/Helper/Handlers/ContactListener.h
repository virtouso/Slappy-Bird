#pragma once
#include "box2d.h"
#include "Game.h"
#include <iostream>
#include "Helper/Static/GameState.h"
class ContactListener :public b2ContactListener
{

	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
};