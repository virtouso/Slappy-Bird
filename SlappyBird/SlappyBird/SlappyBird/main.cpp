#include <SDL.h>
#include "Game.h"
#include "Helper/Static/GameReferences.h"
Game* game = nullptr;

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart = 0;
	int frameTime = 0;


	game = new Game();
	game->Init(GameReferences::GameName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, GameReferences::ScreenWidth, GameReferences::ScreenHeight, false);
	while (game->Running())
	{
		frameStart = SDL_GetTicks();
		game->HandleEvents();
		game->Update();
		game->Render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->Clean();

	return 0;
}