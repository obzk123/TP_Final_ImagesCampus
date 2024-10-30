#include "ConfigMenu.h"
#include "Game.h"
#include "ResourceManager.h"

ConfigMenu::ConfigMenu(Game* gameInstance)
{
	this->gameInstance = gameInstance;

	font = this->gameInstance->GetResourceManager()->GetFont();
	menuOptions.push_back(new sf::Text());
	menuOptions[0]->setFont(*font);
	menuOptions[0]->setFillColor(sf::Color::Red);
	menuOptions[0]->setString("Resolution");
	menuOptions[0]->setPosition(100, 150);

	menuOptions.push_back(new sf::Text());
	menuOptions[1]->setFont(*font);
	menuOptions[1]->setFillColor(sf::Color::White);
	menuOptions[1]->setString("Screen Mode");
	menuOptions[1]->setPosition(100, 250);

	menuOptions.push_back(new sf::Text());
	menuOptions[2]->setFont(*font);
	menuOptions[2]->setFillColor(sf::Color::White);
	menuOptions[2]->setString("Audio");
	menuOptions[2]->setPosition(100, 350);


	menuOptions.push_back(new sf::Text());
	menuOptions[3]->setFont(*font);
	menuOptions[3]->setFillColor(sf::Color::White);
	menuOptions[3]->setString("Back");
	menuOptions[3]->setPosition(100, 450);
}

ConfigMenu::~ConfigMenu()
{

}

TypeScreen ConfigMenu::SelectOption()
{
	switch (selectedOption)
	{
	case 0:
		return TypeScreen::Exit;
		break;
	case 1:
		return TypeScreen::Exit;
		break;
	case 2:
		return TypeScreen::Exit;
		break;
	case 3:
		return TypeScreen::MainMenu;
		break;
	case 4:
		return TypeScreen::MainMenu;
		break;
	}
}

TypeScreen ConfigMenu::ProcessInput(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
		{
			return TypeScreen::MainMenu;
		}
	}
	return Screens::ProcessInput(event);
}
