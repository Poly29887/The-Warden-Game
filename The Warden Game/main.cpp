#include "stdafx.h"
#include "Game.h"

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	
	Game game;

	while (game.getwindow().isOpen())
	{
		game.update();
		game.render();
	}

	//end
	return 0;
}