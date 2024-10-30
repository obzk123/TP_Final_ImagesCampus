#include "WinScreen.h"
#include "ResourceManager.h"
#include "Game.h"
#include "GameScreen.h"
#include "Player.h"

WinScreen::WinScreen(Game* game, Player* player)
{
	this->gameInstance = game;
	this->player = player;
	this->sizeX = this->gameInstance->GetRenderWindow().getSize().x;
	this->sizeY = this->gameInstance->GetRenderWindow().getSize().y;
	this->font = this->gameInstance->GetResourceManager()->GetFont();
	

	this->title = new sf::Text();
	this->title->setFont(*this->font);
	this->title->setFillColor(sf::Color::White);
	this->title->setString("Congratulations");
	this->title->setCharacterSize(30);
	this->title->setOrigin(10, 10);
	this->title->setPosition(300, 150);

	this->scoreText = new sf::Text();
	this->scoreText->setFont(*this->font);
	this->scoreText->setFillColor(sf::Color::White);
	this->scoreText->setOrigin(50, 50);
	this->scoreText->setString("Total score: " + std::to_string(this->player->GetScore()));
	this->scoreText->setCharacterSize(30);
	this->scoreText->setPosition(340, 250);

	this->hitNotes = new sf::Text();
	this->hitNotes->setFont(*this->font);
	this->hitNotes->setFillColor(sf::Color::White);
	this->hitNotes->setString("Hit notes: " + std::to_string(this->player->GetHitNotes()));
	this->hitNotes->setCharacterSize(30);
	this->hitNotes->setOrigin(50, 50);
	this->hitNotes->setPosition(340, 300);

	this->missNotes = new sf::Text();
	this->missNotes->setFont(*this->font);
	this->missNotes->setFillColor(sf::Color::White);
	this->missNotes->setOrigin(50, 50);
	this->missNotes->setString("Miss notes: " + std::to_string(this->player->GetMissNotes()));
	this->missNotes->setCharacterSize(30);
	this->missNotes->setPosition(340, 350);

	this->failNotes = new sf::Text();
	this->failNotes->setFont(*this->font);
	this->failNotes->setFillColor(sf::Color::White);
	this->failNotes->setOrigin(50, 50);
	this->failNotes->setString("Fail notes: " + std::to_string(this->player->GetFailNotes()));
	this->failNotes->setCharacterSize(30);
	this->failNotes->setPosition(340, 400);

	this->menuOptions.push_back(new sf::Text());
	this->menuOptions[0]->setFont(*this->font);
	this->menuOptions[0]->setFillColor(sf::Color::White);
	this->menuOptions[0]->setOrigin(50, 50);
	this->menuOptions[0]->setString("Restart");
	this->menuOptions[0]->setCharacterSize(30);
	this->menuOptions[0]->setPosition(400, 450);

	this->menuOptions.push_back(new sf::Text());
	this->menuOptions[1]->setFont(*this->font);
	this->menuOptions[1]->setFillColor(sf::Color::White);
	this->menuOptions[1]->setOrigin(50, 50);
	this->menuOptions[1]->setString("Back to menu");
	this->menuOptions[1]->setCharacterSize(30);
	this->menuOptions[1]->setPosition(370, 500);

}

TypeScreen WinScreen::ProcessInput(sf::Event event)
{
	return Screens::ProcessInput(event);
}

void WinScreen::Draw(sf::RenderWindow& window)
{
	Screens::Draw(window);
	window.draw(*this->title);
	window.draw(*this->scoreText);
	window.draw(*this->hitNotes);
	window.draw(*this->missNotes);
	window.draw(*this->failNotes);
}

void WinScreen::Update(float deltaTime)
{
	Screens::Update(deltaTime);

	this->scoreText->setString("Total score: " + std::to_string(this->player->GetScore()));
	this->hitNotes->setString("Hit notes: " + std::to_string(this->player->GetHitNotes()));
	this->missNotes->setString("Miss notes: " + std::to_string(this->player->GetMissNotes()));
	this->failNotes->setString("Fail notes: " + std::to_string(this->player->GetFailNotes()));
}

TypeScreen WinScreen::SelectOption()
{
	if (this->selectedOption == 0)
	{
		this->gameInstance->GetGameScreen()->Restart();
	}
	else if (this->selectedOption == 1)
	{
		this->gameInstance->GetGameScreen()->DeathThread();
		this->player->DeathThreadDoblePoints();
		this->gameInstance->GetCurrentSong()->GetPreviewSound()->play();
		return TypeScreen::MainMenu;
	}
	return TypeScreen::None;
}
