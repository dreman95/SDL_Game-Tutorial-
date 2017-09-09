#include <iostream>
#include "Game.h"
#include <Windows.h>



//our Game object
Game* g_game = nullptr;


int main(int argc, char* args[])
{
	
	
	g_game = new Game();

	g_game->init("Chapter 1", 100, 100, 480, 640, false);

	while (g_game->running())
	{
		
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	
	
	}
	
	

	return 0;
}

