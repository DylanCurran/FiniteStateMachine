// author Dylan Curran
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "State.h"
#include "animation.h"
class Game
{
public:
	int currentState = 0; // This is for the switch statement to see what state the object
	float stateTimer = 0;
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();
	bool checkIdle = false;
private:
	Animation fsm;
	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setupSprite();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game

};

#endif // !GAME

