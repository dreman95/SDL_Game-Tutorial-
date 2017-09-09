#include <SDL.h>
#pragma once 



class Game
{
public:
	Game();
	~Game();
	
bool init(const char* title, int xpos, int ypos, int
		height, int width, bool fullscreen);
	void render();
	void update();
	void handleEvents();

	bool running();
	void clean();

	
private:
	bool m_running;
	SDL_Window* g_pWindow = nullptr;
	SDL_Renderer* g_pRenderer = nullptr;
	SDL_Texture* m_texture = nullptr;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;
};
