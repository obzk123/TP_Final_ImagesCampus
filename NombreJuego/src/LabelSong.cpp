#include "LabelSong.h"

LabelSong::LabelSong()
{
	this->labelBackground = new sf::Sprite();
	this->title = new sf::Text();
	this->subtitle = new sf::Text();
	this->duracion = new sf::Text();
	this->image = new sf::Sprite();
	this->album = new sf::Text();
	this->score = new sf::Text();
}

LabelSong::~LabelSong()
{
	if (this->labelBackground != nullptr)
	{
		delete this->labelBackground;
		this->labelBackground = nullptr;
	}
	if (this->title != nullptr)
	{
		delete this->title;
		this->title = nullptr;
	}
	if (this->subtitle != nullptr)
	{
		delete this->subtitle;
		this->subtitle = nullptr;
	}
	if (this->duracion != nullptr)
	{
		delete this->duracion;
		this->duracion = nullptr;
	}
	if (this->image != nullptr)
	{
		delete this->image;
		this->image = nullptr;
	}
	if (this->album != nullptr)
	{
		delete this->album;
		this->album = nullptr;
	}
	if (this->score != nullptr)
	{
		delete this->score;
		this->score = nullptr;
	}
}
