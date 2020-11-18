#ifndef  Game_hpp
#define Game_hpp

#include "SDL.h"
#include "SDL_image.h"
#include "iostream";
#include "box2d.h"

class Game
{

public:
	static SDL_Renderer* Renderer;
	static SDL_Event event;
	static b2World* World;
	static SDL_Rect Camera;

	Game();
	~Game();

	void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void InitPhysics();
	void InitBasics(bool fullscreen, const char* title, int xpos, int ypos, int width, int height);
	void InitBird();
	void HandleEvents();
	void Update();
	void ControllCamera();
	void	GenerateObstacle(float posx, float posy, float sizex, float sizey);
	void Render();
	void Clean();
	bool Running() { return isRunning; }

private:

	bool isRunning;
	SDL_Window* window;


	int testCounter;

};

#endif