#include "Note.h"
#include "ResourceManager.h"
#include "Game.h"
#include "GameScreen.h"
#include "Player.h"

Note::Note(TypeNote typeNote, float startTime, float endTime, int powerUp, Game* game)
{
	this->noteImage = new sf::Sprite();
	this->powerUp = powerUp;
	this->startTime = 0;
	this->endTime = 0;
	this->canBeDestroy = false;
	this->velocity = (END_NOTE_POSITION_Y - START_NOTE_POSITION_Y) / NOTE_DURATION;
	this->game = game;
	if (!this->SetTypeNote(typeNote) || !this->SetStartTime(startTime) || !this->SetEndTime(endTime))
	{
		std::cerr << "Error al crear la nota" << std::endl;
		return;
	}

	isVisible = true;
	switch (this->typeNote)
	{
	case TypeNote::GREEN:;
		this->noteImage->setTexture(*game->GetResourceManager()->GetTextureNoteGreen());
		this->positionInX = GREEN_POSITION_X;
		break;
	case TypeNote::RED:
		this->noteImage->setTexture(*game->GetResourceManager()->GetTextureNoteRed());
		this->positionInX = RED_POSITION_X;
		break;
	case TypeNote::YELLOW:
		this->noteImage->setTexture(*game->GetResourceManager()->GetTextureNoteYellow());
		this->positionInX = YELLOW_POSITION_X;
		break;
	case TypeNote::BLUE:
		this->noteImage->setTexture(*game->GetResourceManager()->GetTextureNoteBlue());
		this->positionInX = BLUE_POSITION_X;
		break;
	case TypeNote::ORANGE:
		this->noteImage->setTexture(*game->GetResourceManager()->GetTextureNoteOrange());
		this->positionInX = ORANGE_POSITION_X;
		break;
	}

	switch (powerUp)
	{
	case 1:
		this->noteImage->setTexture(*game->GetResourceManager()->GetTexturePowerUpOne());
		break;
	case 2:
		this->noteImage->setTexture(*game->GetResourceManager()->GetTexturePowerUpTwo());
		break;
	}
	
	//float diferentTime = this->endTime - this->startTime;
	//if (diferentTime > 0)
	//{
	//	sf::Vector2u textureSize = game->GetResourceManager()->GetTextureButtonGreen()->getSize();
	//	sf::IntRect textureRect(0, 0, textureSize.x, 50 * diferentTime);
	//	this->noteImage->setTextureRect(textureRect);
	//}
	this->noteImage->setRotation(0);
	this->noteImage->setOrigin(50,50);
	this->noteImage->setPosition(this->positionInX, START_NOTE_POSITION_Y);
			
}

Note::~Note()
{
	if (this->noteImage != nullptr)
	{
		delete this->noteImage;
		this->noteImage = nullptr;
	}
}

float Note::GetStartTime()
{
	return this->startTime;
}

float Note::GetEndTime()
{
	return this->endTime;
}

bool Note::SetStartTime(float newTime)
{
	if (newTime > -1.0f)
	{
		this->startTime = newTime;
		return true;
	}
	return false;
}

bool Note::SetEndTime(float newTime)
{
	if (newTime > -1.0f)
	{
		this->endTime = newTime;
		return true;
	}
	return false;
}

bool Note::GetCanBeDestroy()
{
	return this->canBeDestroy;
}

void Note::SetCanBeDestroy(bool newState)
{
	this->canBeDestroy = true;
}

sf::Sprite* Note::GetSpriteNote()
{
	return this->noteImage;
}

void Note::Update(float deltaTime)
{
	if (isVisible)
	{
		sf::Vector2f positon = this->noteImage->getPosition();
		positon.y += this->velocity * deltaTime;
		this->noteImage->setPosition(positon);
		if (this->noteImage->getPosition().y > END_NOTE_POSITION_Y)
		{
			this->canBeDestroy = true;
			if (this->powerUp != 2)
			{
				this->game->GetGameScreen()->GetPlayer()->FailNote();
			}
		}
	}
}

void Note::Draw(sf::RenderWindow& window)
{
	if (isVisible)
	{
		window.draw(*this->noteImage);
	}
}

bool Note::SetTypeNote(TypeNote newTypeNote)
{
	this->typeNote = newTypeNote;
	return true;
}
