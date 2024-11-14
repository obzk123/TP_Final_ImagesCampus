#include "PlayMenu.h"
#include "Song.h"
#include "Game.h"
#include "LabelSong.h"
#include "ResourceManager.h"


PlayMenu::PlayMenu(Game* gameInstance)
{
	this->gameInstance = gameInstance;
	int spacing = 200;
	sf::FloatRect textRect;
	font = this->gameInstance->GetResourceManager()->GetFont();

	int x = this->gameInstance->GetRenderWindow().getSize().x;
	int y = this->gameInstance->GetRenderWindow().getSize().y;

	this->background = new sf::RectangleShape();
	this->background->setFillColor(sf::Color(21, 28, 28));
	this->background->setSize(sf::Vector2f(x, y));
	this->background->setPosition(0, 0);

	this->subBackground = new sf::Sprite();
	this->subBackground->setTexture(*this->gameInstance->GetResourceManager()->GetTextureLabelB());
	this->subBackground->setScale(0.17f, 0.24f);
	this->subBackground->setOrigin(this->subBackground->getTexture()->getSize().x / 2.0f, this->subBackground->getTexture()->getSize().y / 2.0f);
	this->subBackground->setPosition(x / 2, y / 2);


	for (int i = 0; i < this->gameInstance->GetSongs().size(); i++)
	{
		//Label
		this->labelSongs.push_back(new LabelSong());
		this->labelSongs[i]->labelBackground->setTexture(*this->gameInstance->GetResourceManager()->GetTextureLabelC());
		this->labelSongs[i]->labelBackground->setScale(0.09f, 0.09f);
		this->labelSongs[i]->labelBackground->setOrigin(this->labelSongs[i]->labelBackground->getTexture()->getSize().x / 2.0f, this->labelSongs[i]->labelBackground->getTexture()->getSize().y / 2.0f);
		this->labelSongs[i]->labelBackground->setPosition(x * 0.50f, (y * 0.33f) + spacing * i);

		//Titulo
		this->labelSongs[i]->title->setFont(*font);
		this->labelSongs[i]->title->setString(this->gameInstance->GetSongs()[i]->GetNameSong());
		this->labelSongs[i]->title->setCharacterSize(18);
		this->labelSongs[i]->title->setFillColor(sf::Color::White);
		textRect = this->labelSongs[i]->title->getLocalBounds();
		this->labelSongs[i]->title->setOrigin(0, textRect.top + textRect.height / 2.0f);
		this->labelSongs[i]->title->setPosition(x * 0.40f, (y * 0.25f) + spacing * i);

		//Subtítulo
		this->labelSongs[i]->subtitle->setFont(*font);
		this->labelSongs[i]->subtitle->setString("Artist: " + this->gameInstance->GetSongs()[i]->GetNameArtist());
		this->labelSongs[i]->subtitle->setCharacterSize(15);
		this->labelSongs[i]->subtitle->setFillColor(sf::Color::White);
		textRect = this->labelSongs[i]->subtitle->getLocalBounds();
		this->labelSongs[i]->subtitle->setOrigin(0, textRect.top + textRect.height / 2.0f);
		this->labelSongs[i]->subtitle->setPosition(x * 0.39f, (y * 0.30f) + spacing * i);

		//Album
		this->labelSongs[i]->album->setFont(*font);
		this->labelSongs[i]->album->setString("Album: " + this->gameInstance->GetSongs()[i]->GetAlbum());
		this->labelSongs[i]->album->setCharacterSize(15);
		this->labelSongs[i]->album->setFillColor(sf::Color::White);
		textRect = this->labelSongs[i]->album->getLocalBounds();
		this->labelSongs[i]->album->setOrigin(0, textRect.top + textRect.height / 2.0f);
		this->labelSongs[i]->album->setPosition(x * 0.39f, (y * 0.33f) + spacing * i);

		//Duracion
		this->labelSongs[i]->duracion->setFont(*font);
		this->labelSongs[i]->duracion->setString("Time: " + this->gameInstance->GetSongs()[i]->GetTime());
		this->labelSongs[i]->duracion->setCharacterSize(15);
		this->labelSongs[i]->duracion->setFillColor(sf::Color::White);
		textRect = this->labelSongs[i]->duracion->getLocalBounds();
		this->labelSongs[i]->duracion->setOrigin(0, textRect.top + textRect.height / 2.0f);
		this->labelSongs[i]->duracion->setPosition(x * 0.39f, (y * 0.36f) + spacing * i);

		//Score
		this->labelSongs[i]->score->setFont(*font);
		this->labelSongs[i]->score->setString("High score: " + std::to_string(this->gameInstance->GetSongs()[i]->GetScore()));
		this->labelSongs[i]->score->setCharacterSize(15);
		this->labelSongs[i]->score->setFillColor(sf::Color::White);
		textRect = this->labelSongs[i]->score->getLocalBounds();
		this->labelSongs[i]->score->setOrigin(0, textRect.top + textRect.height / 2.0f);
		this->labelSongs[i]->score->setPosition(x * 0.39f, (y * 0.39f) + spacing * i);


		//Imagen
		this->labelSongs[i]->image->setTexture(*this->gameInstance->GetSongs()[i]->GetImage());
		sf::Vector2f desiredSize(75, 75);
		float scaleX = desiredSize.x / this->gameInstance->GetSongs()[i]->GetImage()->getSize().x;
		float scaleY = desiredSize.y / this->gameInstance->GetSongs()[i]->GetImage()->getSize().y;
		this->labelSongs[i]->image->setScale(scaleX, scaleY);
		this->labelSongs[i]->image->setOrigin(scaleX / 2.0f, scaleY / 2.0f);
		this->labelSongs[i]->image->setPosition(x * 0.55f, (y * 0.21f) + spacing * i + 50);

	}

	LabelSong* backLabel = new LabelSong();
	backLabel->labelBackground->setTexture(*this->gameInstance->GetResourceManager()->GetTextureLabelA());
	backLabel->labelBackground->setScale(0.05f, 0.05f);
	backLabel->labelBackground->setOrigin(backLabel->labelBackground->getTexture()->getSize().x / 2.0f, backLabel->labelBackground->getTexture()->getSize().y / 2.0f);
	backLabel->labelBackground->setPosition(x / 2, y * 0.78f);

	backLabel->title->setFont(*font);
	backLabel->title->setCharacterSize(32);
	backLabel->title->setString("Back");
	backLabel->title->setFillColor(sf::Color::White);
	textRect = backLabel->title->getLocalBounds();
	backLabel->title->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	backLabel->title->setPosition(x / 2, y * 0.78f);
	this->labelSongs.push_back(backLabel);

	this->labelSongs[0]->labelBackground->setColor(sf::Color(255, 0, 0, 128));
	this->backNumber = this->labelSongs.size() - 1;
}

PlayMenu::~PlayMenu()
{

}

TypeScreen PlayMenu::SelectOption()
{
	if (this->selectedOption == this->backNumber)
	{
		return TypeScreen::MainMenu;
	}

	switch (selectedOption)
	{
	default:
		return TypeScreen::Game;
		break;
	}
}

TypeScreen PlayMenu::ProcessInput(sf::Event event)
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

void PlayMenu::MoveUp()
{
	if (this->selectedOption > 0)
	{
		this->SoundMenuUp->play();
		if (this->selectedOption == this->labelSongs.size() - 1)
		{
			this->labelSongs[this->selectedOption]->title->setFillColor(sf::Color::White);
			this->labelSongs[this->selectedOption]->labelBackground->setColor(sf::Color::White);
		}
		else
		{
			this->labelSongs[this->selectedOption]->labelBackground->setColor(sf::Color::White);
		}
		this->selectedOption--;
		this->labelSongs[this->selectedOption]->labelBackground->setColor(sf::Color(255, 0, 0, 128));
		this->PlaySound();
		
	}
	
}

void PlayMenu::MoveDown()
{
	if (this->selectedOption < this->labelSongs.size() - 1)
	{
		this->SoundMenuDown->play();
		this->labelSongs[this->selectedOption]->labelBackground->setColor(sf::Color::White);
		this->selectedOption++;
		if (this->selectedOption == this->labelSongs.size() - 1)
		{
			this->labelSongs[this->selectedOption]->title->setFillColor(sf::Color(255, 0, 0, 128));
			this->labelSongs[this->selectedOption]->labelBackground->setColor(sf::Color(255, 0, 0, 128));
		}
		else 
		{
			this->PlaySound();
			this->labelSongs[this->selectedOption]->labelBackground->setColor(sf::Color(255, 0, 0, 128));
		}
	}
}

void PlayMenu::PlaySound()
{
	this->gameInstance->SetCurrentSong((this->gameInstance->GetSongs()[selectedOption]));
	this->gameInstance->GetCurrentSong()->PlaySongPreview();
}

void PlayMenu::Draw(sf::RenderWindow& window)
{
	window.draw(*this->background);
	window.draw(*this->subBackground);

	for (int i = 0; i < this->labelSongs.size(); i++)
	{
		window.draw(*this->labelSongs[i]->labelBackground);
		window.draw(*this->labelSongs[i]->title);
		window.draw(*this->labelSongs[i]->subtitle);
		window.draw(*this->labelSongs[i]->duracion);
		window.draw(*this->labelSongs[i]->album);
		window.draw(*this->labelSongs[i]->score);
		window.draw(*this->labelSongs[i]->image);
	}
}

void PlayMenu::Update(float deltaTime)
{
	Screens::Update(deltaTime);
	for (int i = 0; i < this->labelSongs.size() - 1; i++)
	{
		this->labelSongs[i]->score->setString("High score: " + std::to_string(this->gameInstance->GetSongs()[i]->GetScore()));
	}
	
}
