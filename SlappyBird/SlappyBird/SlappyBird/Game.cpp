#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "ECS/Components.h"
#include "box2d.h"
#include"Helper/Static/Physics.h"
#include"Helper/Static/GameReferences.h"



SDL_Renderer* Game::Renderer = nullptr;



//GameObject* player;

Manager manager;
SDL_Event Game::event;
b2World* Game::World;
SDL_Rect Game::Camera = { 100,100,GameReferences::ScreenWidth,GameReferences::ScreenHeight };

auto& Bird(manager.AddEntity());
float NextObstaclePosition;
float BirdStartY;
Game::Game()
{
}

Game::~Game()
{
}

void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	InitBasics(fullscreen, title, xpos, ypos, width, height);
	InitPhysics();
	InitBird();
}





void Game::HandleEvents()
{
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}

}




void Game::Update()
{


	manager.Refresh();
	manager.Update();

	ControllCamera();

	if (Bird.getComponent<TransformComponent>().Position.x > NextObstaclePosition) {

		NextObstaclePosition = NextObstaclePosition + GameReferences::NextDistance;
		Game::GenerateObstacle(NextObstaclePosition, BirdStartY + (GameReferences::MinObstaclePossibleYPosition + (std::rand() % (GameReferences::MaxObstaclePossibleYPosition- (GameReferences::MinObstaclePossibleYPosition) + 1))), 64, 256);
	}

	World->Step(Physics::timeStep, Physics::velocityIterations, Physics::positionIterations);

}




void Game::Render()
{
	SDL_RenderClear(Renderer);

	manager.Draw();

	SDL_RenderPresent(Renderer);

}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(Renderer);
	SDL_Quit();
}


#pragma region Utility


void Game::InitBasics(bool fullscreen, const char* title, int xpos, int ypos, int width, int height)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "subsystem initialised..." << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "window created!" << std::endl;
		}
		Renderer = SDL_CreateRenderer(window, -1, 0);
		if (Renderer) {
			SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 100);


			std::cout << "Renderer Created..." << std::endl;
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}

}
void Game::InitPhysics()
{
	World = new b2World(b2Vec2(0, 10));
}


void Game::InitBird()
{
	Bird.AddComponent<PhysicsComponent>(0, 0, 1, 1, b2Vec2(32, 32), b2BodyType::b2_dynamicBody);
	Bird.AddComponent<TransformComponent>(0, 0, 64, 64);
	Bird.AddComponent<SpriteRendererComponent>("Assets/Sprite/Bird.png", SDL_RendererFlip::SDL_FLIP_NONE);
	Bird.AddComponent<BirdController>();
	NextObstaclePosition = Bird.getComponent<TransformComponent>().Position.x + GameReferences::NextDistance;
	BirdStartY = Bird.getComponent<TransformComponent>().Position.y;
	GenerateObstacle(NextObstaclePosition, BirdStartY + 100, 64, 256);
}



void Game::GenerateObstacle(float posx, float posy, float sizex, float sizey)
{

	auto& ObstacleDown(manager.AddEntity());
	ObstacleDown.AddComponent<PhysicsComponent>(posx, posy, 64, 128, b2Vec2(32, 128), b2BodyType::b2_staticBody);
	ObstacleDown.AddComponent<TransformComponent>(posx, posy, sizex, sizey);
	ObstacleDown.AddComponent<SpriteRendererComponent>("Assets/Sprite/Bar.png", SDL_RendererFlip::SDL_FLIP_NONE);

	auto& ObstacleUp(manager.AddEntity());
	ObstacleUp.AddComponent<PhysicsComponent>(posx, posy - 500, 64, 128, b2Vec2(32, 128), b2BodyType::b2_staticBody);
	ObstacleUp.AddComponent<TransformComponent>(posx, posy, sizex, sizey);
	ObstacleUp.AddComponent<SpriteRendererComponent>("Assets/Sprite/Bar.png", SDL_RendererFlip::SDL_FLIP_HORIZONTAL);

}


void Game::ControllCamera()
{
	Game::Camera.x = Bird.getComponent<TransformComponent>().Position.x - 400;
	Game::Camera.y = Bird.getComponent<TransformComponent>().Position.y - 300;
}






#pragma endregion
