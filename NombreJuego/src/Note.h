#pragma once
#include "GameObject.h"

class Game;

enum class TypeNote {
	GREEN = 0,
	RED = 1,
	YELLOW = 2,
	BLUE = 3,
	ORANGE = 4
};

class Note : public GameObject
{
public:
	Note(TypeNote typeNote, float startTime, float endTime, int powerUp, Game* game);
	~Note();
	float GetStartTime();
	float GetEndTime();
	bool SetStartTime(float newTime);
	bool SetEndTime(float newTime);
	bool GetCanBeDestroy();
	void SetCanBeDestroy(bool newState);
	int GetPowerUp() { return this->powerUp; }
	sf::Sprite* GetSpriteNote();
	void Update(float deltaTime) override;
	void Draw(sf::RenderWindow& window) override;


private:
	float startTime;
	float endTime;
	float positionInX;
	float velocity;
	int powerUp;
	bool canBeDestroy;
	Game* game;
	sf::Sprite* noteImage;
	TypeNote typeNote;
	
	bool SetTypeNote(TypeNote newTypeNote);
};

