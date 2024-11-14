#include "ConfigMenu.h"
#include "Game.h"
#include "ResourceManager.h"

ConfigMenu::ConfigMenu(Game* gameInstance)
{
	this->gameInstance = gameInstance;
	font = this->gameInstance->GetResourceManager()->GetFont();

	x = this->gameInstance->GetRenderWindow().getSize().x;
	y = this->gameInstance->GetRenderWindow().getSize().y;
	sf::FloatRect textRect;

	this->volume = this->gameInstance->GetCurrentSong()->GetPreviewSound()->getVolume();
	this->volume_2 = this->gameInstance->volumeFx;

	this->background = new sf::RectangleShape();
	this->background->setFillColor(sf::Color(21, 28, 28));
	this->background->setSize(sf::Vector2f(x, y));
	this->background->setPosition(0, 0);

	this->title = new sf::Text();
	this->title->setFont(*font);
	this->title->setCharacterSize(50);
	this->title->setString("Settings");
	textRect = this->title->getLocalBounds();
	this->title->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	this->title->setPosition(x / 2.0f, y * 0.25f);
	this->title->setFillColor(sf::Color::White);
	

	menuOptions.push_back(new sf::Text());
	menuOptions[0]->setFont(*font);
	menuOptions[0]->setFillColor(sf::Color::White);
	menuOptions[0]->setString("Sound");
	textRect = this->menuOptions[0]->getLocalBounds();
	this->menuOptions[0]->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	menuOptions[0]->setPosition(x / 2, y * 0.40f);

	menuOptions.push_back(new sf::Text());
	menuOptions.push_back(new sf::Text());

	labels.push_back(new sf::Sprite());
	labels[0]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureLabelA());
	labels[0]->setScale(0.05f, 0.05f);
	labels[0]->setOrigin(labels[0]->getTexture()->getSize().x / 2, labels[0]->getTexture()->getSize().y / 2);
	labels[0]->setPosition(x / 2, y * 0.40f);


	this->volumeBar = new sf::RectangleShape(sf::Vector2f(220, 10));
	this->volumeBar->setFillColor(sf::Color::White);
	this->volumeBar->setOrigin(this->volumeBar->getSize().x / 2, this->volumeBar->getSize().y / 2);
	this->volumeBar->setPosition(x / 2, y  * 0.50f);

	this->volumeSlide = new sf::CircleShape(10);
	this->volumeSlide->setFillColor(sf::Color::Red);
	textRect = this->volumeSlide->getGlobalBounds();
	this->volumeSlide->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	this->volumeSlide->setPosition((this->x / 2 - 100) + this->volume * 2, y * 0.50f);

	this->volumeText = new sf::Text();
	this->volumeText->setFont(*font);
	this->volumeText->setCharacterSize(30);
	this->volumeText->setString(std::to_string(100));
	textRect = this->volumeText->getGlobalBounds();
	this->volumeText->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	this->volumeText->setPosition(x * 0.63f, y * 0.50f);

	this->volumeText->setFillColor(sf::Color::White);

	this->typeVolumeText = new sf::Text();
	this->typeVolumeText->setFont(*font);
	this->typeVolumeText->setCharacterSize(30);
	this->typeVolumeText->setString("Music");
	textRect = this->typeVolumeText->getGlobalBounds();
	this->typeVolumeText->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	this->typeVolumeText->setPosition(x * 0.35f, y * 0.50f);
	this->typeVolumeText->setFillColor(sf::Color::White);


	this->volumeBar_2 = new sf::RectangleShape(sf::Vector2f(220, 10));
	this->volumeBar_2->setFillColor(sf::Color::White);
	this->volumeBar_2->setOrigin(this->volumeBar_2->getSize().x / 2.0f, this->volumeBar_2->getSize().y / 2.0f);
	this->volumeBar_2->setPosition(x / 2, y * 0.60f);

	this->volumeSlide_2 = new sf::CircleShape(10);
	this->volumeSlide_2->setFillColor(sf::Color::Red);
	textRect = this->volumeSlide_2->getGlobalBounds();
	this->volumeSlide_2->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	this->volumeSlide_2->setPosition((this->x / 2 - 100) + this->volume_2 * 2, y * 0.60f);

	this->volumeText_2 = new sf::Text();
	this->volumeText_2->setFont(*font);
	this->volumeText_2->setCharacterSize(30);
	this->volumeText_2->setString(std::to_string(100));
	textRect = this->volumeText_2->getGlobalBounds();
	this->volumeText_2->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	this->volumeText_2->setPosition(x * 0.63f, y * 0.60f);
	this->volumeText_2->setFillColor(sf::Color::White);

	this->typeVolumeText_2 = new sf::Text();
	this->typeVolumeText_2->setFont(*font);
	this->typeVolumeText_2->setCharacterSize(30);
	this->typeVolumeText_2->setString("Fx");
	textRect = this->typeVolumeText_2->getGlobalBounds();
	this->typeVolumeText_2->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	this->typeVolumeText_2->setPosition(x * 0.35f, y * 0.60f);
	this->typeVolumeText_2->setFillColor(sf::Color::White);

	menuOptions.push_back(new sf::Text());
	menuOptions[3]->setFont(*font);
	menuOptions[3]->setFillColor(sf::Color::White);
	menuOptions[3]->setString("Back");
	textRect = this->menuOptions[3]->getLocalBounds();
	this->menuOptions[3]->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	menuOptions[3]->setPosition(x / 2, y * 0.70f);


	labels.push_back(new sf::Sprite());
	labels[1]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureLabelA());
	labels[1]->setScale(0.05f, 0.05f);
	labels[1]->setOrigin(labels[1]->getTexture()->getSize().x / 2, labels[1]->getTexture()->getSize().y / 2);
	labels[1]->setPosition(x / 2, y * 0.70f);

	this->KeyRight = new sf::Sprite();
	this->KeyRight->setTexture(*this->gameInstance->GetResourceManager()->GetTextureKeyRight());
	this->KeyRight->setOrigin(this->KeyRight->getTexture()->getSize().x / 2.0f, this->KeyRight->getTexture()->getSize().y / 2.0f);
	this->KeyRight->setPosition(x * 0.88f, y * 0.43f);

	this->KeyLeft = new sf::Sprite();
	this->KeyLeft->setTexture(*this->gameInstance->GetResourceManager()->GetTextureKeyLeft());
	this->KeyLeft->setOrigin(this->KeyLeft->getTexture()->getSize().x / 2.0f, this->KeyLeft->getTexture()->getSize().y / 2.0f);
	this->KeyLeft->setPosition(x * 0.83f, y * 0.43f);

	this->explain = new sf::Text();
	this->explain->setFont(*font);
	this->explain->setCharacterSize(14);
	this->explain->setFillColor(sf::Color::White);
	this->explain->setString("How to up and down volume");
	textRect = this->explain->getGlobalBounds();
	this->explain->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	this->explain->setPosition(x * 0.85f, y * 0.37f);
}

ConfigMenu::~ConfigMenu()
{

}

TypeScreen ConfigMenu::SelectOption()
{
	switch (selectedOption)
	{
	default:
		return TypeScreen::None;
		break;
	case 3:
		return TypeScreen::MainMenu;
		break;

	}
}

TypeScreen ConfigMenu::ProcessInput(sf::Event event)
{
	if (this->selectedOption == 1)
	{
		this->volumeSlide->setFillColor(sf::Color::Green);
		this->volumeSlide_2->setFillColor(sf::Color::Red);
	}
	else if (this->selectedOption == 2)
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
		if (this->selectedOption == 1 || this->selectedOption == 2)
		{
			if (event.key.code == sf::Keyboard::Right)
			{
				if (this->selectedOption == 1)
				{
					if (this->volume < 100)
					{
						this->volume++;
						this->gameInstance->GetCurrentSong()->GetSound()->setVolume(this->volume);
						this->gameInstance->GetCurrentSong()->GetPreviewSound()->setVolume(this->volume);
						this->volumeText->setString(std::to_string(this->volume));
						this->volumeSlide->setPosition(this->x / 2 + (volume * 2) - 100, this->y * 0.50f);
					}
				}

				if (this->selectedOption == 2)
				{
					if (this->volume_2 < 100)
					{
						this->volume_2++;
						this->gameInstance->volumeFx++;
						this->volumeText_2->setString(std::to_string(this->volume_2));
						this->volumeSlide_2->setPosition(this->x / 2 + (volume_2 * 2) - 100, this->y * 0.60f);
					}
				}
			}

			if (event.key.code == sf::Keyboard::Left)
			{
				if (this->selectedOption == 1)
				{
					if (this->volume > 0)
					{
						this->volume--;
						this->gameInstance->GetCurrentSong()->GetSound()->setVolume(this->volume);
						this->gameInstance->GetCurrentSong()->GetPreviewSound()->setVolume(this->volume);
						this->volumeText->setString(std::to_string(this->volume));
						this->volumeSlide->setPosition(this->x / 2 + (volume * 2) - 100, this->y * 0.50f);
					}
				}

				if (this->selectedOption == 2)
				{
					if (this->volume_2 > 0)
					{
						this->volume_2--;
						this->volumeText_2->setString(std::to_string(this->volume_2));
						this->gameInstance->volumeFx--;
						this->volumeSlide_2->setPosition(this->x / 2 + (volume_2 * 2) - 100, this->y * 0.60f);
					}
				}
			}
		}
	}
	return Screens::ProcessInput(event);
}

void ConfigMenu::Draw(sf::RenderWindow& window)
{
	window.draw(*this->background);
	window.draw(*this->title);
	window.draw(*this->volumeBar);
	window.draw(*this->volumeSlide);
	window.draw(*this->volumeText);
	window.draw(*this->typeVolumeText);
	window.draw(*this->volumeBar_2);
	window.draw(*this->volumeSlide_2);
	window.draw(*this->volumeText_2);
	window.draw(*this->typeVolumeText_2);
	window.draw(*this->KeyRight);
	window.draw(*this->KeyLeft);
	window.draw(*this->explain);
	Screens::Draw(window);
}
