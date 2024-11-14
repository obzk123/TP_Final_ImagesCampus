#pragma once

#include "Screens.h"

enum class MenuOption
{
	None = 0,
	Play = 1,
	Config = 2,
	Exit = 3
};

class MainMenu : public Screens
{
public:
	MainMenu(Game* gameInstance);
	~MainMenu();
	TypeScreen SelectOption() override;
	void Draw(sf::RenderWindow& window) override;
	TypeScreen ProcessInput(sf::Event event) override;
private:
	sf::RectangleShape* background;
	sf::Text* title;
	sf::Text* createdBy;
	sf::Sprite* git;
	sf::Sprite* linkedin;
	sf::Sprite* KeyUp;
	sf::Sprite* KeyDown;
	sf::Text* explain;
};

