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
#include "CaptureNote.h"

GameScreen::GameScreen(Game* game, int volumeFx)
{
	this->gameInstance = game;
	this->volumeFx = volumeFx;
	this->sizeX = this->gameInstance->GetRenderWindow().getSize().x;
	this->sizeY = this->gameInstance->GetRenderWindow().getSize().y;

	this->buttons.push_back(new sf::Sprite());
	this->buttons[INDEX_GREEN_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonGreen());
	this->buttons[INDEX_GREEN_BUTTON]->setOrigin(this->gameInstance->GetResourceManager()->GetTextureButtonGreen()->getSize().x / 2, 
													this->gameInstance->GetResourceManager()->GetTextureButtonGreen()->getSize().y / 2);
	this->buttons[INDEX_GREEN_BUTTON]->setPosition(sizeX * GREEN_POSITION_X, sizeY * BUTTON_POSITION_Y);

	this->buttons.push_back(new sf::Sprite());
	this->buttons[INDEX_RED_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonRed());
	this->buttons[INDEX_RED_BUTTON]->setOrigin(this->gameInstance->GetResourceManager()->GetTextureButtonRed()->getSize().x / 2,
													this->gameInstance->GetResourceManager()->GetTextureButtonRed()->getSize().y / 2);
	this->buttons[INDEX_RED_BUTTON]->setPosition(sizeX * RED_POSITION_X, sizeY * BUTTON_POSITION_Y);

	this->buttons.push_back(new sf::Sprite());
	this->buttons[INDEX_YELLOW_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonYellow());
	this->buttons[INDEX_YELLOW_BUTTON]->setOrigin(this->gameInstance->GetResourceManager()->GetTextureButtonYellow()->getSize().x / 2,
													this->gameInstance->GetResourceManager()->GetTextureButtonYellow()->getSize().y / 2);
	this->buttons[INDEX_YELLOW_BUTTON]->setPosition(sizeX * YELLOW_POSITION_X, sizeY * BUTTON_POSITION_Y);

	this->buttons.push_back(new sf::Sprite());
	this->buttons[INDEX_BLUE_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonBlue());
	this->buttons[INDEX_BLUE_BUTTON]->setOrigin(this->gameInstance->GetResourceManager()->GetTextureButtonBlue()->getSize().x / 2,
													this->gameInstance->GetResourceManager()->GetTextureButtonBlue()->getSize().y / 2);
	this->buttons[INDEX_BLUE_BUTTON]->setPosition(sizeX * BLUE_POSITION_X, sizeY * BUTTON_POSITION_Y);

	this->buttons.push_back(new sf::Sprite());
	this->buttons[INDEX_ORANGE_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonOrange());
	this->buttons[INDEX_ORANGE_BUTTON]->setOrigin(this->gameInstance->GetResourceManager()->GetTextureButtonOrange()->getSize().x / 2,
													this->gameInstance->GetResourceManager()->GetTextureButtonOrange()->getSize().y / 2);
	this->buttons[INDEX_ORANGE_BUTTON]->setPosition(sizeX * ORANGE_POSITION_X, sizeY * BUTTON_POSITION_Y);

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
	this->rockMeter->setOrigin(this->gameInstance->GetResourceManager()->GetTextureRockMeter()->getSize().x / 2,
									this->gameInstance->GetResourceManager()->GetTextureRockMeter()->getSize().y / 2);
	this->rockMeter->setPosition(sizeX * 0.20f, sizeY * 0.70f);
	this->rockMeter->setScale(0.60f, 0.60f);

	this->player = new Player(this->buttons, game);
	this->backCount = new sf::Text();
	this->background = new sf::Sprite();
	this->background_2 = new sf::Sprite();
	this->track = new sf::RectangleShape();
	this->track_2 = new sf::RectangleShape();
	this->sound = new sf::Sound();
	this->loadingScreen = new LoadingScreen(game);
	this->lossScreen = new LossScreen(game);
	this->winScreen = new WinScreen(game, player);
	sf::FloatRect textRect;

	this->publicHappySound = new sf::Sound();
	this->publicAngrySound = new sf::Sound();
	this->publicHappySound->setBuffer(*this->gameInstance->GetResourceManager()->GetBufferPublicHappy());
	this->publicHappySound->setVolume(this->volumeFx);
	this->publicAngrySound->setBuffer(*this->gameInstance->GetResourceManager()->GetBufferPublicAngry());
	this->publicAngrySound->setVolume(this->volumeFx);

	this->disc = new sf::Sprite();
	this->circleTime = new sf::CircleShape(5);
	this->lineTime = new sf::RectangleShape();
	this->timeText = new sf::Text();
	

	this->circleTime->setFillColor(sf::Color::Red);
	textRect = this->circleTime->getGlobalBounds();
	this->circleTime->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	this->circleTime->setPosition(this->sizeX * 0.72f, this->sizeY * 0.58f);

	this->lineTime->setFillColor(sf::Color::White);
	this->lineTime->setSize(sf::Vector2f(200, 5));
	this->lineTime->setOrigin(this->lineTime->getSize().x / 2.0f, this->lineTime->getSize().y / 2.0f);
	this->lineTime->setPosition(this->sizeX * 0.80f, this->sizeY * 0.58f);

	this->disc->setTexture(*this->gameInstance->GetResourceManager()->GetTextureDisc());
	this->disc->setScale(1.75f, 1.75f);
	this->disc->setOrigin(this->gameInstance->GetResourceManager()->GetTextureDisc()->getSize().x / 2.0f, this->gameInstance->GetResourceManager()->GetTextureDisc()->getSize().y / 2.0f);
	this->disc->setPosition(this->sizeX * 0.80f, this->sizeY * 0.75f);

	this->albumImage = new sf::RectangleShape(sf::Vector2f(150.0f,150.0f));
	this->albumImage->setTexture(this->gameInstance->GetCurrentSong()->GetImage());
	this->albumImage->setOrigin(150.0f / 2.0f, 150.0f / 2.0f);
	this->albumImage->setPosition(this->sizeX * 0.80f, this->sizeY * 0.75f);

	this->background->setTexture(*this->gameInstance->GetResourceManager()->GetTextureBackground());
	this->background->setPosition(0, 0);

	this->background_2->setTexture(*this->gameInstance->GetResourceManager()->GetTextureBackground_2());
	this->background_2->setPosition(this->gameInstance->GetResourceManager()->GetTextureBackground()->getSize().x, 0);

	this->track->setTexture(this->gameInstance->GetResourceManager()->GetTextureTrack());
	this->track->setSize(sf::Vector2f(sizeX * 0.25f, sizeY));
	this->track->setOrigin(this->track->getSize().x / 2, this->track->getSize().y / 2);
	this->track->setPosition(sizeX / 2, sizeY / 2);

	this->track_2->setTexture(this->gameInstance->GetResourceManager()->GetTextureTrack());
	this->track_2->setSize(sf::Vector2f(sizeX * 0.25f, sizeY));
	this->track_2->setOrigin(this->track_2->getSize().x / 2, this->track_2->getSize().y / 2);
	this->track_2->setPosition(sizeX / 2, -(sizeY / 2) );

	this->rigthLine = new sf::RectangleShape();
	this->rigthLine->setFillColor(sf::Color(21, 28, 28));
	this->rigthLine->setSize(sf::Vector2f(5, sizeY));
	this->rigthLine->setOrigin(this->rigthLine->getSize().x / 2, this->rigthLine->getSize().y / 2);
	this->rigthLine->setPosition(800, this->sizeY / 2);

	this->leftLine = new sf::RectangleShape();
	this->leftLine->setFillColor(sf::Color(21, 28, 28));
	this->leftLine->setSize(sf::Vector2f(5, sizeY));
	this->leftLine->setOrigin(this->leftLine->getSize().x / 2, this->leftLine->getSize().y / 2);
	this->leftLine->setPosition(480, this->sizeY / 2);


	this->lines.push_back(new sf::RectangleShape());
	this->lines[0]->setFillColor(sf::Color(21, 28, 28));
	this->lines[0]->setSize(sf::Vector2f(5, sizeY));
	this->lines[0]->setOrigin(this->lines[0]->getSize().x / 2, this->lines[0]->getSize().y / 2);
	this->lines[0]->setPosition(this->sizeX / 2 - 95, this->sizeY / 2 );

	this->lines.push_back(new sf::RectangleShape());
	this->lines[1]->setFillColor(sf::Color(21, 28, 28));
	this->lines[1]->setSize(sf::Vector2f(5, sizeY));
	this->lines[1]->setOrigin(this->lines[1]->getSize().x / 2, this->lines[1]->getSize().y / 2);
	this->lines[1]->setPosition(this->sizeX / 2 - 30, this->sizeY / 2);

	this->lines.push_back(new sf::RectangleShape());
	this->lines[2]->setFillColor(sf::Color(21, 28, 28));
	this->lines[2]->setSize(sf::Vector2f(5, sizeY));
	this->lines[2]->setOrigin(this->lines[2]->getSize().x / 2, this->lines[2]->getSize().y / 2);
	this->lines[2]->setPosition(this->sizeX / 2 + 30, this->sizeY / 2);

	this->lines.push_back(new sf::RectangleShape());
	this->lines[3]->setFillColor(sf::Color(21, 28, 28));
	this->lines[3]->setSize(sf::Vector2f(5, sizeY));
	this->lines[3]->setOrigin(this->lines[3]->getSize().x / 2, this->lines[3]->getSize().y / 2);
	this->lines[3]->setPosition(this->sizeX / 2 + 95, this->sizeY / 2);

	this->lines.push_back(new sf::RectangleShape());
	this->lines[4]->setFillColor(sf::Color(21, 28, 28));
	this->lines[4]->setSize(sf::Vector2f(325, 5));
	this->lines[4]->setOrigin(this->lines[4]->getSize().x / 2, this->lines[4]->getSize().y / 2);
	this->lines[4]->setPosition(this->sizeX / 2, 655);

	this->lines.push_back(new sf::RectangleShape());
	this->lines[5]->setFillColor(sf::Color(21, 28, 28));
	this->lines[5]->setSize(sf::Vector2f(325, 5));
	this->lines[5]->setOrigin(this->lines[5]->getSize().x / 2, this->lines[5]->getSize().y / 2);
	this->lines[5]->setPosition(this->sizeX / 2, 715);

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
	
	this->backCount->setFont(*font);
	this->backCount->setCharacterSize(24);
	this->backCount->setString("3");
	textRect = this->backCount->getLocalBounds();
	this->backCount->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	sf::Vector2 size = this->gameInstance->GetRenderWindow().getSize();
	this->backCount->setPosition(size.x / 2, size.y / 2);
	this->backCount->setFillColor(sf::Color::White);

	this->timeText->setFont(*font);
	this->timeText->setCharacterSize(36);
	this->timeText->setString("0:00");
	textRect = this->timeText->getGlobalBounds();
	this->timeText->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	this->timeText->setFillColor(sf::Color::White);
	this->timeText->setPosition(this->sizeX * 0.803f, this->sizeY * 0.55f);
	

	this->KeyQ = new sf::Sprite();
	this->KeyQ->setTexture(*this->gameInstance->GetResourceManager()->GetTextureKeyQ());
	this->KeyQ->setOrigin(this->KeyQ->getTexture()->getSize().x / 2.0f, this->KeyQ->getTexture()->getSize().y / 2.0f);
	this->KeyQ->setPosition(this->sizeX * 0.70f, this->sizeY * 0.30f);

	this->KeyW = new sf::Sprite();
	this->KeyW->setTexture(*this->gameInstance->GetResourceManager()->GetTextureKeyW());
	this->KeyW->setOrigin(this->KeyW->getTexture()->getSize().x / 2.0f, this->KeyW->getTexture()->getSize().y / 2.0f);
	this->KeyW->setPosition(this->sizeX * 0.75f, this->sizeY * 0.30f);

	this->KeyE = new sf::Sprite();
	this->KeyE->setTexture(*this->gameInstance->GetResourceManager()->GetTextureKeyE());
	this->KeyE->setOrigin(this->KeyE->getTexture()->getSize().x / 2.0f, this->KeyE->getTexture()->getSize().y / 2.0f);
	this->KeyE->setPosition(this->sizeX * 0.80f, this->sizeY * 0.30f);

	this->KeyR = new sf::Sprite();
	this->KeyR->setTexture(*this->gameInstance->GetResourceManager()->GetTextureKeyR());
	this->KeyR->setOrigin(this->KeyR->getTexture()->getSize().x / 2.0f, this->KeyR->getTexture()->getSize().y / 2.0f);
	this->KeyR->setPosition(this->sizeX * 0.85f, this->sizeY * 0.30f);

	this->KeyT = new sf::Sprite();
	this->KeyT->setTexture(*this->gameInstance->GetResourceManager()->GetTextureKeyT());
	this->KeyT->setOrigin(this->KeyT->getTexture()->getSize().x / 2.0f, this->KeyT->getTexture()->getSize().y / 2.0f);
	this->KeyT->setPosition(this->sizeX * 0.90f, this->sizeY * 0.30f);

	this->explain = new sf::Text();
	this->explain->setFont(*font);
	this->explain->setCharacterSize(36);
	this->explain->setString("How to play");
	textRect = this->explain->getGlobalBounds();
	this->explain->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	this->explain->setFillColor(sf::Color::White);
	this->explain->setPosition(this->sizeX * 0.805f, this->sizeY * 0.23f);

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
	if (this->pauseMenu == nullptr)
	{
		this->pauseMenu = new PauseMenu(this->gameInstance);
	}
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
		window.draw(*this->background_2);
		window.draw(*this->track);
		window.draw(*this->track_2);
		window.draw(*this->rockMeter);
		window.draw(*this->leftLine);
		window.draw(*this->rigthLine);
		window.draw(*this->disc);
		window.draw(*this->albumImage);
		window.draw(*this->lineTime);
		window.draw(*this->circleTime);
		window.draw(*this->timeText);
		window.draw(*this->KeyQ);
		window.draw(*this->KeyW);
		window.draw(*this->KeyE);
		window.draw(*this->KeyR);
		window.draw(*this->KeyT);
		window.draw(*this->explain);

		for (int i = 0; i < this->lines.size(); i++)
		{
			window.draw(*this->lines[i]);
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
	float speed = -100.0f;
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
			this->background->move(sf::Vector2f(speed * deltaTime, 0));
			this->background_2->move(sf::Vector2f(speed * deltaTime, 0));
			if (this->background->getPosition().x + this->background->getTexture()->getSize().x < 0) 
			{
				this->background->setPosition(this->background_2->getPosition().x + this->background->getTexture()->getSize().x, 0);
			}
			if (this->background_2->getPosition().x + this->background_2->getTexture()->getSize().x < 0) 
			{
				this->background_2->setPosition(this->background->getPosition().x + this->background->getTexture()->getSize().x, 0);
			}

			this->time += deltaTime;
			this->disc->rotate(deltaTime * 200);
			int totalDuration = this->gameInstance->GetCurrentSong()->GetSoundBuffer()->getDuration().asSeconds();
			int remainingTime = totalDuration - (int)this->time;
			if (remainingTime < 0) remainingTime = 0;
			int minutes = remainingTime / 60;
			int seconds = remainingTime % 60;
			this->timeText->setString(std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds));

			float progreso = this->time / this->gameInstance->GetCurrentSong()->GetSoundBuffer()->getDuration().asSeconds();
			// Interpolación lineal entre 0.72 * sizeX y 0.88 * sizeX
			float posX = this->sizeX * (0.72f + progreso * (0.88f - 0.72f));
			// Mueve el círculo a la nueva posición (en X)
			float deltaX = posX - this->circleTime->getPosition().x;  // Calcula el desplazamiento necesario
			this->circleTime->move(deltaX, 0);  // Aplica el desplazamiento
			
			this->track->move(sf::Vector2f(0, -speed * deltaTime));
			this->track_2->move(sf::Vector2f(0, -speed * deltaTime));
			// Reiniciar posición si un fondo sale de la pantalla
			if (this->track->getPosition().y >= this->track->getSize().y + this->sizeY / 2)
			{
				/*std::cout << this->track->getPosition().y << " + " << this->track_2->getPosition().y << std::endl;*/
				this->track->setPosition(sizeX / 2, this->track_2->getPosition().y - this->track->getSize().y);
			}
			if (this->track_2->getPosition().y >= this->track_2->getSize().y + this->sizeY / 2)
			{
				this->track_2->setPosition(sizeX / 2, this->track->getPosition().y - this->track_2->getSize().y);
			}

			//Win condition
			if (this->time > this->gameInstance->GetCurrentSong()->GetSoundBuffer()->getDuration().asSeconds() + 3.0f)
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
			
			if (!this->captureMode)
			{
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
				if (!this->loss && !this->win)
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
	this->capturesNotes.clear();
}

void GameScreen::SaveCaptureMode()
{
	// Abrimos el archivo para escritura
	std::ofstream outFile("notes.ini");
	if (!outFile) 
	{
		std::cerr << "No se pudo abrir el archivo para escritura." << std::endl;
	}

	// Guardamos cada elemento del vector en el archivo
	for (int i = 0; i < this->capturesNotes.size(); i ++) 
	{
		outFile << this->capturesNotes[i]->notaIndex << "," << this->capturesNotes[i]->initialTime << "," << this->capturesNotes[i]->endTime << "," << this->capturesNotes[i]->isSpecial << "\n";
	}

	// Cerramos el archivo
	outFile.close();
	std::cout << "Datos guardados en captureNotes.txt" << std::endl;
}
