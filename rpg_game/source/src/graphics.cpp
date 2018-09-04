#include "graphics.hpp"


Graphics::Graphics( std::string windowTitle )
{
	m_backBuffer = nullptr;
	m_initialised = init( windowTitle );
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(m_mainWindow);
	SDL_Quit();
}

bool Graphics::init( std::string windowTitle )
{
	if( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		std::cout << "SDL Initialisation Error: " << SDL_GetError() << std::endl;
		return false;
	}

	// Create the window.
	m_mainWindow = SDL_CreateWindow(
				windowTitle.c_str(),
				SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED,
				SCREEN_WIDTH,
				SCREEN_HEIGHT,
				SDL_WINDOW_SHOWN
				);

	if ( m_mainWindow == nullptr )
	{
		std::cout << "Window Creation Error: " << SDL_GetError() << std::endl;
		return false;
	}

	m_backBuffer = SDL_GetWindowSurface(m_mainWindow);

	return true;
}


Graphics* Graphics::getInstance()
{
	return m_instance;
}


void Graphics::render()
{
	SDL_UpdateWindowSurface(m_mainWindow);
}
