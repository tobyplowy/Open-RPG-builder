#pragma once

#include "graphics.hpp"

class GameManager {

public:
	GameManager( Graphics* graphicsInstance );
	~GameManager();

	void run();

	GameManager* getInstance();

private:
	GameManager* m_gameManagerInstance;
	Graphics* m_graphicsInstance;

	bool m_quit;

	SDL_Event m_events;

};
