#include "Game.h"
#include "MainMenu.h"
#include "LoadingScreen.h"
#include "ConfigMenu.h"
#include "PlayMenu.h"
#include "EnumScreen.h"
#include "GameScreen.h"
#include "Song.h"
#include "ResourceManager.h"
#include "CameraShake.h"
#include "Windows.h"
#include "GL/glu.h"

Game::Game() : window(sf::VideoMode(1280, 720), "Futuristic Hero", sf::Style::Default)
{
    this->window.setFramerateLimit(60);
    this->playMenu = nullptr;
    this->configMenu = nullptr;
    this->mainMenu = nullptr;
    this->gameScreen = nullptr;
    this->currentScreen = nullptr;

    // Carga el ícono
    sf::Image icon;
    if (!icon.loadFromFile("res/textures/icon.png")) {
        std::cerr << "No se pudo cargar el archivo del ícono." << std::endl;
    }
    // Establece el ícono de la ventana
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    this->resourcerManager = new ResourceManager(this);
    this->resourcerManager->LoadFont();
    this->loadingScreen = new LoadingScreen(this);
    this->currentScreen = this->loadingScreen;
    this->typeScreen = TypeScreen::LoadingScreen;
    this->currentSong = new Song(this);
    
    std::thread th([this]
        {
            this->GetResourceManager()->InitLoad();
            this->GetResourceManager()->LoadAllPartialSong(this->GetSongs());
            this->playMenu = new PlayMenu(this);
            this->configMenu = new ConfigMenu(this);
            this->mainMenu = new MainMenu(this);
            waitLoadSong = true;
        });
    th.detach();
}

Game::~Game()
{
    if (this->mainMenu != nullptr)
    {
        delete this->mainMenu;
        this->mainMenu = nullptr;
    }
    
    if (this->configMenu != nullptr)
    {
        delete this->configMenu;
        this->configMenu = nullptr;
    }
    
    if (this->loadingScreen != nullptr)
    {
        delete this->loadingScreen;
        this->loadingScreen = nullptr;
    }

    if (this->gameScreen != nullptr)
    {
        delete this->gameScreen;
        this->gameScreen = nullptr;
    }
        
    if (this->currentSong != nullptr)
    {
        delete this->currentSong;
        this->currentSong = nullptr;
    }
    
    if (this->playMenu != nullptr)
    {
        delete this->playMenu;
        this->playMenu = nullptr;
    }

    if (this->resourcerManager != nullptr)
    {
        delete this->resourcerManager;
        this->resourcerManager = nullptr;
    }
}

void Game::Run()
{
    bool firstTime = true;
	sf::Clock clock;
	while (window.isOpen())
	{

		float deltaTime = clock.restart().asSeconds();
        fps = 1.0f / deltaTime;
		this->Input();
		this->Update(deltaTime);
		this->Draw();
        
        if (this->waitLoadSong)
        {
            if (firstTime)
            {
                this->currentSong = this->Songs[0];
                this->currentSong->PlaySongPreview();
                firstTime = false;
                this->typeScreen = TypeScreen::MainMenu;
                this->ChangeScreen();
                this->waitLoadSong = false;
            }

        }
	}
}

std::vector<Song*>& Game::GetSongs()
{
    return this->Songs;
}

Song* Game::GetCurrentSong()
{
    return this->currentSong;
}

void Game::SetCurrentSong(Song* newSong)
{
    if (this->currentSong->IsPlayingPreview())
    {
        this->currentSong->RestartSongPreview();
    }
    this->currentSong = newSong;
}

sf::RenderWindow& Game::GetRenderWindow()
{
    return this->window;
}

void Game::loadGame()
{

}

ResourceManager* Game::GetResourceManager()
{
    return this->resourcerManager;
}

GameScreen* Game::GetGameScreen()
{
    return this->gameScreen;
}

void Game::Input()
{
    sf::Event event;
   
    while (this->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            this->window.close();
        }
        this->typeScreen = this->currentScreen->ProcessInput(event);
        this->ChangeScreen();
    }
}

void Game::Update(float deltaTime)
{
    if (this->currentScreen != this->gameScreen)
    {
        if (this->currentSong->GetPreviewSound()->getStatus() != sf::Sound::Playing)
        {
            this->currentSong->GetPreviewSound()->play();
        }
    }
    this->currentScreen->Update(deltaTime);
}

void Game::Draw() {

    this->window.clear();
    this->currentScreen->Draw(window);
    this->window.display();
}

void Game::ChangeScreen()
{
    switch (this->typeScreen)
    {
    case TypeScreen::None:
        break;
    case TypeScreen::MainMenu:
        this->currentScreen = this->mainMenu;
        break;
    case TypeScreen::PlayMenu:
        this->currentScreen = this->playMenu;
        break;
    case TypeScreen::ConfigMenu:
        this->currentScreen = this->configMenu;
        break;
    case TypeScreen::Game:

        if (this->gameScreen != nullptr)
        {
            if (this->gameScreen->GetCaptureMode())
            {
                this->gameScreen->SaveCaptureMode();
            }
            delete this->gameScreen;
            this->gameScreen = nullptr;
        }
        this->gameScreen = new GameScreen(this, this->volumeFx);
        this->currentScreen = this->gameScreen;
        break;
    case TypeScreen::Exit:
        this->window.close();
        break;
    }
}


