#include "LoadingScreen.h"
#include "Game.h"
#include "ResourceManager.h"

LoadingScreen::LoadingScreen(Game* gameInstance)
{
    this->gameInstance = gameInstance;
    this->loadTime = 0.0f;
    this->dotCount = 0;

    
    font = this->gameInstance->GetResourceManager()->GetFont();
    this->myText = new sf::Text();
    this->myText->setFont(*font);
    this->myText->setFillColor(sf::Color::White);
    this->myText->setString("Loading");
    sf::Vector2u windowSize = gameInstance->GetRenderWindow().getSize();
    sf::FloatRect textRect = this->myText->getLocalBounds();
    this->myText->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    this->myText->setPosition(windowSize.x / 2.0f, windowSize.y / 2.0f);

    this->mySpinner = new sf::CircleShape(10);
    this->mySpinner->setFillColor(sf::Color::Transparent);
    this->mySpinner->setOutlineThickness(5);
    this->mySpinner->setOutlineColor(sf::Color::White);
    this->mySpinner->setOrigin(50, 50);
    float marginLeft = 740.0f;
    float marginTop = 580.0f;
    this->mySpinner->setPosition(marginLeft + this->mySpinner->getRadius(), marginTop + this->mySpinner->getRadius());

}

LoadingScreen::~LoadingScreen()
{
    if (this->mySpinner != nullptr)
    {
        delete this->mySpinner;
        this->mySpinner = nullptr;
    }

    if (this->myText != nullptr)
    {
        delete this->myText;
        this->myText = nullptr;
    }
}

void LoadingScreen::Draw(sf::RenderWindow& window)
{
    window.draw(*this->mySpinner);
    window.draw(*this->myText);
}

void LoadingScreen::Update(float deltaTime)
{
    this->mySpinner->rotate(deltaTime);
    this->ModifyText(deltaTime);

}

TypeScreen LoadingScreen::SelectOption()
{
    return TypeScreen::None;
}

void LoadingScreen::ModifyText(float deltaTime)
{
    this->loadTime += deltaTime;
    if (this->loadTime >= 0.5f)
    {
        dotCount = (dotCount + 1) % 4;
        std::string loadingText = "Loading";
        for (int i = 0; i < dotCount; i++)
        {
            loadingText += ".";
        }
        this->myText->setString(loadingText);
        this->loadTime = 0;
    }
}
