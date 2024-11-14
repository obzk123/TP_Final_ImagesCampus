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
	this->game = game;
	int sizeX = this->game->GetRenderWindow().getSize().x;
	int sizeY = this->game->GetRenderWindow().getSize().y;

	float targetY = sizeY - this->noteImage->getGlobalBounds().height;
	this->velocity = targetY / NOTE_DURATION;

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
		this->positionInX = sizeX * GREEN_POSITION_X;
		break;
	case TypeNote::RED:
		this->noteImage->setTexture(*game->GetResourceManager()->GetTextureNoteRed());
		this->positionInX = sizeX * RED_POSITION_X;
		break;
	case TypeNote::YELLOW:
		this->noteImage->setTexture(*game->GetResourceManager()->GetTextureNoteYellow());
		this->positionInX = sizeX * YELLOW_POSITION_X;
		break;
	case TypeNote::BLUE:
		this->noteImage->setTexture(*game->GetResourceManager()->GetTextureNoteBlue());
		this->positionInX = sizeX * BLUE_POSITION_X;
		break;
	case TypeNote::ORANGE:
		this->noteImage->setTexture(*game->GetResourceManager()->GetTextureNoteOrange());
		this->positionInX = sizeX * ORANGE_POSITION_X;
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
	
	this->noteImage->setRotation(0);
	this->noteImage->setOrigin(this->noteImage->getTexture()->getSize().x / 2, this->noteImage->getTexture()->getSize().y / 2);
	this->noteImage->setPosition(this->positionInX, sizeY * START_NOTE_POSITION_Y);
			
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
		if (this->noteImage->getPosition().y >  this->game->GetRenderWindow().getSize().y * 1.0f)
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
