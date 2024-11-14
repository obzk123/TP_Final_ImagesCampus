#pragma once
#include "Screens.h"

class Game;
class Player;

class WinScreen : public Screens
{
public:
	WinScreen(Game* game, Player* player);
	TypeScreen ProcessInput(sf::Event event) override;
	void Draw(sf::RenderWindow& window) override;
	void Update(float deltaTime) override;

private:
	Player* player;
	TypeScreen SelectOption() override;
	sf::Text* title;
	sf::Text* hitNotes;
	sf::Text* missNotes;
	sf::Text* failNotes;
	sf::Text* scoreText;
	int sizeX;
	int sizeY;
	sf::Sprite* subBackground;
};

