#pragma once

#include "Screens.h"


class Song;

class PlayMenu : public Screens
{
public:
	PlayMenu(Game* gameInstance);
	~PlayMenu();
	TypeScreen SelectOption() override;
	TypeScreen ProcessInput(sf::Event event) override;
	void Draw(sf::RenderWindow& window) override;
	void Update(float deltaTime) override;
	void MoveUp() override;
	void MoveDown() override;
	

private:
	int backNumber = 0;
	void PlaySound();
	std::vector<class LabelSong*> labelSongs;
};

