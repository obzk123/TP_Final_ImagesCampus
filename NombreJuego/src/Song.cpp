#include "Song.h"
#include "Note.h"

Song::Song(Game* gameInstance)
{
    this->gameInstance = gameInstance;
    this->image = new sf::Texture();
    this->soundBuffer = new sf::SoundBuffer();
    this->sound = new sf::Sound();
    this->previewSound = new sf::Sound();
    this->previewSoundBuffer = new sf::SoundBuffer();
    this->background = new sf::Texture();
}

Song::~Song()
{
    if (this->image != nullptr)
    {
        delete this->image;
        this->image = nullptr;
    }

    if (this->soundBuffer != nullptr)
    {
        delete this->soundBuffer;
        this->soundBuffer = nullptr;
    }

    if (this->sound != nullptr)
    {
        delete this->sound;
        this->sound = nullptr;
    }

    if (this->previewSound != nullptr)
    {
        delete this->previewSound;
        this->previewSound = nullptr;
    }

    if (this->previewSoundBuffer != nullptr)
    {
        delete this->previewSoundBuffer;
        this->previewSoundBuffer = nullptr;
    }

    if (this->background != nullptr)
    {
        delete this->background;
        this->background = nullptr;
    }
}

std::string Song::timeToString(sf::Time time)
{
    int totalSeconds = static_cast<int>(time.asSeconds());

    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;

    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << minutes << ":"
        << std::setfill('0') << std::setw(2) << seconds;

    return oss.str();
}

void Song::PauseSongPreview()
{
    this->previewSound->pause();
}

void Song::RestartSongPreview()
{
    this->previewSound->stop();
}

void Song::PlaySongPreview()
{
    this->previewSound->play();
}

void Song::PauseSong()
{
    this->sound->pause();
}

void Song::RestartSong()
{
    this->sound->stop();
}

void Song::PlaySong()
{
    this->sound->play();
}

bool Song::IsPlaying()
{
    return this->sound->getStatus() == sf::Sound::Status::Playing ? true : false;
}

void Song::CleanNotesAndSong()
{
}

void Song::LoadNotes()
{
    this->notes.clear();

    std::ifstream notesFile(this->pathNotes);
    if (!notesFile.is_open())
    {
        std::cerr << "Error al abrir notes.ini" << std::endl;
    }

    std::string line;
    while (std::getline(notesFile, line)) 
    {
        std::stringstream ss(line);
        int value1, value4; 
        float value2, value3;
        char comma;
        if (ss >> value1 >> comma >> value2 >> comma >> value3 >> comma >> value4) 
        {
            Note* newNote = new Note((TypeNote)value1, value2, value3, value4, this->gameInstance);
            if (newNote != nullptr)
            {
                this->notes.push_back(newNote);
            }
        }
        else 
        {
            std::cerr << "Error al leer la línea: " << line << std::endl;
        }
    }
    notesFile.close();
}

void Song::LoadSong()
{
    this->soundBuffer->loadFromFile(this->pathSong);
    if (this->soundBuffer == nullptr)
    {
        std::cerr << "Error al abrir la cancion" << std::endl;
    }
    else {
        this->sound->setBuffer(*this->soundBuffer);
    }
    
}

void Song::SaveScore()
{
    std::ifstream settingsFile(this->pathSettings);
    if (!settingsFile)
    {
        std::cerr << "Error al abrir settingsSong.ini para lectura" << std::endl;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(settingsFile, line)) 
    {
        std::istringstream is_line(line);
        std::string key;
        if (std::getline(is_line, key, '=')) 
        {
            if (key == "score") 
            {
                line = key + "=" + std::to_string(this->score);
            }
        }
        lines.push_back(line);
    }
    
    settingsFile.close();

    std::ofstream outputFile(this->pathSettings);
    if (!outputFile)
    {
        std::cerr << "Error al abrir settingsSong.ini para escritura" << std::endl;
    }

    for (const auto& modifiedLine : lines) 
    {
        outputFile << modifiedLine << "\n";
    }
    outputFile.close();
}

bool Song::IsPlayingPreview()
{
    return this->previewSound->getStatus() == sf::Sound::Status::Playing  ? true : false;
}
