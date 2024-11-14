#pragma once

#include "Screens.h"

enum class ConfigOptions : int
{
	None = 0,
	Resolution = 1,
	Audio = 2,
	ScreenMode = 3,
	Back = 4
};

class ConfigMenu : public Screens
{
public:
	ConfigMenu(Game* gameInstance);
	~ConfigMenu();
	TypeScreen SelectOption() override;
	TypeScreen ProcessInput(sf::Event event) override;
	void Draw(sf::RenderWindow& window) override;
private:
	sf::RectangleShape* background;
	sf::Text* title;
	sf::RectangleShape* volumeBar;
	sf::CircleShape* volumeSlide;
	sf::Text* volumeText;
	sf::Text* typeVolumeText;
	sf::RectangleShape* volumeBar_2;
	sf::CircleShape* volumeSlide_2;
	sf::Text* volumeText_2;
	sf::Text* typeVolumeText_2;
	sf::Sprite* KeyLeft;
	sf::Sprite* KeyRight;
	sf::Text* explain;
	int volume;
	int volume_2;
	int x;
	int y;
};

