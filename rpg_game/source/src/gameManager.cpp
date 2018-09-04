#include "gameManager.hpp"

GameManager::GameManager( Graphics* graphicsInstance  )
{
	m_quit = false;

	if (!graphicsInstance)
		m_quit = true;

	m_graphicsInstance = graphicsInstance;
};

GameManager::~GameManager()
{
	delete m_gameManagerInstance;
	m_gameManagerInstance = nullptr;
};

GameManager* GameManager::getInstance()
{
	return m_gameManagerInstance;
}

void GameManager::run( )
{
	while ( !m_quit )
	{
		while( SDL_PollEvent(&m_events) != 0 )
		{
			switch ( m_events.type )
			{
			case SDL_QUIT:
				m_quit = true;
			}

			m_graphicsInstance->render();
		}
	}
}
