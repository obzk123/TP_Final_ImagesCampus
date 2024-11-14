#include "PauseMenu.h"
#include "Game.h"
#include "ResourceManager.h"
#include "GameScreen.h"
#include "Player.h"

PauseMenu::PauseMenu(Game* game)
{
	gameInstance = game;
	this->sizeX = game->GetRenderWindow().getSize().x;
	this->sizeY = game->GetRenderWindow().getSize().y;
	sf::FloatRect textureRect;
	this->selectedOption = 0;

	font = this->gameInstance->GetResourceManager()->GetFont();
	this->volume = this->gameInstance->GetCurrentSong()->GetSound()->getVolume();
	this->volume_2 = this->gameInstance->GetGameScreen()->GetPublicHappySound()->getVolume();

	this->subBackground = new sf::Sprite();
	this->subBackground->setTexture(*this->gameInstance->GetResourceManager()->GetTextureLabelB());
	this->subBackground->setScale(0.2f, 0.26f);
	this->subBackground->setOrigin(this->subBackground->getTexture()->getSize().x / 2.0f, this->subBackground->getTexture()->getSize().y / 2.0f);
	this->subBackground->setPosition(this->sizeX / 2, this->sizeY / 2);

	this->menuOptions.push_back(new sf::Text());
	this->menuOptions[0]->setFont(*font);
	this->menuOptions[0]->setString("Continue");
	textureRect = this->menuOptions[0]->getGlobalBounds();
	this->menuOptions[0]->setOrigin(textureRect.left + textureRect.width / 2.0f, textureRect.height + textureRect.top / 2.0f);
	this->menuOptions[0]->setPosition(this->sizeX * 0.52f, this->sizeY * 0.26f);
	this->menuOptions[0]->setCharacterSize(24);
	this->menuOptions[0]->setFillColor(sf::Color::White);

	labels.push_back(new sf::Sprite());
	labels[0]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureLabelA());
	labels[0]->setScale(0.05f, 0.05f);
	labels[0]->setOrigin(this->labels[0]->getTexture()->getSize().x / 2, this->labels[0]->getTexture()->getSize().y / 2);
	labels[0]->setPosition(this->sizeX / 2, this->sizeY * 0.25f);


	this->menuOptions.push_back(new sf::Text());
	this->menuOptions[1]->setFont(*font);
	this->menuOptions[1]->setString("Sound");
	textureRect = this->menuOptions[1]->getGlobalBounds();
	this->menuOptions[1]->setOrigin(textureRect.left + textureRect.width / 2.0f, textureRect.height + textureRect.top / 2.0f);
	this->menuOptions[1]->setPosition(this->sizeX * 0.51f, this->sizeY * 0.41f);
	this->menuOptions[1]->setCharacterSize(24);
	this->menuOptions[1]->setFillColor(sf::Color::White);

	labels.push_back(new sf::Sprite());
	labels[1]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureLabelA());
	labels[1]->setScale(0.05f, 0.05f);
	labels[1]->setOrigin(this->labels[1]->getTexture()->getSize().x / 2, this->labels[1]->getTexture()->getSize().y / 2);
	labels[1]->setPosition(this->sizeX / 2, this->sizeY * 0.40f);

	this->menuOptions.push_back(new sf::Text());
	this->menuOptions.push_back(new sf::Text());
	this->volumeBar = new sf::RectangleShape(sf::Vector2f(200, 10));
	this->volumeBar->setFillColor(sf::Color::White);
	textureRect = this->volumeBar->getGlobalBounds();
	this->volumeBar->setOrigin(textureRect.left + textureRect.width / 2.0f, textureRect.height + textureRect.top / 2.0f);
	this->volumeBar->setPosition(this->sizeX / 2, this->sizeY * 0.50f);

	this->volumeSlide = new sf::CircleShape(10);
	this->volumeSlide->setFillColor(sf::Color::Red);
	textureRect = this->volumeSlide->getGlobalBounds();
	this->volumeSlide->setOrigin(textureRect.left + textureRect.width / 2.0f, textureRect.height + textureRect.top / 2.0f);
	this->volumeSlide->setPosition( (this->sizeX / 2 - 100) + this->volume * 2, sizeY * 0.505f);

	this->volumeText = new sf::Text();
	this->volumeText->setFont(*font);
	this->volumeText->setString(std::to_string(this->volume));
	textureRect = this->volumeText->getGlobalBounds();
	this->volumeText->setOrigin(textureRect.left + textureRect.width / 2.0f, textureRect.height + textureRect.top / 2.0f);
	this->volumeText->setPosition(this->sizeX * 0.62f, sizeY * 0.50f);
	this->volumeText->setCharacterSize(24);
	this->volumeText->setFillColor(sf::Color::White);

	this->typeVolumeText = new sf::Text();
	this->typeVolumeText->setFont(*font);
	this->typeVolumeText->setString("Music");
	textureRect = this->typeVolumeText->getGlobalBounds();
	this->typeVolumeText->setOrigin(textureRect.left + textureRect.width / 2.0f, textureRect.height + textureRect.top / 2.0f);
	this->typeVolumeText->setPosition(this->sizeX * 0.40f, this->sizeY * 0.51f);
	this->typeVolumeText->setCharacterSize(16);
	this->typeVolumeText->setFillColor(sf::Color::White);


	this->volumeBar_2 = new sf::RectangleShape(sf::Vector2f(200, 10));
	this->volumeBar_2->setFillColor(sf::Color::White);
	textureRect = this->volumeBar_2->getGlobalBounds();
	this->volumeBar_2->setOrigin(textureRect.left + textureRect.width / 2.0f, textureRect.height + textureRect.top / 2.0f);
	this->volumeBar_2->setPosition(this->sizeX / 2, this->sizeY * 0.54f);

	this->volumeSlide_2 = new sf::CircleShape(10);
	this->volumeSlide_2->setFillColor(sf::Color::Red);
	textureRect = this->volumeSlide_2->getGlobalBounds();
	this->volumeSlide_2->setOrigin(textureRect.left + textureRect.width / 2.0f, textureRect.height + textureRect.top / 2.0f);
	this->volumeSlide_2->setPosition( (this->sizeX / 2 - 100) + this->volume_2 * 2, sizeY * 0.545f);

	this->volumeText_2 = new sf::Text();
	this->volumeText_2->setFont(*font);
	this->volumeText_2->setString(std::to_string(this->volume_2));
	textureRect = this->volumeText_2->getGlobalBounds();
	this->volumeText_2->setOrigin(textureRect.left + textureRect.width / 2.0f, textureRect.height + textureRect.top / 2.0f);
	this->volumeText_2->setPosition(this->sizeX * 0.62f, sizeY * 0.54f);
	this->volumeText_2->setCharacterSize(24);
	this->volumeText_2->setFillColor(sf::Color::White);

	this->typeVolumeText_2 = new sf::Text();
	this->typeVolumeText_2->setFont(*font);
	this->typeVolumeText_2->setString("Fx");
	textureRect = this->typeVolumeText_2->getGlobalBounds();
	this->typeVolumeText_2->setOrigin(textureRect.left + textureRect.width / 2.0f, textureRect.height + textureRect.top / 2.0f);
	this->typeVolumeText_2->setPosition(this->sizeX * 0.40f, this->sizeY * 0.55f);
	this->typeVolumeText_2->setCharacterSize(16);
	this->typeVolumeText_2->setFillColor(sf::Color::White);

	this->menuOptions.push_back(new sf::Text());
	this->menuOptions[4]->setFont(*font);
	this->menuOptions[4]->setString("Restart");
	textureRect = this->menuOptions[4]->getGlobalBounds();
	this->menuOptions[4]->setOrigin(textureRect.left + textureRect.width / 2.0f, textureRect.height + textureRect.top / 2.0f);
	this->menuOptions[4]->setPosition(this->sizeX * 0.52f, this->sizeY * 0.66f);
	this->menuOptions[4]->setCharacterSize(24);
	this->menuOptions[4]->setFillColor(sf::Color::White);

	labels.push_back(new sf::Sprite());
	labels[2]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureLabelA());
	labels[2]->setScale(0.05f, 0.05f);
	labels[2]->setOrigin(this->labels[2]->getTexture()->getSize().x / 2, this->labels[2]->getTexture()->getSize().y / 2);
	labels[2]->setPosition(this->sizeX / 2, this->sizeY * 0.65f);

	this->menuOptions.push_back(new sf::Text());
	this->menuOptions[5]->setFont(*font);
	this->menuOptions[5]->setString("Back to menu");
	textureRect = this->menuOptions[5]->getGlobalBounds();
	this->menuOptions[5]->setOrigin(textureRect.left + textureRect.width / 2.0f, textureRect.height + textureRect.top / 2.0f);
	this->menuOptions[5]->setPosition(this->sizeX * 0.53f, this->sizeY * 0.81f);
	this->menuOptions[5]->setCharacterSize(24);
	this->menuOptions[5]->setFillColor(sf::Color::White);


	labels.push_back(new sf::Sprite());
	labels[3]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureLabelA());
	labels[3]->setScale(0.05f, 0.05f);
	labels[3]->setOrigin(this->labels[3]->getTexture()->getSize().x / 2, this->labels[3]->getTexture()->getSize().y / 2);
	labels[3]->setPosition(this->sizeX / 2, sizeY * 0.80f);
}

PauseMenu::~PauseMenu()
{
}

TypeScreen PauseMenu::ProcessInput(sf::Event event)
{

	if (this->selectedOption == 2)
	{
		this->volumeSlide->setFillColor(sf::Color::Green);
		this->volumeSlide_2->setFillColor(sf::Color::Red);
	}
	else if (this->selectedOption == 3)
	{
		this->volumeSlide->setFillColor(sf::Color::Red);
		this->volumeSlide_2->setFillColor(sf::Color::Green);
	}
	else
	{
		this->volumeSlide->setFillColor(sf::Color::Red);
		this->volumeSlide_2->setFillColor(sf::Color::Red);
	}
	if (event.type == sf::Event::KeyPressed)
	{

		if (this->selectedOption == 2 || this->selectedOption == 3)
		{
			if (event.key.code == sf::Keyboard::Right)
			{
				if (this->selectedOption == 2)
				{
					if (this->volume < 100)
					{
						this->volume++;
						this->gameInstance->GetCurrentSong()->GetSound()->setVolume(this->volume);
						this->volumeText->setString(std::to_string(this->volume));
						this->volumeSlide->setPosition(this->sizeX / 2 + (volume * 2) - 100, this->sizeY * 0.505f);
					}
				}

				if (this->selectedOption == 3)
				{
					if (this->volume_2 < 100)
					{
						this->volume_2++;
						this->gameInstance->GetGameScreen()->GetPublicHappySound()->setVolume(this->volume_2);
						this->gameInstance->GetGameScreen()->GetPublicAngrySound()->setVolume(this->volume_2);
						this->volumeText_2->setString(std::to_string(this->volume_2));
						this->volumeSlide_2->setPosition(this->sizeX / 2 + (volume_2 * 2) - 100, this->sizeY * 0.545f);
					}
				}
			}

			if (event.key.code == sf::Keyboard::Left)
			{
				if (this->selectedOption == 2)
				{
					if (this->volume > 0)
					{
						this->volume--;
						this->gameInstance->GetCurrentSong()->GetSound()->setVolume(this->volume);
						this->volumeText->setString(std::to_string(this->volume));
						this->volumeSlide->setPosition(this->sizeX / 2 + (volume * 2) - 100, this->sizeY * 0.505f);
					}
				}

				if (this->selectedOption == 3)
				{
					if (this->volume_2 > 0)
					{
						this->volume_2--;
						this->gameInstance->GetGameScreen()->GetPublicHappySound()->setVolume(this->volume_2);
						this->gameInstance->GetGameScreen()->GetPublicAngrySound()->setVolume(this->volume_2);
						this->volumeText_2->setString(std::to_string(this->volume_2));
						this->volumeSlide_2->setPosition(this->sizeX / 2 + (volume_2 * 2) - 100, this->sizeY * 0.545f);
					}
				}
			}
		}
	}
	return Screens::ProcessInput(event);
}

void PauseMenu::Draw(sf::RenderWindow& window)
{
	window.draw(*this->subBackground);
	Screens::Draw(window);
	window.draw(*this->volumeBar);
	window.draw(*this->volumeSlide);
	window.draw(*this->volumeText);
	window.draw(*this->typeVolumeText);
	window.draw(*this->volumeBar_2);
	window.draw(*this->volumeSlide_2);
	window.draw(*this->volumeText_2);
	window.draw(*this->typeVolumeText_2);
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
	else if (this->selectedOption == 4)
	{
		this->gameInstance->GetGameScreen()->Restart();
	}
	else if (this->selectedOption == 5)
	{
		this->gameInstance->GetGameScreen()->DeathThread();
		this->gameInstance->GetGameScreen()->GetPlayer()->DeathThreadDoblePoints();
		this->gameInstance->GetGameScreen()->GetPublicAngrySound()->stop();
		this->gameInstance->GetGameScreen()->GetPublicHappySound()->stop();
		this->gameInstance->GetCurrentSong()->GetPreviewSound()->play();
		return TypeScreen::MainMenu;
	}
	return TypeScreen::None;
}
