#pragma once

#include "GameObject.h"

class Game;
class Song;

class ResourceManager : GameObject
{
public:
	ResourceManager(Game* game);
	~ResourceManager();
	sf::Texture* GetTextureNoteGreen()			{	return this->TextureNoteGreen;			}
	sf::Texture* GetTextureNoteRed()			{	return this->TextureNoteRed;			}
	sf::Texture* GetTextureNoteYellow()			{	return this->TextureNoteYellow;			}
	sf::Texture* GetTextureNoteBlue()			{	return this->TextureNoteBlue;			}
	sf::Texture* GetTextureNoteOrange()			{	return this->TextureNoteOrange;			}

	sf::Texture* GetTextureButtonGreen()		{	return this->TextureButtonGreen;		}
	sf::Texture* GetTextureButtonRed()			{	return this->TextureButtonRed;			}
	sf::Texture* GetTextureButtonYellow()		{	return this->TextureButtonYellow;		}
	sf::Texture* GetTextureButtonBlue()			{	return this->TextureButtonBlue;			}
	sf::Texture* GetTextureButtonOrange()		{	return this->TextureButtonOrange;		}

	sf::Texture* GetTextureButtonPressGreen()	{	return this->TextureButtonPressGreen;	}
	sf::Texture* GetTextureButtonPressRed()		{	return this->TextureButtonPressRed;		}
	sf::Texture* GetTextureButtonPressYellow()	{	return this->TextureButtonPressYellow;	}
	sf::Texture* GetTextureButtonPressBlue()	{	return this->TextureButtonPressBlue;	}
	sf::Texture* GetTextureButtonPressOrange()	{	return this->TextureButtonPressOrange;	}
	sf::Texture* GetTextureDisc()				{	return this->TextureDisc;				}
	sf::Texture* GetTextureSpinner()			{	return this->TextureSpinner;			}
	sf::Texture* GetTextureLabelA()				{	return this->TextureLabelA;				}
	sf::Texture* GetTextureLabelB()				{	return this->TextureLabelB;				}
	sf::Texture* GetTextureLabelC()				{	return this->TextureLabelC;				}
	sf::Texture* GetTextureBackground()			{	return this->TextureBackground;			}
	sf::Texture* GetTextureBackground_2()		{	return this->TextureBackground_2;		}
	sf::Texture* GetTextureRockMeter()			{	return this->TextureRockMeter;			}
	sf::Texture* GetTextureTrack()				{	return this->TextureTrack;				}
	sf::SoundBuffer* GetBufferBadNote1()		{	return this->BufferBadNote1;			}
	sf::SoundBuffer* GetBufferBadNote2()		{	return this->BufferBadNote2;			}
	sf::SoundBuffer* GetBufferBadNote3()		{	return this->BufferBadNote3;			}
	sf::SoundBuffer* GetBufferBadNote4()		{	return this->BufferBadNote4;			}
	sf::SoundBuffer* GetBufferBadNote5()		{	return this->BufferBadNote5;			}

	sf::Texture* GetTextureArrow()				{	return this->TextureArrow;				}
	sf::SoundBuffer* GetBufferMetronome()		{	return this->BufferMetronome;			}
	sf::SoundBuffer* GetBufferPublicHappy()		{	return this->BufferPublicHappy;			}
	sf::SoundBuffer* GetBufferPublicAngry()		{	return this->BufferPublicAngry;			}

	sf::Texture* GetTexturePowerUpOne()			{	return this->TexturePowerUpOne;			}
	sf::Texture* GetTexturePowerUpTwo()			{	return this->TexturePowerUpTwo;			}

	sf::Texture* GetTextureKeyUp()				{ return this->TextureKeyUp;				}
	sf::Texture* GetTextureKeyDown()			{ return this->TextureKeyDown;				}
	sf::Texture* GetTextureKeyLeft()			{ return this->TextureKeyLeft;				}
	sf::Texture* GetTextureKeyRight()			{ return this->TextureKeyRight;				}
	sf::Texture* GetTextureKeyQ()				{ return this->TextureKeyQ;					}
	sf::Texture* GetTextureKeyW()				{ return this->TextureKeyW;					}
	sf::Texture* GetTextureKeyE()				{ return this->TextureKeyE;					}
	sf::Texture* GetTextureKeyR()				{ return this->TextureKeyR;					}
	sf::Texture* GetTextureKeyT()				{ return this->TextureKeyT;					}

	sf::Texture* GetTextureGit()				{	return this->TextureGit;				}
	sf::Texture* GetTextureLinkedin()			{	return this->TextureLinkedin;			}

	sf::Texture* GetTextureFretboard()			{	return this->TextureFretboard;			}

	sf::Font* GetFont()							{	return this->font;						}

	void InitLoad();
	void LoadFont();
	bool LoadAllPartialSong(std::vector<Song*>& songs);
	Song* LoadPartialSong(std::string path, Game* game);

private:

	Game* gameInstance;
	sf::Texture* TextureButtonGreen;
	sf::Texture* TextureButtonRed;
	sf::Texture* TextureButtonYellow;
	sf::Texture* TextureButtonBlue;
	sf::Texture* TextureButtonOrange;
	sf::Texture* TextureButtonPressGreen;
	sf::Texture* TextureButtonPressRed;
	sf::Texture* TextureButtonPressYellow;
	sf::Texture* TextureButtonPressBlue;
	sf::Texture* TextureButtonPressOrange;
	sf::Texture* TextureNoteGreen;
	sf::Texture* TextureNoteRed;
	sf::Texture* TextureNoteYellow;
	sf::Texture* TextureNoteBlue;
	sf::Texture* TextureNoteOrange;
	sf::Texture* TextureArrow;
	sf::Texture* TexturePowerUpOne;
	sf::Texture* TexturePowerUpTwo;
	sf::Texture* TextureRockMeter;
	sf::Texture* TextureTrack;
	sf::Texture* TextureDisc;
	sf::Texture* TextureSpinner;
	sf::Texture* TextureLabelA;
	sf::Texture* TextureLabelB;
	sf::Texture* TextureLabelC;
	sf::Texture* TextureBackground;
	sf::Texture* TextureBackground_2;
	sf::Texture* TextureGit;
	sf::Texture* TextureLinkedin;
	sf::Texture* TextureFretboard;
	sf::Texture* TextureKeyUp;
	sf::Texture* TextureKeyDown;
	sf::Texture* TextureKeyLeft;
	sf::Texture* TextureKeyRight;
	sf::Texture* TextureKeyQ;
	sf::Texture* TextureKeyW;
	sf::Texture* TextureKeyE;
	sf::Texture* TextureKeyR;
	sf::Texture* TextureKeyT;

	sf::SoundBuffer* BufferMetronome;
	sf::SoundBuffer* BufferPublicHappy;
	sf::SoundBuffer* BufferPublicAngry;
	sf::SoundBuffer* BufferBadNote1;
	sf::SoundBuffer* BufferBadNote2;
	sf::SoundBuffer* BufferBadNote3;
	sf::SoundBuffer* BufferBadNote4;
	sf::SoundBuffer* BufferBadNote5;
	sf::Font* font;
};

