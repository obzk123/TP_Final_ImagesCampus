#pragma once

#include "GameObject.h"
#include "EnumScreen.h"
#include "Song.h"

class MainMenu;
class LoadingScreen;
class ConfigMenu;
class PauseMenu;
class PlayMenu;
class GameScreen;
class Screens;
class ResourceManager;
class CameraShake;

class Game
{
public:
	Game();
	~Game();
	void Run();

	std::vector<Song*>& GetSongs();
	Song* GetCurrentSong();
	void SetCurrentSong(Song* newSong);
	sf::RenderWindow& GetRenderWindow();
	void loadGame();
	ResourceManager* GetResourceManager();

	GameScreen* GetGameScreen();

private:
	void Input();
	void Update(float deltaTime);
	void Draw();

	sf::RenderWindow window;

	ResourceManager* resourcerManager;
	LoadingScreen* loadingScreen;
	Song* currentSong;
	PlayMenu* playMenu;
	ConfigMenu* configMenu;
	MainMenu* mainMenu;
	GameScreen* gameScreen;
	Screens* currentScreen;
	
	TypeScreen typeScreen;
	std::vector<Song*> Songs;
	float fps = 0;
	std::string songFolder;
	std::atomic<bool> waitLoadSong = false;
	void ChangeScreen();

	
};

