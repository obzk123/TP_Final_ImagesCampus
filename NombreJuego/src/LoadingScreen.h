#pragma once

#include "Screens.h"

class LoadingScreen : public Screens
{
public:
	LoadingScreen(Game* gameInstance);
	~LoadingScreen();
	void Draw(sf::RenderWindow& window) override;
	void Update(float deltaTime) override;
	TypeScreen SelectOption() override;

private:
	
	float loadTime;
	int dotCount;
	sf::RectangleShape* background;
	sf::Sprite* mySpinner;
	sf::Text* myText;
	void ModifyText(float deltaTime);

};

