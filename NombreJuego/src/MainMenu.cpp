#include "MainMenu.h"
#include "Game.h"
#include "ResourceManager.h"

MainMenu::MainMenu(Game* game)
{
    gameInstance = game;
    font = this->gameInstance->GetResourceManager()->GetFont();

    menuOptions.push_back(new sf::Text());
    menuOptions[0]->setFont(*font);
    menuOptions[0]->setString("Jugar");
    menuOptions[0]->setPosition(100, 150);
    menuOptions[0]->setFillColor(sf::Color::Red);

    menuOptions.push_back(new sf::Text());
    menuOptions[1]->setFont(*font);
    menuOptions[1]->setString("Configurar");
    menuOptions[1]->setPosition(100, 250);
    menuOptions[1]->setFillColor(sf::Color::White);

    menuOptions.push_back(new sf::Text());
    menuOptions[2]->setFont(*font);
    menuOptions[2]->setString("Salir");
    menuOptions[2]->setPosition(100, 350);
    menuOptions[2]->setFillColor(sf::Color::White);

}

MainMenu::~MainMenu()
{

}


// Retorna la opción seleccionada
TypeScreen MainMenu::SelectOption() {
    switch (selectedOption) 
    {
    case 0:
        return TypeScreen::PlayMenu;
    case 1:
        return TypeScreen::ConfigMenu;
    case 2:
        return TypeScreen::Exit;
    case 3:
        return TypeScreen::None;
    }
}
