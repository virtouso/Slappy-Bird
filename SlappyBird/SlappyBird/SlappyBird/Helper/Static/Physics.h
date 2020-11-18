#pragma once

#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "ECS/Components.h"
#include "box2d.h"
//#include <cfloat>



class Physics
{
public:
	static	float timeStep; //1/60.0;      //the length of time passed to simulate (seconds)
	static	int32 velocityIterations;   //how strongly to correct velocity
	static	int32 positionIterations;   //how strongly to correct position

};

