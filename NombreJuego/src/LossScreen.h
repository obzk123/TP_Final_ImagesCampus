#pragma once
#include "Screens.h"

class Game;

class LossScreen : public Screens
{
public:
	LossScreen(Game* game);
	TypeScreen ProcessInput(sf::Event event) override;
	void Draw(sf::RenderWindow& window) override;
	void Update(float deltaTime) override;

	
private:
	TypeScreen SelectOption() override;
	sf::Text* title;
};

