#pragma once

#include <SDL.h>
#include <iostream>

class Graphics {

public:

	Graphics( std::string windowTitle );
	~Graphics();

	static const int SCREEN_WIDTH = 1280;
	static const int SCREEN_HEIGHT = 720;

	Graphics* getInstance();

	void render();


private:

	bool init( std::string windowTitle );

	Graphics* m_instance;
	bool m_initialised;

	SDL_Window* m_mainWindow;
	SDL_Surface* m_backBuffer;
};
