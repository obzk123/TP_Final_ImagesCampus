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
	sf::FloatRect textRect;


	this->subBackground = new sf::Sprite();
	this->subBackground->setTexture(*this->gameInstance->GetResourceManager()->GetTextureLabelB());
	this->subBackground->setOrigin(this->subBackground->getTexture()->getSize().x / 2, this->subBackground->getTexture()->getSize().y / 2);
	this->subBackground->setScale(0.2f, 0.2f);
	this->subBackground->setPosition(this->sizeX / 2, this->sizeY / 2);

	this->title = new sf::Text();
	this->title->setFont(*this->font);
	this->title->setFillColor(sf::Color::White);
	this->title->setString("Congratulations");
	this->title->setCharacterSize(32);
	textRect = this->title->getGlobalBounds();
	this->title->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	this->title->setPosition(this->sizeX / 2, this->sizeY * 0.30f);

	this->scoreText = new sf::Text();
	this->scoreText->setFont(*this->font);
	this->scoreText->setFillColor(sf::Color::White);
	this->scoreText->setString("Total score: " + std::to_string(this->player->GetScore()));
	this->scoreText->setCharacterSize(30);
	textRect = this->scoreText->getGlobalBounds();
	this->scoreText->setOrigin(0, textRect.top + textRect.height / 2.0f);
	this->scoreText->setPosition(this->sizeX * 0.38f, this->sizeY * 0.36f);

	this->hitNotes = new sf::Text();
	this->hitNotes->setFont(*this->font);
	this->hitNotes->setFillColor(sf::Color::White);
	this->hitNotes->setString("Hit notes: " + std::to_string(this->player->GetHitNotes()));
	this->hitNotes->setCharacterSize(30);
	textRect = this->hitNotes->getGlobalBounds();
	this->hitNotes->setOrigin(0, textRect.top + textRect.height / 2.0f);
	this->hitNotes->setPosition(this->sizeX * 0.38f, this->sizeY * 0.41f);

	this->missNotes = new sf::Text();
	this->missNotes->setFont(*this->font);
	this->missNotes->setFillColor(sf::Color::White);
	this->missNotes->setString("Miss notes: " + std::to_string(this->player->GetMissNotes()));
	this->missNotes->setCharacterSize(30);
	textRect = this->missNotes->getGlobalBounds();
	this->missNotes->setOrigin(0, textRect.top + textRect.height / 2.0f);
	this->missNotes->setPosition(this->sizeX * 0.38f, this->sizeY * 0.47f);

	this->failNotes = new sf::Text();
	this->failNotes->setFont(*this->font);
	this->failNotes->setFillColor(sf::Color::White);
	this->failNotes->setString("Fail notes: " + std::to_string(this->player->GetFailNotes()));
	this->failNotes->setCharacterSize(30);
	textRect = this->failNotes->getGlobalBounds();
	this->failNotes->setOrigin(0, textRect.top + textRect.height / 2.0f);
	this->failNotes->setPosition(this->sizeX * 0.38f, this->sizeY * 0.52f);

	this->menuOptions.push_back(new sf::Text());
	this->menuOptions[0]->setFont(*this->font);
	this->menuOptions[0]->setFillColor(sf::Color::White);
	this->menuOptions[0]->setString("Restart");
	this->menuOptions[0]->setCharacterSize(24);
	textRect = this->menuOptions[0]->getGlobalBounds();
	this->menuOptions[0]->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	this->menuOptions[0]->setPosition(this->sizeX / 2, this->sizeY * 0.62f);

	this->menuOptions.push_back(new sf::Text());
	this->menuOptions[1]->setFont(*this->font);
	this->menuOptions[1]->setFillColor(sf::Color::White);
	this->menuOptions[1]->setString("Back to menu");
	this->menuOptions[1]->setCharacterSize(24);
	textRect = this->menuOptions[1]->getGlobalBounds();
	this->menuOptions[1]->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	this->menuOptions[1]->setPosition(this->sizeX / 2, this->sizeY * 0.72f);

	labels.push_back(new sf::Sprite());
	labels[0]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureLabelA());
	labels[0]->setScale(0.05f, 0.05f);
	labels[0]->setOrigin(this->labels[0]->getTexture()->getSize().x / 2, this->labels[0]->getTexture()->getSize().y / 2);
	labels[0]->setPosition(this->sizeX / 2, this->sizeY * 0.62f);

	labels.push_back(new sf::Sprite());
	labels[1]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureLabelA());
	labels[1]->setScale(0.05f, 0.05f);
	labels[1]->setOrigin(this->labels[1]->getTexture()->getSize().x / 2, this->labels[1]->getTexture()->getSize().y / 2);
	labels[1]->setPosition(this->sizeX / 2, this->sizeY * 0.72f);

}

TypeScreen WinScreen::ProcessInput(sf::Event event)
{
	return Screens::ProcessInput(event);
}

void WinScreen::Draw(sf::RenderWindow& window)
{
	window.draw(*this->subBackground);
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
		this->gameInstance->GetGameScreen()->GetPublicAngrySound()->stop();
		this->gameInstance->GetGameScreen()->GetPublicHappySound()->stop();
		this->gameInstance->GetCurrentSong()->GetPreviewSound()->play();
		return TypeScreen::MainMenu;
	}
	return TypeScreen::None;
}
