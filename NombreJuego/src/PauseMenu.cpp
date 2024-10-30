#include "PauseMenu.h"
#include "Game.h"
#include "ResourceManager.h"
#include "GameScreen.h"
#include "Player.h"

PauseMenu::PauseMenu(Game* game)
{
	gameInstance = game;
	this->sizeX = game->GetRenderWindow().getSize().x / 2;
	this->sizeY = game->GetRenderWindow().getSize().y / 2;

	this->selectedOption = 0;

	font = this->gameInstance->GetResourceManager()->GetFont();
	this->volume = this->gameInstance->GetCurrentSong()->GetSound()->getVolume();

	this->menuOptions.push_back(new sf::Text());
	this->menuOptions[0]->setFont(*font);
	this->menuOptions[0]->setString("Continue");
	this->menuOptions[0]->setOrigin(50, 50);
	this->menuOptions[0]->setPosition(sizeX, sizeY - 100);
	this->menuOptions[0]->setCharacterSize(30);
	this->menuOptions[0]->setFillColor(sf::Color::White);
		  
	this->menuOptions.push_back(new sf::Text());
	this->menuOptions[1]->setFont(*font);
	this->menuOptions[1]->setString("Sound");
	this->menuOptions[1]->setOrigin(50, 50);
	this->menuOptions[1]->setPosition(sizeX, sizeY);
	this->menuOptions[1]->setCharacterSize(30);
	this->menuOptions[1]->setFillColor(sf::Color::White);

	this->volumeBar = new sf::RectangleShape(sf::Vector2f(200, 10));
	this->volumeBar->setFillColor(sf::Color::White);
	this->volumeBar->setPosition(sizeX, sizeY + 30);

	this->volumeSlide = new sf::CircleShape(10);
	this->volumeSlide->setFillColor(sf::Color::Red);
	this->volumeSlide->setOrigin(10, 10);
	this->volumeSlide->setPosition(sizeX + (volume * 2), sizeY + 35);

	this->volumeText = new sf::Text();
	this->volumeText->setFont(*font);
	this->volumeText->setString(std::to_string(this->volume));
	this->volumeText->setOrigin(50, 50);
	this->volumeText->setPosition(sizeX + 50, sizeY + 35);
	this->volumeText->setCharacterSize(30);
	this->volumeText->setFillColor(sf::Color::White);

		  
	this->menuOptions.push_back(new sf::Text());
	this->menuOptions[2]->setFont(*font);
	this->menuOptions[2]->setString("Restart");
	this->menuOptions[2]->setOrigin(50, 50);
	this->menuOptions[2]->setPosition(sizeX, sizeY + 150);
	this->menuOptions[2]->setCharacterSize(30);
	this->menuOptions[2]->setFillColor(sf::Color::White);

	this->menuOptions.push_back(new sf::Text());
	this->menuOptions[3]->setFont(*font);
	this->menuOptions[3]->setString("Back to menu");
	this->menuOptions[3]->setOrigin(50, 50);
	this->menuOptions[3]->setPosition(sizeX, sizeY + 200);
	this->menuOptions[3]->setCharacterSize(30);
	this->menuOptions[3]->setFillColor(sf::Color::White);
}

PauseMenu::~PauseMenu()
{
}

TypeScreen PauseMenu::ProcessInput(sf::Event event)
{
	
	if (event.type == sf::Event::KeyPressed)
	{
		if (this->selectedOption == 1)
		{
			if (event.key.code == sf::Keyboard::Right)
			{
				if (this->volume < 100)
				{
					this->volume++;
					this->gameInstance->GetCurrentSong()->GetSound()->setVolume(this->volume);
					this->volumeText->setString(std::to_string(this->volume));
					this->volumeSlide->setPosition(this->sizeX + (volume * 2), this->sizeY + 35);
				}
			}

			if (event.key.code == sf::Keyboard::Left)
			{
				if (this->volume > 0)
				{
					this->volume--;
					this->gameInstance->GetCurrentSong()->GetSound()->setVolume(this->volume);
					this->volumeText->setString(std::to_string(this->volume));
					this->volumeSlide->setPosition(sizeX + (volume * 2), sizeY + 35);
				}
			}
		}
	}
	return Screens::ProcessInput(event);
}

void PauseMenu::Draw(sf::RenderWindow& window)
{
	Screens::Draw(window);
	window.draw(*this->volumeBar);
	window.draw(*this->volumeSlide);
	window.draw(*this->volumeText);
}

void PauseMenu::Update(float deltaTime)
{
	Screens::Update(deltaTime);
}

TypeScreen PauseMenu::SelectOption()
{
	if (this->selectedOption == 0)
	{
		this->gameInstance->GetGameScreen()->UnPause();
	}
	else if (this->selectedOption == 2)
	{
		this->gameInstance->GetGameScreen()->Restart();
	}
	else if (this->selectedOption == 3)
	{
		this->gameInstance->GetGameScreen()->DeathThread();
		this->gameInstance->GetGameScreen()->GetPlayer()->DeathThreadDoblePoints();
		this->gameInstance->GetCurrentSong()->GetPreviewSound()->play();
		return TypeScreen::MainMenu;
	}
	return TypeScreen::None;
}
