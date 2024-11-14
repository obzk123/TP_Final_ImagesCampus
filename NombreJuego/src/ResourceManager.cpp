#include "ResourceManager.h"
#include "Game.h"
#include "Song.h"

ResourceManager::ResourceManager(Game* game)
{	
	this->gameInstance				= game;
	this->TextureNoteGreen			= new sf::Texture();
	this->TextureNoteRed			= new sf::Texture();
	this->TextureNoteYellow			= new sf::Texture();
	this->TextureNoteBlue			= new sf::Texture();
	this->TextureNoteOrange			= new sf::Texture();
	this->TextureButtonGreen		= new sf::Texture();
	this->TextureButtonRed			= new sf::Texture();
	this->TextureButtonYellow		= new sf::Texture();
	this->TextureButtonBlue			= new sf::Texture();
	this->TextureButtonOrange		= new sf::Texture();
	this->TextureButtonPressGreen	= new sf::Texture();
	this->TextureButtonPressRed		= new sf::Texture();
	this->TextureButtonPressYellow	= new sf::Texture();
	this->TextureButtonPressBlue	= new sf::Texture();
	this->TextureButtonPressOrange	= new sf::Texture();
	this->TextureArrow				= new sf::Texture();
	this->TexturePowerUpOne			= new sf::Texture();
	this->TexturePowerUpTwo			= new sf::Texture();
	this->TextureRockMeter			= new sf::Texture();
	this->TextureTrack				= new sf::Texture();
	this->TextureDisc				= new sf::Texture();
	this->TextureSpinner			= new sf::Texture();
	this->TextureLabelA				= new sf::Texture();
	this->TextureLabelB				= new sf::Texture();
	this->TextureLabelC				= new sf::Texture();
	this->TextureGit				= new sf::Texture();
	this->TextureLinkedin			= new sf::Texture();
	this->TextureFretboard			= new sf::Texture();
	this->BufferMetronome			= new sf::SoundBuffer();
	this->BufferPublicHappy			= new sf::SoundBuffer();
	this->BufferPublicAngry			= new sf::SoundBuffer();
	this->BufferBadNote1			= new sf::SoundBuffer();
	this->BufferBadNote2			= new sf::SoundBuffer();
	this->BufferBadNote3			= new sf::SoundBuffer();
	this->BufferBadNote4			= new sf::SoundBuffer();
	this->BufferBadNote5			= new sf::SoundBuffer();
	this->font						= new sf::Font();
	this->TextureBackground			= new sf::Texture();
	this->TextureBackground_2		= new sf::Texture();
	this->TextureKeyUp				= new sf::Texture();
	this->TextureKeyDown			= new sf::Texture();
	this->TextureKeyLeft			= new sf::Texture();
	this->TextureKeyRight			= new sf::Texture();
	this->TextureKeyQ				= new sf::Texture();
	this->TextureKeyW				= new sf::Texture();
	this->TextureKeyE				= new sf::Texture();
	this->TextureKeyR				= new sf::Texture();
	this->TextureKeyT				= new sf::Texture();
}

ResourceManager::~ResourceManager()
{
	if (this->TextureButtonGreen != nullptr)
	{
		delete this->TextureButtonGreen;
		this->TextureButtonGreen = nullptr;
	}

	if (this->TextureButtonRed != nullptr)
	{
		delete this->TextureButtonRed;
		this->TextureButtonRed = nullptr;
	}
	
	if (this->TextureButtonYellow != nullptr)
	{
		delete this->TextureButtonYellow;
		this->TextureButtonYellow = nullptr;
	}
	
	if (this->TextureButtonBlue != nullptr)
	{
		delete this->TextureButtonBlue;
		this->TextureButtonBlue = nullptr;
	}

	if (this->TextureButtonOrange != nullptr)
	{
		delete this->TextureButtonOrange;
		this->TextureButtonOrange = nullptr;
	}

	if (this->TextureArrow != nullptr)
	{
		delete this->TextureArrow;
		this->TextureArrow = nullptr;
	}

	if (this->BufferMetronome != nullptr)
	{
		delete this->BufferMetronome;
		this->BufferMetronome = nullptr;
	}

	if (this->TexturePowerUpOne != nullptr)
	{
		delete this->TexturePowerUpOne;
		this->TexturePowerUpOne = nullptr;
	}
	if (this->TexturePowerUpTwo != nullptr)
	{
		delete this->TexturePowerUpTwo;
		this->TexturePowerUpTwo = nullptr;
	}
	
	if (this->font != nullptr)
	{
		delete this->font;
		this->font = nullptr;
	}

	if (this->BufferPublicHappy != nullptr)
	{
		delete this->BufferPublicHappy;
		this->BufferPublicHappy = nullptr;
	}

	if (this->BufferPublicAngry != nullptr)
	{
		delete this->BufferPublicAngry;
		this->BufferPublicAngry = nullptr;
	}

	if (this->TextureSpinner != nullptr)
	{
		delete this->TextureSpinner;
		this->TextureSpinner = nullptr;
	}

	if (this->TextureLabelA != nullptr)
	{
		delete this->TextureLabelA;
		this->TextureLabelA = nullptr;
	}

	if (this->TextureLabelB != nullptr)
	{
		delete this->TextureLabelB;
		this->TextureLabelB = nullptr;
	}

	if (this->TextureLabelC != nullptr)
	{
		delete this->TextureLabelC;
		this->TextureLabelC = nullptr;
	}
}

void ResourceManager::InitLoad()
{
	this->TextureNoteGreen->loadFromFile(CURRENT_PATH + TEXTURE_PATH + NOTE_GREEN_TEXTURE);
	this->TextureNoteRed->loadFromFile(CURRENT_PATH + TEXTURE_PATH + NOTE_RED_TEXTURE);
	this->TextureNoteYellow->loadFromFile(CURRENT_PATH + TEXTURE_PATH + NOTE_YELLOW_TEXTURE);
	this->TextureNoteBlue->loadFromFile(CURRENT_PATH + TEXTURE_PATH + NOTE_BLUE_TEXTURE);
	this->TextureNoteOrange->loadFromFile(CURRENT_PATH + TEXTURE_PATH +	NOTE_ORANGE_TEXTURE);
	
	this->TextureButtonGreen->loadFromFile(CURRENT_PATH + TEXTURE_PATH + BUTTON_GREEN_TEXTURE);
	this->TextureButtonRed->loadFromFile(CURRENT_PATH + TEXTURE_PATH + BUTTON_RED_TEXTURE);
	this->TextureButtonYellow->loadFromFile(CURRENT_PATH + TEXTURE_PATH + BUTTON_YELLOW_TEXTURE);
	this->TextureButtonBlue->loadFromFile(CURRENT_PATH + TEXTURE_PATH +	BUTTON_BLUE_TEXTURE);
	this->TextureButtonOrange->loadFromFile(CURRENT_PATH + TEXTURE_PATH + BUTTON_ORANGE_TEXTURE);

	this->TextureButtonPressGreen->loadFromFile(CURRENT_PATH + TEXTURE_PATH + BUTTON_PRESS_GREEN_TEXTURE);
	this->TextureButtonPressRed->loadFromFile(CURRENT_PATH + TEXTURE_PATH + BUTTON_PRESS_RED_TEXTURE);
	this->TextureButtonPressYellow->loadFromFile(CURRENT_PATH + TEXTURE_PATH + BUTTON_PRESS_YELLOW_TEXTURE);
	this->TextureButtonPressBlue->loadFromFile(CURRENT_PATH + TEXTURE_PATH + BUTTON_PRESS_BLUE_TEXTURE);
	this->TextureButtonPressOrange->loadFromFile(CURRENT_PATH + TEXTURE_PATH + BUTTON_PRESS_ORANGE_TEXTURE);
	
	this->TextureLabelA->loadFromFile(CURRENT_PATH + TEXTURE_PATH + LABEL_A_TEXTURE);
	this->TextureLabelB->loadFromFile(CURRENT_PATH + TEXTURE_PATH + LABEL_B_TEXTURE);
	this->TextureLabelC->loadFromFile(CURRENT_PATH + TEXTURE_PATH + LABEL_C_TEXTURE);

	this->TextureDisc->loadFromFile(CURRENT_PATH + TEXTURE_PATH + DISC_TEXTURE);
	this->TextureRockMeter->loadFromFile(CURRENT_PATH + TEXTURE_PATH + ROCK_METER_TEXTURE);
	this->TextureTrack->loadFromFile(CURRENT_PATH + TEXTURE_PATH + TRACK_TEXTURE);
	this->TextureArrow->loadFromFile(CURRENT_PATH + TEXTURE_PATH + ARROW_TEXTURE);
	this->TexturePowerUpOne->loadFromFile(CURRENT_PATH + TEXTURE_PATH + POWER_UP_ONE_TEXTURE);
	this->TexturePowerUpTwo->loadFromFile(CURRENT_PATH + TEXTURE_PATH + POWER_UP_TWO_TEXTURE);
	this->BufferMetronome->loadFromFile(CURRENT_PATH + SONG_PATH + METRONOME_PATH);
	this->BufferPublicHappy->loadFromFile(CURRENT_PATH + SONG_PATH +  PUBLIC_HAPPY_PATH);
	this->BufferPublicAngry->loadFromFile(CURRENT_PATH + SONG_PATH + PUBLIC_ANGRY_PATH);
	
	this->TextureBackground->loadFromFile(CURRENT_PATH + TEXTURE_PATH + BACKGROUND_TEXTURE);
	this->TextureBackground_2->loadFromFile(CURRENT_PATH + TEXTURE_PATH + BACKGROUND_TEXTURE_2);

	this->TextureLinkedin->loadFromFile(CURRENT_PATH + TEXTURE_PATH + LINKEDIN_TEXTURE);
	this->TextureGit->loadFromFile(CURRENT_PATH + TEXTURE_PATH + GIT_TEXTURE);
	this->TextureFretboard->loadFromFile(CURRENT_PATH + TEXTURE_PATH + FRETBOARD_TEXTURE);

	this->BufferBadNote1->loadFromFile(CURRENT_PATH + SONG_PATH +	BUFFER_BAD_NOTE_1);
	this->BufferBadNote2->loadFromFile(CURRENT_PATH + SONG_PATH +	BUFFER_BAD_NOTE_2);
	this->BufferBadNote3->loadFromFile(CURRENT_PATH + SONG_PATH +	BUFFER_BAD_NOTE_3);
	this->BufferBadNote4->loadFromFile(CURRENT_PATH + SONG_PATH +	BUFFER_BAD_NOTE_4);
	this->BufferBadNote5->loadFromFile(CURRENT_PATH + SONG_PATH +	BUFFER_BAD_NOTE_5);

	this->TextureKeyUp->loadFromFile(CURRENT_PATH + TEXTURE_PATH	+ KEY_UP);
	this->TextureKeyDown->loadFromFile(CURRENT_PATH + TEXTURE_PATH	+ KEY_DOWN);
	this->TextureKeyLeft->loadFromFile(CURRENT_PATH + TEXTURE_PATH	+ KEY_LEFT);
	this->TextureKeyRight->loadFromFile(CURRENT_PATH + TEXTURE_PATH + KEY_RIGHT);
	this->TextureKeyQ->loadFromFile(CURRENT_PATH + TEXTURE_PATH		+ KEY_Q);
	this->TextureKeyW->loadFromFile(CURRENT_PATH + TEXTURE_PATH		+ KEY_W);
	this->TextureKeyE->loadFromFile(CURRENT_PATH + TEXTURE_PATH		+ KEY_E);
	this->TextureKeyR->loadFromFile(CURRENT_PATH + TEXTURE_PATH		+ KEY_R);
	this->TextureKeyT->loadFromFile(CURRENT_PATH + TEXTURE_PATH		+ KEY_T);
}

void ResourceManager::LoadFont()
{
	this->font->loadFromFile(FONT_PATH);
	this->TextureSpinner->loadFromFile(CURRENT_PATH + TEXTURE_PATH + SPINNER_TEXTURE);
}

bool ResourceManager::LoadAllPartialSong(std::vector<Song*>& songs)
{
	try 
	{
		for (const auto& entry : std::filesystem::directory_iterator(CURRENT_PATH + SONG_PATH))
		{
			if (std::filesystem::is_directory(entry))
			{
				std::filesystem::path settingPath = entry.path() / "settingsSong.ini";
				if (std::filesystem::exists(settingPath))
				{
					Song* newSong = this->LoadPartialSong(entry.path().string(), gameInstance);
					if (newSong != nullptr)
					{
						songs.push_back(newSong);
					}
				}
			}
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
		return false;
	}

	return true;
}

Song* ResourceManager::LoadPartialSong(std::string path, Game* game)
{
	Song* newSong = new Song(game);
	std::ifstream settingsFile(path + "/settingsSong.ini");
	if (!settingsFile) 
	{
		std::cerr << "Error al abrir settingsSong.ini" << std::endl;
		return nullptr;
	}

	newSong->SetPathSettings(path + "/settingsSong.ini");
	newSong->GetPreviewSoundBuffer()->loadFromFile(path + "\\" + "preview.mp3");
	if (!newSong->GetPreviewSoundBuffer())
	{
		std::cerr << "Error al abrir preview.wav" << std::endl;
		return nullptr;
	}
	newSong->GetPreviewSound()->setBuffer(*newSong->GetPreviewSoundBuffer());
	newSong->SetPathNotes(path + "\\" + "notes.ini");
	//newSong->GetBackground()->loadFromFile(path + "\\" + "background.jpg");

	std::string line;
	while (std::getline(settingsFile, line)) {
		std::istringstream is_line(line);
		std::string key;
		if (std::getline(is_line, key, '=')) {
			std::string value;
			if (std::getline(is_line, value)) {
				if (key == "name") newSong->SetNameSong(value);
				else if (key == "artist") newSong->SetNameArtist(value);
				else if (key == "name_image")
				{
					newSong->GetImage()->loadFromFile(path + "\\" + value);
				}
				else if (key == "name_song") newSong->SetPathSong(path + "\\" + value);
				else if (key == "album") newSong->SetAlbum(value);
				else if (key == "score") newSong->SetScore(std::stoi(value));
				else if (key == "time") newSong->SetTime(value);
			}
		}
	}
	return newSong;
}
