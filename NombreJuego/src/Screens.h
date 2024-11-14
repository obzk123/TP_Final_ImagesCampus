#pragma once

#include "GameObject.h"
#include "EnumScreen.h"

class Game;

class Screens : public GameObject
{
public:
	virtual TypeScreen ProcessInput(sf::Event event);
	virtual void Draw(sf::RenderWindow &window) override;
	virtual void Update(float deltaTime) override;
	//~Screens();

protected:
	Screens();
	virtual void MoveUp();
	virtual void MoveDown();
	virtual TypeScreen SelectOption() = 0;
	std::vector<sf::Text*> menuOptions;
	int selectedOption;
	Game* gameInstance;
	sf::Font* font;
	std::vector<sf::Sprite*> labels;
	sf::SoundBuffer* BufferMenuUp;
	sf::SoundBuffer* BufferMenuDown;
	sf::Sound* SoundMenuUp;
	sf::Sound* SoundMenuDown;
};

