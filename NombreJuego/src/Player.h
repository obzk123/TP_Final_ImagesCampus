#pragma once

#include "GameObject.h"

class Note;
class Game;
class CameraShake;

class Player : public GameObject
{
public:
	Player(std::vector<sf::Sprite*>& buttons, Game* game);
	~Player();
	void Draw(sf::RenderWindow& window) override;
	void Update(float DeltaTime) override;
	void Input(sf::Event event);
	void SetStrikeNotes(int newValue);
	void SetPublicScore(int newValue);
	int GetScore() { return this->score; }
	void SetScore(int value) { this->score = value; }
	int GetPublicScore() { return this->publicScore; }
	void AddScore(int value);
	void ResetPublicScore();
	void HitNote(int indexButton);
	void MissNote(int indexButton);
	void FailNote();

	void SetHitNotes(int value) { this->hitNotes = value; }
	void SetMissNotes(int value) { this->missNotes = value; }
	void SetFailNotes(int value) { this->failNotes = value; }
	void SetDoblePoints(bool value) { this->doblePoints = value; }
	void SetTimerDoblePoints(float value) { this->timerDoblePoints = value; }
	void SetDeathThreadDoblePoints(bool value) { this->deadThreadDoblePoints = value; }

	int GetHitNotes()  { return this->hitNotes;}
	int GetMissNotes() { return this->missNotes; }
	int GetFailNotes() { return this->failNotes; }
	bool GetDoblePoints() { return this->doblePoints; }
	bool GetDeathThreadDoblePoints() { return this->deadThreadDoblePoints; }
	float GetTimerDoblePoints() { return this->timerDoblePoints; }

	void ThreadDoblePoints();
	void DeathThreadDoblePoints();

private:
	int check;
	int score;
	int strikeNotes;
	int publicScore;
	bool isPressed;
	
	int hitNotes;
	int missNotes;
	int failNotes;
	char buffer[50];
	std::vector<sf::Sprite*> buttonsRef;
	std::thread doblePointsThread;
	std::atomic<float> timerDoblePoints;
	std::atomic<float> deltaTime;
	std::atomic<bool> doblePoints;
	std::atomic<bool> deadThreadDoblePoints;
	
	Game* gameInstance;
	sf::Text* strikeText;
	sf::Text* scoreText;
	sf::Font* font;
	sf::Sprite* arrowSprite;
	sf::Text* timerPoints;
	
	int CheckNote(sf::Sprite button);
};
