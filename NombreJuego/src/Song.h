#pragma once

#include "GameObject.h"

class Note;
class Game;

class Song : public GameObject
{
public:
	Song(Game* gameInstance);
	~Song();
	static std::string timeToString(sf::Time time);
	
	void PauseSongPreview();
	void RestartSongPreview();
	void PlaySongPreview();
	bool IsPlayingPreview();

	void PauseSong();
	void RestartSong();
	void PlaySong();
	bool IsPlaying();

	void CleanNotesAndSong();

	std::string GetNameSong() { return this->nameSong; }
	std::string GetNameArtist() { return this->nameArtist; }
	std::string GetTime() { return this->time; }
	std::string GetAlbum() { return this->album; }
	std::vector<Note*>& GetNotes() { return this->notes; }
	sf::Texture* GetImage() { return this->image; }
	sf::Texture* GetBackground() { return this->background; }
	sf::SoundBuffer* GetSoundBuffer() { return this->soundBuffer; }
	sf::SoundBuffer* GetPreviewSoundBuffer() { return this->previewSoundBuffer; }
	sf::Sound* GetSound() { return this->sound; }
	sf::Sound* GetPreviewSound() { return this->previewSound; }
	std::string GetPathSong() { return this->pathSong; }
	std::string GetPathNotes() { return this->pathNotes; }
	std::string GetPathSettings() { return this->pathSettings; }
	int GetScore() { return this->score; }


	void SetNameSong(std::string value) { this->nameSong = value;}
	void SetNameArtist(std::string value) { this->nameArtist = value;}
	void SetTime(std::string value) { this->time = value;}
	void SetAlbum(std::string value) { this->album = value;}
	void SetNotes(std::vector<Note*> value) { this->notes = value;}
	void SetImage(sf::Texture* value) { this->image = value;}
	void SetSoundBuffer(sf::SoundBuffer* value)	{ this->soundBuffer = value;}
	void SetPreviewSoundBuffer(sf::SoundBuffer* value) { this->previewSoundBuffer = value;}
	void SetSound(sf::Sound* value)	{ this->sound = value;}
	void SetPreviewSound(sf::Sound* value) { this->previewSound = value;}
	void SetPathSong(std::string value) { this->pathSong = value; }
	void SetPathNotes(std::string value) { this->pathNotes = value; }
	void SetPathSettings(std::string value) { this->pathSettings = value; }
	void SetScore(int value) { this->score = value; }
	void LoadNotes();
	void LoadSong();
	void SaveScore();

private:
	Game* gameInstance;
	std::string pathSettings;
	std::string pathSong;
	std::string pathNotes;
	std::string nameSong;
	std::string nameArtist;
	std::string time;
	std::string album;
	std::vector<Note*> notes;
	sf::Texture* image;
	sf::SoundBuffer* soundBuffer;
	sf::SoundBuffer* previewSoundBuffer;
	sf::Sound* previewSound;
	sf::Sound* sound;
	sf::Texture* background;
	int score;
	
};

