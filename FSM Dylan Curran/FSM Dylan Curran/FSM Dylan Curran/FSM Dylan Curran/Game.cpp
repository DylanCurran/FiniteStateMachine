// author Dylan Curran

#include "Game.h"
#include <iostream>



Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "SFML Game" },
	m_exitGame{false} //when true game will exit
{
	setupFontAndText(); // load font 
	setupSprite(); // load texture
}


Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if ( sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))	// jumping
			{
				currentState = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))	// hammering
			{
				currentState = 2;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))	//shielding
			{
				currentState = 3;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))	//Firing
			{
				currentState = 4;
			}

			
		}
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	
	if (m_exitGame)
	{
		m_window.close();
	}
	switch (currentState)
	{
	case 1:
		if (stateTimer < 2)
		{
			//std::cout << "Jumping" << std::endl;
			fsm.jumping();
			stateTimer += t_deltaTime.asSeconds();
		}
		else
		{
			currentState = 500;
			stateTimer = 0;
		}
		break;
	case 2:
		if (stateTimer < 0.5f)
		{
			fsm.hammering();
			stateTimer += t_deltaTime.asSeconds();
		}
		else
		{
			currentState = 500;
			stateTimer = 0;
		}
		break;
	case 3:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			fsm.shielding();
		}
		else
		{
			currentState = 500;
			stateTimer = 0;
		}
		break;
	case 4:
		if (stateTimer < 1.5f)
		{
			fsm.firing();
			stateTimer += t_deltaTime.asSeconds();
		}
		else
		{
			currentState = 500;
			stateTimer = 0;
		}
		break;
	default:
		fsm.idle();
		break;
	}
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	m_window.draw(m_welcomeMessage);
	
		m_window.draw(m_logoSprite);
	
	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_welcomeMessage.setFont(m_ArialBlackfont);
	m_welcomeMessage.setString("Press Space to Jump \n Hold S for Shield \n Press F to fire \n press H for hammering");
	m_welcomeMessage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	m_welcomeMessage.setPosition(40.0f, 40.0f);
	m_welcomeMessage.setCharacterSize(20);
	m_welcomeMessage.setOutlineColor(sf::Color::Red);
	m_welcomeMessage.setFillColor(sf::Color::Black);
	m_welcomeMessage.setOutlineThickness(3.0f);

}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	if (!m_logoTexture.loadFromFile("ASSETS\\IMAGES\\idleRein.jpg"))
	{
		// simple error message if previous call fails
		std::cout << "need idle rein" << std::endl;
	}
	
	m_logoSprite.setTexture(m_logoTexture);
	m_logoSprite.setPosition(300.0f, 180.0f);
}
