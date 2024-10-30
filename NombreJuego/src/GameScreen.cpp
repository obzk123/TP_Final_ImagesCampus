#include "GameScreen.h"
#include "Game.h"
#include "Note.h"
#include "ResourceManager.h"
#include "Player.h"
#include "CameraShake.h"
#include "PauseMenu.h"
#include "LoadingScreen.h"
#include "LossScreen.h"
#include "WinScreen.h"

GameScreen::GameScreen(Game* game)
{
	this->gameInstance = game;

	this->buttons.push_back(new sf::Sprite());
	this->buttons[INDEX_GREEN_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonGreen());
	this->buttons[INDEX_GREEN_BUTTON]->setOrigin(50, 50);
	this->buttons[INDEX_GREEN_BUTTON]->setPosition(GREEN_POSITION_X, BUTTON_POSITION_Y);

	this->buttons.push_back(new sf::Sprite());
	this->buttons[INDEX_RED_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonRed());
	this->buttons[INDEX_RED_BUTTON]->setOrigin(50, 50);
	this->buttons[INDEX_RED_BUTTON]->setPosition(RED_POSITION_X, BUTTON_POSITION_Y);

	this->buttons.push_back(new sf::Sprite());
	this->buttons[INDEX_YELLOW_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonYellow());
	this->buttons[INDEX_YELLOW_BUTTON]->setOrigin(50, 50);
	this->buttons[INDEX_YELLOW_BUTTON]->setPosition(YELLOW_POSITION_X, BUTTON_POSITION_Y);

	this->buttons.push_back(new sf::Sprite());
	this->buttons[INDEX_BLUE_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonBlue());
	this->buttons[INDEX_BLUE_BUTTON]->setOrigin(50, 50);
	this->buttons[INDEX_BLUE_BUTTON]->setPosition(BLUE_POSITION_X, BUTTON_POSITION_Y);

	this->buttons.push_back(new sf::Sprite());
	this->buttons[INDEX_ORANGE_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonOrange());
	this->buttons[INDEX_ORANGE_BUTTON]->setOrigin(50, 50);
	this->buttons[INDEX_ORANGE_BUTTON]->setPosition(ORANGE_POSITION_X, BUTTON_POSITION_Y);

	this->soundBadNotes.push_back(new sf::Sound());
	this->soundBadNotes[0]->setBuffer(*this->gameInstance->GetResourceManager()->GetBufferBadNote1());
	this->soundBadNotes[0]->setVolume(100);

	this->soundBadNotes.push_back(new sf::Sound());
	this->soundBadNotes[1]->setBuffer(*this->gameInstance->GetResourceManager()->GetBufferBadNote2());
	this->soundBadNotes[1]->setVolume(100);

	this->soundBadNotes.push_back(new sf::Sound());
	this->soundBadNotes[2]->setBuffer(*this->gameInstance->GetResourceManager()->GetBufferBadNote3());
	this->soundBadNotes[2]->setVolume(100);

	this->soundBadNotes.push_back(new sf::Sound());
	this->soundBadNotes[3]->setBuffer(*this->gameInstance->GetResourceManager()->GetBufferBadNote4());
	this->soundBadNotes[3]->setVolume(100);

	this->soundBadNotes.push_back(new sf::Sound());
	this->soundBadNotes[4]->setBuffer(*this->gameInstance->GetResourceManager()->GetBufferBadNote5());
	this->soundBadNotes[4]->setVolume(100);

	this->rockMeter = new sf::Sprite();
	this->rockMeter->setTexture(*this->gameInstance->GetResourceManager()->GetTextureRockMeter());
	this->rockMeter->setOrigin(50, 50);
	this->rockMeter->setPosition(100, 350);
	this->rockMeter->setScale(0.60f, 0.60f);

	this->player = new Player(this->buttons, game);
	this->backCount = new sf::Text();
	this->background = new sf::RectangleShape();
	this->track = new sf::RectangleShape();
	this->track_2 = new sf::RectangleShape();
	this->sound = new sf::Sound();
	this->pauseMenu = new PauseMenu(game);
	this->loadingScreen = new LoadingScreen(game);
	this->lossScreen = new LossScreen(game);
	this->winScreen = new WinScreen(game, player);
	this->publicHappySound = new sf::Sound();
	this->publicAngrySound = new sf::Sound();
	this->disc = new sf::Sprite();
	this->circleTime = new sf::CircleShape(5);
	this->lineTime = new sf::RectangleShape();
	this->timeText = new sf::Text();

	this->circleTime->setFillColor(sf::Color::Red);
	this->circleTime->setOrigin(50, 50);
	this->circleTime->setPosition(700,147.5f);

	this->lineTime->setFillColor(sf::Color::White);
	this->lineTime->setSize(sf::Vector2f(125, 5));
	this->lineTime->setOrigin(50, 50);
	this->lineTime->setPosition(700, 150);

	this->disc->setTexture(*this->gameInstance->GetResourceManager()->GetTextureDisc());
	this->disc->setOrigin(this->gameInstance->GetResourceManager()->GetTextureDisc()->getSize().x / 2.0f, this->gameInstance->GetResourceManager()->GetTextureDisc()->getSize().y / 2.0f);
	this->disc->setPosition(600, 200);
	this->disc->setScale(0.75f, 0.75f);

	this->background->setTexture(this->gameInstance->GetCurrentSong()->GetBackground());
	this->background->setSize(sf::Vector2f(128, 128));
	this->background->setPosition(600, 300);

	this->track->setTexture(this->gameInstance->GetResourceManager()->GetTextureTrack());
	this->track->setPosition(320, 0);
	this->track->setOrigin(50, 50);
	this->track->setSize(sf::Vector2f(278, 900));

	this->track_2->setTexture(this->gameInstance->GetResourceManager()->GetTextureTrack());
	this->track_2->setPosition(320, 1024);
	this->track_2->setOrigin(50, 50);
	this->track_2->setSize(sf::Vector2f(278, 900));

	this->rigthLine = new sf::RectangleShape();
	this->rigthLine->setFillColor(sf::Color::White);
	this->rigthLine->setPosition(320, 0);
	this->rigthLine->setOrigin(50, 50);
	this->rigthLine->setSize(sf::Vector2f(10, 700));

	this->leftLine = new sf::RectangleShape();
	this->leftLine->setFillColor(sf::Color::White);
	this->leftLine->setPosition(590, 0);
	this->leftLine->setOrigin(50, 50);
	this->leftLine->setSize(sf::Vector2f(10, 700));

	this->buttonLine = new sf::RectangleShape();
	this->buttonLine->setFillColor(sf::Color::White);
	this->buttonLine->setPosition(330, 555);
	this->buttonLine->setOrigin(50, 50);
	this->buttonLine->setSize(sf::Vector2f(260, 15));

	this->trastes.push_back(new sf::RectangleShape());
	this->trastes[0]->setFillColor(sf::Color::White);
	this->trastes[0]->setPosition(GREEN_POSITION_X + 20, 0);
	this->trastes[0]->setOrigin(50, 50);
	this->trastes[0]->setSize(sf::Vector2f(10, 600));

	this->trastes.push_back(new sf::RectangleShape());
	this->trastes[1]->setFillColor(sf::Color::White);
	this->trastes[1]->setPosition(RED_POSITION_X + 20, 0);
	this->trastes[1]->setOrigin(50, 50);
	this->trastes[1]->setSize(sf::Vector2f(10, 600));
	
	this->trastes.push_back(new sf::RectangleShape());
	this->trastes[2]->setFillColor(sf::Color::White);
	this->trastes[2]->setPosition(YELLOW_POSITION_X + 20, 0);
	this->trastes[2]->setOrigin(50, 50);
	this->trastes[2]->setSize(sf::Vector2f(10, 600));
	
	this->trastes.push_back(new sf::RectangleShape());
	this->trastes[3]->setFillColor(sf::Color::White);
	this->trastes[3]->setPosition(BLUE_POSITION_X + 20, 0);
	this->trastes[3]->setOrigin(50, 50);
	this->trastes[3]->setSize(sf::Vector2f(10, 600));
	
	this->trastes.push_back(new sf::RectangleShape());
	this->trastes[4]->setFillColor(sf::Color::White);
	this->trastes[4]->setPosition(ORANGE_POSITION_X + 20, 0);
	this->trastes[4]->setOrigin(50, 50);
	this->trastes[4]->setSize(sf::Vector2f(10, 600));

	this->trastes.push_back(new sf::RectangleShape());
	this->trastes[5]->setFillColor(sf::Color::White);
	this->trastes[5]->setPosition(330, 450);
	this->trastes[5]->setOrigin(50, 50);
	this->trastes[5]->setSize(sf::Vector2f(260, 15));


	this->trastes.push_back(new sf::RectangleShape());
	this->trastes[6]->setFillColor(sf::Color::White);
	this->trastes[6]->setPosition(330, 300);
	this->trastes[6]->setOrigin(50, 50);
	this->trastes[6]->setSize(sf::Vector2f(260, 15));


	this->trastes.push_back(new sf::RectangleShape());
	this->trastes[7]->setFillColor(sf::Color::White);
	this->trastes[7]->setPosition(330, 150);
	this->trastes[7]->setOrigin(50, 50);
	this->trastes[7]->setSize(sf::Vector2f(260, 15));


	this->trastes.push_back(new sf::RectangleShape());
	this->trastes[8]->setFillColor(sf::Color::White);
	this->trastes[8]->setPosition(330, 0);
	this->trastes[8]->setOrigin(50, 50);
	this->trastes[8]->setSize(sf::Vector2f(260, 15));

	this->isPause = false;
	this->loss = false;
	this->isLoading = true;
	this->startGame = false;
	this->finishThread = false;
	this->win = false;

	this->count = 3;
	this->time = 0.f;
	this->startTime = 0;
	this->gameState = GameState::INIT;

	this->defaultView = game->GetRenderWindow().getDefaultView();
	this->shakeView = this->defaultView;
	this->cameraShake = new CameraShake(this->shakeView);

	font = this->gameInstance->GetResourceManager()->GetFont();

	this->sound->setBuffer(*this->gameInstance->GetResourceManager()->GetBufferMetronome());
	
	this->publicHappySound->setBuffer(*this->gameInstance->GetResourceManager()->GetBufferPublicHappy());
	this->publicHappySound->setVolume(20);
	
	this->publicAngrySound->setBuffer(*this->gameInstance->GetResourceManager()->GetBufferPublicAngry());
	this->publicAngrySound->setVolume(20);

	this->backCount->setFont(*font);
	this->backCount->setCharacterSize(24);
	this->backCount->setString("3");
	sf::FloatRect textRect = this->backCount->getLocalBounds();
	this->backCount->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	sf::Vector2 size = this->gameInstance->GetRenderWindow().getSize();
	this->backCount->setPosition(size.x / 2, size.y / 2);
	this->backCount->setFillColor(sf::Color::White);

	this->timeText->setFont(*font);
	this->timeText->setCharacterSize(24);
	this->timeText->setString("0:00");
	this->timeText->setOrigin(50, 50);
	this->timeText->setFillColor(sf::Color::White);
	this->timeText->setPosition(750, 150);

	std::thread th([this]
		{
			this->notes.clear();
			this->gameInstance->GetCurrentSong()->GetPreviewSound()->stop();
			this->gameInstance->GetCurrentSong()->LoadSong();
			this->gameInstance->GetCurrentSong()->LoadNotes();
			this->notes = this->gameInstance->GetCurrentSong()->GetNotes();
			this->isLoading = false;
		});
	th.detach();
}

GameScreen::~GameScreen()
{
	if (this->player != nullptr)
	{
		delete this->player;
		this->player = nullptr;
	}

	if (this->cameraShake != nullptr)
	{
		delete this->cameraShake;
		this->cameraShake = nullptr;
	}

	if (this->background != nullptr)
	{
		delete this->background;
		this->background = nullptr;
	}

	if (this->track != nullptr)
	{
		delete this->track;
		this->track = nullptr;
	}
		
	if (this->sound != nullptr)
	{
		delete this->sound;
		this->sound = nullptr;
	}
	
	if (this->backCount != nullptr)
	{
		delete this->backCount;
		this->backCount = nullptr;
	}

	for (int i = 0; i < this->notes.size(); i++)
	{
		if (this->notes[i] != nullptr)
		{
			delete this->notes[i];
			this->notes[i] = nullptr;
		}
	}

	if (this->lossScreen != nullptr)
	{
		delete this->lossScreen;
		this->lossScreen = nullptr;
	}

	if (this->winScreen != nullptr)
	{
		delete this->winScreen;
		this->winScreen = nullptr;
	}

	if (this->publicHappySound != nullptr)
	{
		delete this->publicHappySound;
		this->publicHappySound = nullptr;
	}
}

TypeScreen GameScreen::SelectOption()
{
	return TypeScreen();
}

void GameScreen::StartGame()
{
	this->publicHappySound->play();
	this->backCountThread = std::thread(&GameScreen::BackCount, this);
	this->backCountThread.detach();
}

void GameScreen::BackCount()
{
	sf::Clock clock;
	this->sound->stop();
	this->sound->play();
	float time = 0;
	while (count != 0 && !this->finishThread)
	{
		if (!this->isPause)
		{
			if (this->sound->getStatus() == sf::SoundSource::Paused)
			{
				this->sound->play();
			}
			time += clock.restart().asSeconds();
			if (time > 1.0f)
			{
				count--;
				this->backCount->setString(std::to_string(count));
				time = 0.0f;
			}
		}else
		{
			this->sound->pause();
		}
	}
	
	if (this->count == 0)
	{
		this->gameInstance->GetCurrentSong()->PlaySong();
		this->SetGameState(GameState::PLAYING);
		this->finishThread = true;
	}
}

bool GameScreen::CheckLoss()
{
	if (this->player->GetPublicScore() <= 0)
	{
		if (this->player->GetScore() > this->gameInstance->GetCurrentSong()->GetScore())
		{
			this->gameInstance->GetCurrentSong()->SetScore(this->player->GetScore());
			this->gameInstance->GetCurrentSong()->SaveScore();
		}
		this->Pause();
		this->loss = true;
	}
	return true;
}

void GameScreen::DeathThread()
{
	this->gameInstance->GetGameScreen()->finishThread = true;
	if (this->gameInstance->GetGameScreen()->backCountThread.joinable())
	{
		this->gameInstance->GetGameScreen()->backCountThread.join();
	}
}

void GameScreen::Draw(sf::RenderWindow& window)
{
	if (!this->isLoading)
	{
		window.setView(this->shakeView);
		window.draw(*this->background);
		window.draw(*this->track);
		window.draw(*this->track_2);
		window.draw(*this->rockMeter);
		window.draw(*this->leftLine);
		window.draw(*this->rigthLine);
		window.draw(*this->disc);
		window.draw(*this->lineTime);
		window.draw(*this->circleTime);
		window.draw(*this->timeText);

		for (int i = 0; i < 8; i++)
		{
			window.draw(*this->trastes[i]);
		}

		this->player->Draw(window);
		for (int i = 0; i < this->buttons.size(); i++)
		{
			window.draw(*this->buttons[i]);
		}

		if (this->count > 0)
		{
			window.draw(*this->backCount);
		}

		window.setView(this->defaultView);

		for (int i = 0; i < this->notes.size(); i++)
		{
			if (this->notes[i]->isVisible)
			{
				this->notes[i]->Draw(window);
			}
		}

		if (this->GetIsPause() && !this->loss && !this->win)
		{
			this->pauseMenu->Draw(window);
		}
		else if(this->GetIsPause() && this->loss && !this->win)
		{
			this->lossScreen->Draw(window);
		}
		else if(this->GetIsPause() && !this->loss && this->win)
		{
			this->winScreen->Draw(window);
		}
	}
	else 
	{
		this->loadingScreen->Draw(window);

	}
}

void GameScreen::Update(float deltaTime)
{
	if (!this->isLoading)
	{	
		if (this->player->GetPublicScore() > 50 && this->publicHappySound->getStatus() != sf::Sound::Playing)
		{
			this->publicAngrySound->stop();
			this->publicHappySound->play();
		}
		else if (this->player->GetPublicScore() < 50 && this->publicAngrySound->getStatus() != sf::Sound::Playing)
		{
			this->publicHappySound->stop();
			this->publicAngrySound->play();
		}

		if (!this->isPause && this->startGame)
		{
			this->time += deltaTime;
			this->disc->rotate(deltaTime * 200);
			int totalDuration = this->gameInstance->GetCurrentSong()->GetSoundBuffer()->getDuration().asSeconds();
			int remainingTime = totalDuration - (int)this->time;
			if (remainingTime < 0) remainingTime = 0;
			int minutes = remainingTime / 60;
			int seconds = remainingTime % 60;
			this->timeText->setString(std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds));

			float progeso = (this->time) / this->gameInstance->GetCurrentSong()->GetSoundBuffer()->getDuration().asSeconds();
			float posX = 700 + progeso * (825 - 700);
			this->circleTime->setPosition(posX, this->circleTime->getPosition().y);
			this->track->setPosition(this->track->getPosition().x, this->track->getPosition().y + (deltaTime * 200) );
			this->track_2->setPosition(this->track_2->getPosition().x, this->track_2->getPosition().y + (deltaTime * 200));
			if (this->track->getPosition().y > 700)
			{
				this->track->setPosition(this->track->getPosition().x, -896);
			}

			if (this->track_2->getPosition().y > 700)
			{
				this->track_2->setPosition(this->track->getPosition().x, -896);
			}
			if (this->time > this->gameInstance->GetCurrentSong()->GetSoundBuffer()->getDuration().asSeconds())
			{
				this->Pause();
				this->win = true;
				if (this->player->GetScore() > this->gameInstance->GetCurrentSong()->GetScore())
				{
					this->gameInstance->GetCurrentSong()->SetScore(this->player->GetScore());
					this->gameInstance->GetCurrentSong()->SaveScore();
				}
			}
			this->player->Update(deltaTime);
			this->cameraShake->Update(deltaTime);
			for (int i = 0; i < this->notes.size(); )
			{
				if (this->notes[i]->GetCanBeDestroy())
				{
					delete this->notes[i];
					this->notes.erase(notes.begin() + i);
				}
				else {
					if (this->time > this->notes[i]->GetStartTime() && !this->notes[i]->GetCanBeDestroy())
					{
						this->notes[i]->isVisible = true;
						this->notes[i]->Update(deltaTime);
					}
					else
					{
						this->notes[i]->isVisible = false;
					}
					i++;
				}
			}
		}
		else if(this->isPause && !this->loss && !this->win)
		{
			this->pauseMenu->Update(deltaTime);
		}
		else if (this->isPause && this->loss && !this->win)
		{
			this->lossScreen->Update(deltaTime);
		}
		else if (this->isPause && this->win && !this->loss)
		{
			this->winScreen->Update(deltaTime);
		}

		if (!this->startGame)
		{
			this->StartGame();
			this->startGame = true;
		}
	}
	else 
	{
		this->loadingScreen->Update(deltaTime);
	}


}

void GameScreen::SetGameState(GameState newState)
{
	this->gameState = newState;
}

Player* GameScreen::GetPlayer()
{
	return this->player;
}

CameraShake* GameScreen::GetCameraShake()
{
	return this->cameraShake;
}

std::vector<sf::Sound*> GameScreen::GetBadSoundVector()
{
	return this->soundBadNotes;
}

bool GameScreen::GetIsPause()
{
	return this->isPause;
}

void GameScreen::ChangeIsPause()
{
	this->isPause = !this->isPause;
}

TypeScreen GameScreen::ProcessInput(sf::Event event)
{
	TypeScreen ret = TypeScreen::None;
	if (!this->isLoading)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::P)
			{
				if (!this->isPause)
				{
					this->Pause();
				}
				else
				{
					this->UnPause();
				}
			}
		}

		if (this->isPause && !this->loss && !this->win)
		{
			ret = this->pauseMenu->ProcessInput(event);
		}
		else if(this->isPause && this->loss && !this->win)
		{
			ret = this->lossScreen->ProcessInput(event);
		}
		else if (this->isPause && !this->loss && this->win)
		{
			ret = this->winScreen->ProcessInput(event);
		}
		else 
		{
			this->player->Input(event);
		}
	}

	return ret;
}

void GameScreen::Pause()
{
	this->isPause = true;
	this->gameInstance->GetCurrentSong()->PauseSong();
}

void GameScreen::UnPause()
{
	this->isPause = false;
	if (!this->gameInstance->GetCurrentSong()->GetSound()->getPlayingOffset().asSeconds() == 0.0f)
	{
		this->gameInstance->GetCurrentSong()->PlaySong();
	}
}

void GameScreen::Restart()
{
	this->isLoading = true;
	this->DeathThread();
	this->notes.clear();
	this->gameInstance->GetCurrentSong()->GetSound()->stop();
	this->gameInstance->GetCurrentSong()->LoadNotes();
	this->notes = this->gameInstance->GetCurrentSong()->GetNotes();
	this->buttons[INDEX_GREEN_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonGreen());
	this->buttons[INDEX_RED_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonRed());
	this->buttons[INDEX_YELLOW_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonYellow());
	this->buttons[INDEX_BLUE_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonBlue());
	this->buttons[INDEX_ORANGE_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonOrange());
	this->buttons[INDEX_GREEN_BUTTON]->setColor(sf::Color::White);
	this->buttons[INDEX_RED_BUTTON]->setColor(sf::Color::White);
	this->buttons[INDEX_YELLOW_BUTTON]->setColor(sf::Color::White);
	this->buttons[INDEX_BLUE_BUTTON]->setColor(sf::Color::White);
	this->buttons[INDEX_ORANGE_BUTTON]->setColor(sf::Color::White);
	this->player->ResetPublicScore();
	this->player->SetStrikeNotes(0);
	this->player->SetScore(0);
	this->player->SetHitNotes(0);
	this->player->SetMissNotes(0);
	this->player->SetFailNotes(0);
	this->player->SetDoblePoints(false);
	this->player->SetTimerDoblePoints(0.0f);
	this->player->SetDeathThreadDoblePoints(false);
	this->player->DeathThreadDoblePoints();
	this->backCount->setString("3");
	this->loss = false;
	this->win = false;
	this->isPause = false;
	this->count = 3;
	this->time = 0.f;
	this->publicAngrySound->stop();
	this->publicHappySound->stop();
	this->startTime = 0;
	this->gameState = GameState::INIT;
	this->finishThread = false;
	this->isLoading = false;
	this->startGame = false;
}
