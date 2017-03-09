#include "Game.h"

#define MS_PER_UPDATE 10.0

Game::Game()
 : m_window(sf::VideoMode(800, 600, 32), "Joint Project Team E", sf::Style::Default)
 {
	
}

void Game::run()
 {
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	sf::Clock clock;
	timeSinceLastUpdate = clock.restart();

	LevelLoader::load(m_level);
	std::cout << m_level.m_playerData.position.x << ", " << m_level.m_playerData.position.y << std::endl;
	
		while (m_window.isOpen())
		{
		processEvents();
		
		timeSinceLastUpdate += clock.restart();
	    if (timeSinceLastUpdate > timePerFrame)
		{
			update(timeSinceLastUpdate.asMilliseconds());
			timeSinceLastUpdate = sf::Time::Zero;
		}
		
			render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		processGameEvents(event);
	}
}

void Game::processGameEvents(sf::Event& event)
 {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		m_window.close();
	}
}

void Game::update(double dt)
{
	switch (currentGameState)
	{
	case GameState::Play:
		break;
	default:
		break;
	}
}

void Game::render()
{
	m_window.clear(sf::Color(0, 0, 0, 0));
	switch (currentGameState)
	{
	case GameState::Play:
		break;
	default:
		break;
	}
	m_window.display();
}