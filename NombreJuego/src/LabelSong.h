#pragma once

#include "GameObject.h"

class LabelSong : public GameObject
{
public:
	LabelSong();
	~LabelSong();
	sf::RectangleShape* labelBackground;
	sf::Text* title;
	sf::Text* subtitle;
	sf::Text* duracion;
	sf::Sprite* image;
	sf::Text* album;
	sf::Text* score;
};
