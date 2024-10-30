#include "Screens.h"

Screens::Screens()
{
	this->selectedOption = 0;
}

void Screens::MoveUp()
{
	if (this->selectedOption > 0)
	{
		this->menuOptions[this->selectedOption]->setFillColor(sf::Color::White);
		this->selectedOption--;
		this->menuOptions[this->selectedOption]->setFillColor(sf::Color::Red);
	}
}

void Screens::MoveDown()
{
	if (this->selectedOption < this->menuOptions.size() - 1)
	{
		this->menuOptions[this->selectedOption]->setFillColor(sf::Color::White);
		this->selectedOption++;
		this->menuOptions[this->selectedOption]->setFillColor(sf::Color::Red);
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


