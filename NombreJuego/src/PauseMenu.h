#pragma once

#include "Screens.h"

enum class PauseOption {
	None = 0,
	Continue = 1,
	Config = 2,
	ExitToMenu = 3
};

class PauseMenu : public Screens
{
public:
	PauseMenu(Game* gameInstance);
	~PauseMenu();
	TypeScreen ProcessInput(sf::Event event) override;
	void Draw(sf::RenderWindow& window) override;
	void Update(float deltaTime) override;
	TypeScreen SelectOption() override;
private:
	std::vector<sf::Text*> options;
	sf::RectangleShape* volumeBar;
	sf::CircleShape* volumeSlide;
	sf::Text* volumeText;
	sf::Text* typeVolumeText;

	sf::RectangleShape* volumeBar_2;
	sf::CircleShape* volumeSlide_2;
	sf::Text* volumeText_2;
	sf::Text* typeVolumeText_2;


	sf::Sprite* subBackground;
	int volume;
	int volume_2;
	int sizeX;
	int sizeY;
};

