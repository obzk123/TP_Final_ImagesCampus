#include "LossScreen.h"
#include "Game.h"
#include "ResourceManager.h"
#include "GameScreen.h"
#include "Player.h"

LossScreen::LossScreen(Game* game)
{
    this->gameInstance = game;
    
    this->selectedOption = 0;

    int x = this->gameInstance->GetRenderWindow().getSize().x;
    int y = this->gameInstance->GetRenderWindow().getSize().y;

    this->subBackground = new sf::Sprite();
    this->subBackground->setTexture(*this->gameInstance->GetResourceManager()->GetTextureLabelB());
    this->subBackground->setScale(0.17f, 0.17f);
    this->subBackground->setPosition(x / 2 - 190, y / 2 - 200);

    this->title = new sf::Text();
    this->font = this->gameInstance->GetResourceManager()->GetFont();
    this->title->setFont(*font);
    this->title->setFillColor(sf::Color::White);
    this->title->setString("You loss");
    this->title->setCharacterSize(42);
    this->title->setOrigin(50, 50);
    this->title->setPosition(x / 2 - 75, y / 2 - 75);

    this->menuOptions.push_back(new sf::Text());
    this->menuOptions[0]->setFont(*font);
    this->menuOptions[0]->setFillColor(sf::Color::White);
    this->menuOptions[0]->setString("Restart");
    this->menuOptions[0]->setCharacterSize(24);
    this->menuOptions[0]->setOrigin(50, 50);
    this->menuOptions[0]->setPosition( x / 2, y / 2 + 35);

    this->menuOptions.push_back(new sf::Text());
    this->menuOptions[1]->setFont(*font);
    this->menuOptions[1]->setFillColor(sf::Color::White);
    this->menuOptions[1]->setString("Back to menu");
    this->menuOptions[1]->setCharacterSize(24);
    this->menuOptions[1]->setOrigin(50, 50);
    this->menuOptions[1]->setPosition( x / 2 - 50, y / 2 + 135);
   

    labels.push_back(new sf::Sprite());
    labels[0]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureLabelA());
    labels[0]->setScale(0.05f, 0.05f);
    labels[0]->setPosition(x / 2 - 145, y / 2 - 30);

    labels.push_back(new sf::Sprite());
    labels[1]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureLabelA());
    labels[1]->setScale(0.05f, 0.05f);
    labels[1]->setPosition(x / 2 - 145, y / 2 + 70);
}

TypeScreen LossScreen::ProcessInput(sf::Event event)
{
    return Screens::ProcessInput(event);
}

void LossScreen::Draw(sf::RenderWindow& window)
{
    window.draw(*this->subBackground);
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
        this->gameInstance->GetGameScreen()->GetPublicAngrySound()->stop();
        this->gameInstance->GetGameScreen()->GetPublicHappySound()->stop();
        this->gameInstance->GetCurrentSong()->GetPreviewSound()->play();
        return TypeScreen::MainMenu;
    }
    return TypeScreen::None;
}
