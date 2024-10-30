#include "PlayMenu.h"
#include "Song.h"
#include "Game.h"
#include "LabelSong.h"
#include "ResourceManager.h"


PlayMenu::PlayMenu(Game* gameInstance)
{
	this->gameInstance = gameInstance;
	int baseDistance = 50;
	int spacing = 140;
	font = this->gameInstance->GetResourceManager()->GetFont();
	for (int i = 0; i < this->gameInstance->GetSongs().size(); i++)
	{
		//Label
		this->labelSongs.push_back(new LabelSong());
		this->labelSongs[i]->labelBackground->setSize(sf::Vector2f(300, 115));
		this->labelSongs[i]->labelBackground->setFillColor(sf::Color::White);
		this->labelSongs[i]->labelBackground->setOutlineThickness(3);
		this->labelSongs[i]->labelBackground->setOutlineColor(sf::Color::White);
		this->labelSongs[i]->labelBackground->setPosition(250, baseDistance + spacing * i);

		//Titulo
		this->labelSongs[i]->title->setFont(*font);
		this->labelSongs[i]->title->setString(this->gameInstance->GetSongs()[i]->GetNameSong());
		this->labelSongs[i]->title->setCharacterSize(24);
		this->labelSongs[i]->title->setFillColor(sf::Color::Black);
		this->labelSongs[i]->title->setPosition(250, baseDistance + spacing * i);

		//Subtítulo
		this->labelSongs[i]->subtitle->setFont(*font);
		this->labelSongs[i]->subtitle->setString("Artist: " + this->gameInstance->GetSongs()[i]->GetNameArtist());
		this->labelSongs[i]->subtitle->setCharacterSize(18);
		this->labelSongs[i]->subtitle->setFillColor(sf::Color::Black);
		this->labelSongs[i]->subtitle->setPosition(250, baseDistance + 35 + spacing * i);

		//Duracion
		this->labelSongs[i]->duracion->setFont(*font);
		this->labelSongs[i]->duracion->setString("Time: " + this->gameInstance->GetSongs()[i]->GetTime());
		this->labelSongs[i]->duracion->setCharacterSize(18);
		this->labelSongs[i]->duracion->setFillColor(sf::Color::Black);
		this->labelSongs[i]->duracion->setPosition(350, baseDistance + 35 + spacing * i);

		//Album
		this->labelSongs[i]->album->setFont(*font);
		this->labelSongs[i]->album->setString("Album: " + this->gameInstance->GetSongs()[i]->GetAlbum());
		this->labelSongs[i]->album->setCharacterSize(18);
		this->labelSongs[i]->album->setFillColor(sf::Color::Black);
		this->labelSongs[i]->album->setPosition(250, baseDistance + 60 + spacing * i);

		//Score
		this->labelSongs[i]->score->setFont(*font);
		this->labelSongs[i]->score->setString("High score: " + std::to_string(this->gameInstance->GetSongs()[i]->GetScore()));
		this->labelSongs[i]->score->setCharacterSize(18);
		this->labelSongs[i]->score->setFillColor(sf::Color::Black);
		this->labelSongs[i]->score->setPosition(250, baseDistance + 85 + spacing * i);

		//Imagen
		this->labelSongs[i]->image->setTexture(*this->gameInstance->GetSongs()[i]->GetImage());
		sf::Vector2f desiredSize(100, 100);
		float scaleX = desiredSize.x / this->gameInstance->GetSongs()[i]->GetImage()->getSize().x;
		float scaleY = desiredSize.y / this->gameInstance->GetSongs()[i]->GetImage()->getSize().y;
		this->labelSongs[i]->image->setScale(scaleX, scaleY);
		this->labelSongs[i]->image->setPosition(450, baseDistance + spacing * i + 8);

	}

	LabelSong* backLabel = new LabelSong();
	backLabel->title->setFont(*font);
	backLabel->title->setString("Back");
	backLabel->title->setCharacterSize(24);
	backLabel->title->setFillColor(sf::Color::White);
	backLabel->title->setPosition(375, baseDistance + spacing * this->labelSongs.size());
	this->labelSongs.push_back(backLabel);

	this->labelSongs[0]->labelBackground->setOutlineColor(sf::Color::Red);
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
		if (this->selectedOption == this->labelSongs.size() - 1)
		{
			this->labelSongs[this->selectedOption]->title->setFillColor(sf::Color::White);
		}
		else
		{
			this->labelSongs[this->selectedOption]->labelBackground->setOutlineColor(sf::Color::White);
		}
		this->selectedOption--;
		this->labelSongs[this->selectedOption]->labelBackground->setOutlineColor(sf::Color::Red);
		this->PlaySound();
		
	}
	
}

void PlayMenu::MoveDown()
{
	if (this->selectedOption < this->labelSongs.size() - 1)
	{
		this->labelSongs[this->selectedOption]->labelBackground->setOutlineColor(sf::Color::White);
		this->selectedOption++;
		if (this->selectedOption == this->labelSongs.size() - 1)
		{
			this->labelSongs[this->selectedOption]->title->setFillColor(sf::Color::Red);
		}
		else 
		{
			this->PlaySound();
			this->labelSongs[this->selectedOption]->labelBackground->setOutlineColor(sf::Color::Red);
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
