#include "Game.h"
int main()
{	
	//Init srand
	std::srand(static_cast<unsigned>(time(NULL)));


	//init game engine
	Game game;
	//Game loop

	while (game.running())
	{
	//Update
	game.update();


	
	

	//Draw your game

	//Render
	game.render();	//tell app that window is done drawing
	}
	//End of aplication
	return 0;
}