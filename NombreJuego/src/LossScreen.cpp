#include "LossScreen.h"
#include "Game.h"
#include "ResourceManager.h"
#include "GameScreen.h"
#include "Player.h"

LossScreen::LossScreen(Game* game)
{
    this->gameInstance = game;
    
    this->selectedOption = 0;

    this->title = new sf::Text();
    this->font = this->gameInstance->GetResourceManager()->GetFont();
    this->title->setFont(*font);
    this->title->setFillColor(sf::Color::White);
    this->title->setString("You loss");
    this->title->setCharacterSize(30);
    this->title->setOrigin(50, 50);
    this->title->setPosition(this->gameInstance->GetRenderWindow().getSize().x / 2, this->gameInstance->GetRenderWindow().getSize().y / 2);

    this->menuOptions.push_back(new sf::Text());
    this->menuOptions[0]->setFont(*font);
    this->menuOptions[0]->setFillColor(sf::Color::White);
    this->menuOptions[0]->setString("Restart");
    this->menuOptions[0]->setCharacterSize(30);
    this->menuOptions[0]->setOrigin(50, 50);
    this->menuOptions[0]->setPosition( (this->gameInstance->GetRenderWindow().getSize().x / 2 ), ( this->gameInstance->GetRenderWindow().getSize().y / 2) + 50);

    this->menuOptions.push_back(new sf::Text());
    this->menuOptions[1]->setFont(*font);
    this->menuOptions[1]->setFillColor(sf::Color::White);
    this->menuOptions[1]->setString("Back to menu");
    this->menuOptions[1]->setCharacterSize(30);
    this->menuOptions[1]->setOrigin(50, 50);
    this->menuOptions[1]->setPosition( (this->gameInstance->GetRenderWindow().getSize().x / 2), (this->gameInstance->GetRenderWindow().getSize().y / 2) + 100);
   
}

TypeScreen LossScreen::ProcessInput(sf::Event event)
{
    return Screens::ProcessInput(event);
}

void LossScreen::Draw(sf::RenderWindow& window)
{
    Screens::Draw(window);
    window.draw(*this->title);
}

void LossScreen::Update(float deltaTime)
{
    Screens::Update(deltaTime);
}

TypeScreen LossScreen::SelectOption()
{
    if(selectedOption == 0)
    { 
        this->gameInstance->GetGameScreen()->Restart();
        this->gameInstance->GetGameScreen()->GetPlayer()->DeathThreadDoblePoints();
    }
    else if (selectedOption == 1)
    {
        this->gameInstance->GetGameScreen()->DeathThread();
        this->gameInstance->GetGameScreen()->GetPlayer()->DeathThreadDoblePoints();
        this->gameInstance->GetCurrentSong()->GetPreviewSound()->play();
        return TypeScreen::MainMenu;
    }
    return TypeScreen::None;
}
