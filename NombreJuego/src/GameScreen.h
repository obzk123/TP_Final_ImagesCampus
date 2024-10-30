#pragma once

#include "Screens.h"

class Note;
class Player;
class CameraShake;
class PauseMenu;
class LoadingScreen;
class LossScreen;
class WinScreen;

enum class GameState 
{
	INIT = 0,
	PLAYING = 1,
	END = 2
};

class GameScreen : public Screens
{
public:
	GameScreen(Game* gameInstance);
	~GameScreen();
	TypeScreen SelectOption() override;
	TypeScreen ProcessInput(sf::Event event);
	void StartGame();
	void Draw(sf::RenderWindow& window) override;
	void Update(float deltaTime) override;
	void SetGameState(GameState newState);
	Player* GetPlayer();
	CameraShake* GetCameraShake();
	std::vector<sf::Sound*> GetBadSoundVector();
	bool GetIsPause();
	void ChangeIsPause();
	void Pause();
	void UnPause();
	void Restart();

	void BackCount();
	bool CheckLoss();
	void DeathThread();
	std::vector<Note*> notes;
	std::atomic<bool> isLoading;
	std::thread backCountThread;
	std::atomic<bool> finishThread;

private:
	
	float startTime;
	float time;
	int count;
	std::atomic<bool> isPause;
	bool startGame;
	bool loss;
	bool win;
	

	GameState gameState;
	PauseMenu* pauseMenu;
	LoadingScreen* loadingScreen;
	WinScreen* winScreen;
	LossScreen* lossScreen;
	std::vector<sf::Sprite*> buttons;
	sf::View defaultView;
	sf::View shakeView;

	sf::RectangleShape* background;
	sf::RectangleShape* track;
	sf::RectangleShape* track_2;
	sf::RectangleShape* leftLine;
	sf::RectangleShape* rigthLine;
	sf::RectangleShape* buttonLine;

	std::vector<sf::RectangleShape*> trastes;
	sf::Sprite* disc;
	sf::CircleShape* circleTime;
	sf::RectangleShape* lineTime;

	sf::Text* timeText;
	sf::Sprite* rockMeter;
	sf::Text* backCount;
	sf::Sound* sound;
	sf::Sound* publicHappySound;
	sf::Sound* publicAngrySound;
	std::vector<sf::Sound*> soundBadNotes;
	Player* player;
	CameraShake* cameraShake;
	

};

