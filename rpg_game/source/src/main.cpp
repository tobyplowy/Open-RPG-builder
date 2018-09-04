#include "graphics.hpp"
#include "gameManager.hpp"

#include <iostream>

int main()
{
	Graphics* graphicsInstance = new Graphics("Yoyo");

	GameManager* gameManager = new GameManager( graphicsInstance );

	gameManager->run();
}
