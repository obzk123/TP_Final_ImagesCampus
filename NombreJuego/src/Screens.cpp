#include "Screens.h"

Screens::Screens()
{
	this->selectedOption = 0;

	this->BufferMenuUp = new sf::SoundBuffer();
	this->BufferMenuDown = new sf::SoundBuffer();

	this->SoundMenuUp = new sf::Sound();
	this->SoundMenuDown = new sf::Sound();

	this->BufferMenuUp->loadFromFile(CURRENT_PATH + SONG_PATH + BUFFER_MENU_UP);
	this->BufferMenuDown->loadFromFile(CURRENT_PATH + SONG_PATH + BUFFER_MENU_DOWN);

	this->SoundMenuUp->setBuffer(*this->BufferMenuUp);
	this->SoundMenuDown->setBuffer(*this->BufferMenuDown);
	this->SoundMenuUp->setVolume(100);
	this->SoundMenuDown->setVolume(100);
}

void Screens::MoveUp()
{
	if (this->selectedOption > 0)
	{
		this->menuOptions[this->selectedOption]->setFillColor(sf::Color::White);
		this->selectedOption--;
		this->menuOptions[this->selectedOption]->setFillColor(sf::Color::Red);
		this->SoundMenuUp->play();
	}
}

void Screens::MoveDown()
{
	if (this->selectedOption < this->menuOptions.size() - 1)
	{
		this->menuOptions[this->selectedOption]->setFillColor(sf::Color::White);
		this->selectedOption++;
		this->menuOptions[this->selectedOption]->setFillColor(sf::Color::Red);
		this->SoundMenuDown->play();
	}
}

TypeScreen Screens::ProcessInput(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Up)
		{
			this->MoveUp();
		}

		if (event.key.code == sf::Keyboard::Down)
		{
			this->MoveDown();
		}

		if (event.key.code == sf::Keyboard::Enter)
		{
			return SelectOption();
		}

	}
	return TypeScreen::None;
}


void Screens::Draw(sf::RenderWindow &window)
{
	for (int i = 0; i < labels.size(); i++)
	{
		window.draw(*labels[i]);
	}

	for (int i = 0; i < menuOptions.size(); i++)
	{
		window.draw(*menuOptions[i]);
	}
}

void Screens::Update(float deltaTime)
{

}

//Screens::~Screens()
//{
//}


