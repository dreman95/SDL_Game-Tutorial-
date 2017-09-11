#include "Game.h"
#include <iostream>


Game::Game()
{
}

Game::~Game()
{
	
}

bool Game::init(const char* title, int xpos, int ypos, int
	height, int width, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	// attempt to initialize SDL
if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
{
std::cout << "SDL init success\n";
// init the window
g_pWindow = SDL_CreateWindow(title, xpos, ypos,
width, height, flags);
if (g_pWindow != 0) // window init success
{
	std::cout << "window creation success\n";
	g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
	if (g_pRenderer != 0) // renderer init success
	{
		std::cout << "renderer creation success\n";
		SDL_SetRenderDrawColor(g_pRenderer,
			0, 0, 0, 0);
	}
	else
	{
		std::cout << "renderer init fail\n";
		return false; // renderer init fail
	}
}
else
{
	std::cout << "window init fail\n";
	return false; // window init fail
}
}
else
{
	std::cout << "SDL init fail\n";
	return false; // SDL init fail
}
std::cout << "init success\n";



m_running = true; // everything inited successfully, start the main loop

return true;
}

void Game::render()
{
	
	SDL_RenderClear(g_pRenderer);
	SDL_RenderCopy(g_pRenderer, m_texture, &m_sourceRectangle, &m_destinationRectangle);
	// show the window
	SDL_RenderPresent(g_pRenderer);
}

void Game::update()
{
	//Load texture
	SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/animate.bmp");

	m_texture = SDL_CreateTextureFromSurface(g_pRenderer, pTempSurface);

	SDL_FreeSurface(pTempSurface);

	//dimensions of the first image in sprite sheet.
	m_sourceRectangle.w = 128;
	m_sourceRectangle.h = 82;

	m_destinationRectangle.x = m_sourceRectangle.x = 0;
	m_destinationRectangle.y = m_sourceRectangle.y = 0;
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
}

void Game::handleEvents()
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_running = false;
			break;

		default:
			break;
		}
	}
}

void Game::clean()
{
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_Quit();
}

bool Game::running()
{
	return m_running;
}
