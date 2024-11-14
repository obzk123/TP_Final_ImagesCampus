#include "LoadingScreen.h"
#include "Game.h"
#include "ResourceManager.h"

LoadingScreen::LoadingScreen(Game* gameInstance)
{
    this->gameInstance = gameInstance;
    this->loadTime = 0.0f;
    this->dotCount = 0;

    int x = this->gameInstance->GetRenderWindow().getSize().x;
    int y = this->gameInstance->GetRenderWindow().getSize().y;

    this->background = new sf::RectangleShape();
    this->background->setFillColor(sf::Color(21, 28, 28));
    this->background->setSize(sf::Vector2f(x,y));
    this->background->setPosition(0, 0);

    font = this->gameInstance->GetResourceManager()->GetFont();
    this->myText = new sf::Text();
    this->myText->setFont(*font);
    this->myText->setFillColor(sf::Color::White);
    this->myText->setString("Loading");
    sf::Vector2u windowSize = gameInstance->GetRenderWindow().getSize();
    sf::FloatRect textRect = this->myText->getLocalBounds();
    this->myText->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    this->myText->setPosition(windowSize.x / 2.0f, windowSize.y / 2.0f);

    this->mySpinner = new sf::Sprite();
    this->mySpinner->setTexture(*this->gameInstance->GetResourceManager()->GetTextureSpinner());
    this->mySpinner->setScale(0.05f, 0.05f);
    this->mySpinner->setOrigin(this->mySpinner->getLocalBounds().width / 2, this->mySpinner->getLocalBounds().height / 2);
    this->mySpinner->setPosition(x * 0.90f, y * 0.90f);

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
    window.draw(*this->background);
    window.draw(*this->mySpinner);
    window.draw(*this->myText);
}

void LoadingScreen::Update(float deltaTime)
{
    this->mySpinner->rotate(deltaTime * 200);
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
