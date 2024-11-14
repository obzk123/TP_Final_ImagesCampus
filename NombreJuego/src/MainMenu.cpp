#include "MainMenu.h"
#include "Game.h"
#include "ResourceManager.h"

MainMenu::MainMenu(Game* game)
{
    gameInstance = game;
    font = this->gameInstance->GetResourceManager()->GetFont();

    int x = this->gameInstance->GetRenderWindow().getSize().x;
    int y = this->gameInstance->GetRenderWindow().getSize().y;
    sf::FloatRect textRect;

    this->background = new sf::RectangleShape();
    this->background->setFillColor(sf::Color(21, 28, 28));
    this->background->setSize(sf::Vector2f(x, y));
    this->background->setPosition(0, 0);

    this->title = new sf::Text();
    this->title->setFont(*font);
    this->title->setCharacterSize(50);
    this->title->setString("Futuristic Hero");
    textRect = this->title->getLocalBounds();
    this->title->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    this->title->setPosition(x / 2, y * 0.20f);
    this->title->setFillColor(sf::Color::White);

    menuOptions.push_back(new sf::Text());
    menuOptions[0]->setFont(*font);
    menuOptions[0]->setString("Play");
    textRect = this->menuOptions[0]->getLocalBounds();
    this->menuOptions[0]->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    menuOptions[0]->setPosition(x / 2, y * 0.40f);
    menuOptions[0]->setFillColor(sf::Color::Red);

    labels.push_back(new sf::Sprite());
    labels[0]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureLabelA());
    labels[0]->setScale(0.05f, 0.05f);
    labels[0]->setOrigin(labels[0]->getTexture()->getSize().x / 2, labels[0]->getTexture()->getSize().y / 2);
    labels[0]->setPosition(x / 2, y * 0.40f);

    menuOptions.push_back(new sf::Text());
    menuOptions[1]->setFont(*font);
    menuOptions[1]->setString("Settings");
    textRect = this->menuOptions[1]->getLocalBounds();
    this->menuOptions[1]->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    menuOptions[1]->setPosition(x / 2, y * 0.55f);
    menuOptions[1]->setFillColor(sf::Color::White);

    labels.push_back(new sf::Sprite());
    labels[1]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureLabelA());
    labels[1]->setScale(0.05f, 0.05f);
    labels[1]->setOrigin(labels[1]->getTexture()->getSize().x / 2, labels[1]->getTexture()->getSize().y / 2);
    labels[1]->setPosition(x / 2, y * 0.55f);

    menuOptions.push_back(new sf::Text());
    menuOptions[2]->setFont(*font);
    menuOptions[2]->setString("Exit");
    textRect = this->menuOptions[2]->getLocalBounds();
    this->menuOptions[2]->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    menuOptions[2]->setPosition(x / 2, y * 0.70f);
    menuOptions[2]->setFillColor(sf::Color::White);

    labels.push_back(new sf::Sprite());
    labels[2]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureLabelA());
    labels[2]->setScale(0.05f, 0.05f);
    labels[2]->setOrigin(labels[2]->getTexture()->getSize().x / 2, labels[2]->getTexture()->getSize().y / 2);
    labels[2]->setPosition(x / 2, y * 0.70f);

    this->createdBy = new sf::Text();
    this->createdBy->setFont(*font);
    this->createdBy->setCharacterSize(14);
    this->createdBy->setFillColor(sf::Color::White);
    this->createdBy->setString("Created by Octavio Bill Zito");
    this->createdBy->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    textRect = this->createdBy->getGlobalBounds();
    this->createdBy->setPosition( x * 0.05f, y * 0.95f);

    this->git = new sf::Sprite();
    this->git->setTexture(*this->gameInstance->GetResourceManager()->GetTextureGit());
    this->git->setScale(sf::Vector2f(0.10f, 0.10f));
    this->git->setOrigin(this->git->getTexture()->getSize().x / 2.0f, this->git->getTexture()->getSize().y / 2.0f);
    this->git->setPosition(x * 0.90f, y * 0.92);

    this->linkedin = new sf::Sprite();
    this->linkedin->setTexture(*this->gameInstance->GetResourceManager()->GetTextureLinkedin());
    this->linkedin->setScale(sf::Vector2f(0.10f, 0.10f));
    this->linkedin->setOrigin(this->linkedin->getTexture()->getSize().x / 2.0f, this->linkedin->getTexture()->getSize().y / 2.0f);
    this->linkedin->setPosition(x * 0.95f, y * 0.92);

    this->KeyUp = new sf::Sprite();
    this->KeyUp->setTexture(*this->gameInstance->GetResourceManager()->GetTextureKeyUp());
    this->KeyUp->setOrigin(this->KeyUp->getTexture()->getSize().x / 2.0f, this->KeyUp->getTexture()->getSize().y / 2.0f);
    this->KeyUp->setPosition(x * 0.83f, y * 0.43f);
    
    this->KeyDown = new sf::Sprite();
    this->KeyDown->setTexture(*this->gameInstance->GetResourceManager()->GetTextureKeyDown());
    this->KeyDown->setOrigin(this->KeyDown->getTexture()->getSize().x / 2.0f, this->KeyDown->getTexture()->getSize().y / 2.0f);
    this->KeyDown->setPosition(x * 0.88f, y * 0.43f);
    
    this->explain = new sf::Text();
    this->explain->setFont(*font);
    this->explain->setCharacterSize(14);
    this->explain->setFillColor(sf::Color::White);
    this->explain->setString("How to move in menus");
    textRect = this->explain->getGlobalBounds();
    this->explain->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    this->explain->setPosition(x * 0.85f, y * 0.37f);

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

TypeScreen MainMenu::ProcessInput(sf::Event event)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        // transform the mouse position from window coordinates to world coordinates
        sf::Vector2f mouse = this->gameInstance->GetRenderWindow().mapPixelToCoords(sf::Mouse::getPosition(this->gameInstance->GetRenderWindow()));
        // retrieve the bounding box of the sprite
        sf::FloatRect gitBounds = this->git->getGlobalBounds();
        sf::FloatRect linkedinBounds = this->linkedin->getGlobalBounds();
        // hit test
        if (gitBounds.contains(mouse))
        {
            // mouse is on sprite!
            std::string comando = "start https://github.com/obzk123";
            system(comando.c_str());
        }

        if (linkedinBounds.contains(mouse))
        {
            // mouse is on sprite!
            std::string comando = "start https://www.linkedin.com/in/octavio-bill-zito-aa8145200/";
            system(comando.c_str());
        }
    }
    return Screens::ProcessInput(event);
}

void MainMenu::Draw(sf::RenderWindow& window)
{
    window.draw(*this->background);
    window.draw(*this->createdBy);
    window.draw(*this->git);
    window.draw(*this->linkedin);
    Screens::Draw(window);
    window.draw(*this->title);
    window.draw(*this->explain);
    window.draw(*this->KeyUp);
    window.draw(*this->KeyDown);
}
