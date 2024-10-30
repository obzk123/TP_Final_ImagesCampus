#include "Player.h"
#include "Note.h"
#include "Game.h"
#include "ResourceManager.h"
#include "CameraShake.h"
#include "GameScreen.h"

Player::Player(std::vector<sf::Sprite*>& buttons, Game* game) : buttonsRef(buttons)
{
	this->gameInstance = game;
	this->check = -1;
	this->isPressed = false;
	this->strikeNotes = 0;
	this->score = 0;
	this->publicScore = 50;
	this->hitNotes = 0;
	this->missNotes = 0;
	this->failNotes = 0;
	this->timerDoblePoints = 0.0f;
	this->doblePoints = false;
	this->deadThreadDoblePoints = false;

	this->font = this->gameInstance->GetResourceManager()->GetFont();

	this->strikeText = new sf::Text();
	this->strikeText->setFont(*this->font);
	this->strikeText->setFillColor(sf::Color::White);
	this->strikeText->setString("Strike: 0");
	this->strikeText->setOrigin(50, 50);
	this->strikeText->setPosition(137,493);

	this->scoreText = new sf::Text();
	this->scoreText->setFont(*this->font);
	this->scoreText->setFillColor(sf::Color::White);
	this->scoreText->setString("Score: 0");
	this->scoreText->setOrigin(50, 50);
	this->scoreText->setPosition(137, 330);
	
	this->arrowSprite = new sf::Sprite();
	this->arrowSprite->setTexture(*this->gameInstance->GetResourceManager()->GetTextureArrow());
	this->arrowSprite->setPosition(138, 401);
	this->arrowSprite->setScale(0.85f, 0.70f);
	this->arrowSprite->setOrigin(this->gameInstance->GetResourceManager()->GetTextureArrow()->getSize().x / 2.0f, this->gameInstance->GetResourceManager()->GetTextureArrow()->getSize().y);
	this->arrowSprite->setRotation(0.0f);

	this->timerPoints = new sf::Text();
	this->timerPoints->setFont(*this->font);
	this->timerPoints->setFillColor(sf::Color::White);
	this->timerPoints->setString("Time: " + std::to_string(this->timerDoblePoints));
	this->timerPoints->setOrigin(50, 50);
	this->timerPoints->setPosition(138, 280);
}

Player::~Player()
{
	if (this->strikeText != nullptr)
	{
		delete this->strikeText;
		this->strikeText = nullptr;
	}

	if (this->scoreText != nullptr)
	{
		delete this->scoreText;
		this->scoreText = nullptr;
	}

	if (this->arrowSprite != nullptr)
	{
		delete this->arrowSprite;
		this->arrowSprite = nullptr;
	}

}

void Player::Draw(sf::RenderWindow& window)
{
	if (this->strikeNotes >= 0)
	{
		window.draw(*this->strikeText);
	}
	window.draw(*this->scoreText);
	window.draw(*this->arrowSprite);

	if (this->timerDoblePoints > 0.0f)
	{
		window.draw(*this->timerPoints);
	}

}

void Player::Update(float deltaTime)
{
	this->deltaTime = deltaTime;
	this->strikeText->setString("Strike: " + std::to_string(this->strikeNotes));
	this->scoreText->setString("Score: " + std::to_string(this->score));
	float minRotation = -55.0f;
	float maxRotation = 55.0f;
	float newRotation = minRotation + (this->publicScore / 100.0f) * (maxRotation - minRotation);
	this->arrowSprite->setRotation(newRotation);	
	std::snprintf(this->buffer, sizeof(this->buffer), "Time: %.2f", this->timerDoblePoints.load());
	this->timerPoints->setString(this->buffer);
}

void Player::Input(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Q)
		{
			this->buttonsRef[INDEX_GREEN_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonPressGreen());
			check = this->CheckNote(*this->buttonsRef[INDEX_GREEN_BUTTON]);
			if (check != -1)
			{
				HitNote(INDEX_GREEN_BUTTON);
			}
			else
			{
				MissNote(INDEX_GREEN_BUTTON);
			}
		}
		if (event.key.code == sf::Keyboard::W)
		{
			this->buttonsRef[INDEX_RED_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonPressRed());
			check = this->CheckNote(*this->buttonsRef[INDEX_RED_BUTTON]);
			if (check != -1)
			{
				HitNote(INDEX_RED_BUTTON);
			}
			else
			{
				MissNote(INDEX_RED_BUTTON);
			}
		}
		if (event.key.code == sf::Keyboard::E)
		{
			this->buttonsRef[INDEX_YELLOW_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonPressYellow());
			check = this->CheckNote(*this->buttonsRef[INDEX_YELLOW_BUTTON]);
			if (check != -1)
			{
				HitNote(INDEX_YELLOW_BUTTON);
			}
			else
			{
				MissNote(INDEX_YELLOW_BUTTON);
			}
		}
		if (event.key.code == sf::Keyboard::R)
		{
			this->buttonsRef[INDEX_BLUE_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonPressBlue());
			check = this->CheckNote(*this->buttonsRef[INDEX_BLUE_BUTTON]);
			if (check != -1)
			{
				HitNote(INDEX_BLUE_BUTTON);
			}
			else
			{
				MissNote(INDEX_BLUE_BUTTON);
			}
		}
		if (event.key.code == sf::Keyboard::T)
		{
			this->buttonsRef[INDEX_ORANGE_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonPressOrange());
			check = this->CheckNote(*this->buttonsRef[INDEX_ORANGE_BUTTON]);
			if (check != -1)
			{
				HitNote(INDEX_ORANGE_BUTTON);
			}
			else 
			{
				MissNote(INDEX_ORANGE_BUTTON);
			}
		}
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::Q)
		{
			this->buttonsRef[INDEX_GREEN_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonGreen());
		}
		if (event.key.code == sf::Keyboard::W)
		{
			this->buttonsRef[INDEX_RED_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonRed());
		}
		if (event.key.code == sf::Keyboard::E)
		{
			this->buttonsRef[INDEX_YELLOW_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonYellow());
		}
		if (event.key.code == sf::Keyboard::R)
		{
			this->buttonsRef[INDEX_BLUE_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonBlue());
		}
		if (event.key.code == sf::Keyboard::T)
		{
			this->buttonsRef[INDEX_ORANGE_BUTTON]->setTexture(*this->gameInstance->GetResourceManager()->GetTextureButtonOrange());
		}
	}
}

void Player::SetStrikeNotes(int newValue)
{
	this->strikeNotes = newValue;
}

void Player::SetPublicScore(int newValue)
{
	if (newValue > MIN_PUBLIC_SCORE && this->publicScore < MAX_PUBLIC_SCORE)
	{
		this->publicScore += newValue;
		if (this->publicScore > MAX_PUBLIC_SCORE)
		{
			this->publicScore = MAX_PUBLIC_SCORE;
		}
	}
	else if (newValue < MIN_PUBLIC_SCORE && this->publicScore > MIN_PUBLIC_SCORE)
	{
		this->publicScore += newValue;
		if (this->publicScore < MIN_PUBLIC_SCORE)
		{
			this->publicScore = MIN_PUBLIC_SCORE;
		}
	}
}

void Player::ResetPublicScore()
{
	this->publicScore = 50;
}

void Player::AddScore(int value)
{
	this->score += value;
}

void Player::HitNote(int indexButton)
{
	int powerUp = this->gameInstance->GetGameScreen()->notes[check]->GetPowerUp();
	if (powerUp == 1)
	{
		this->timerDoblePoints =+ 5.0f;
		if (!this->doblePointsThread.joinable())
		{
			this->deadThreadDoblePoints = false;
			this->doblePointsThread = std::thread(&Player::ThreadDoblePoints, this);
			this->doblePointsThread.detach();
		}
		this->doblePoints = true;
	}

	this->gameInstance->GetGameScreen()->notes[check]->SetCanBeDestroy(true);
	//this->buttonsRef[indexButton]->setColor(sf::Color::Yellow);
	this->strikeNotes++;
	if (this->doblePoints)
	{
		this->AddScore(POINTS_PER_NOTE * 2);
	}
	else
	{
		this->AddScore(POINTS_PER_NOTE);
	}

	if (powerUp == 2)
	{
		this->ResetPublicScore();
	}
	else
	{
		this->SetPublicScore(POINT_PUBLIC);
	}

	this->hitNotes++;
	
}

void Player::MissNote(int indexButton)
{
	if (this->strikeNotes > SHAKE_STRAKE)
	{
		this->gameInstance->GetGameScreen()->GetCameraShake()->startShake(0.5f, 10.0f);
	}
	this->gameInstance->GetGameScreen()->GetBadSoundVector()[indexButton]->stop();
	this->gameInstance->GetGameScreen()->GetBadSoundVector()[indexButton]->play();

	this->missNotes++;
	this->strikeNotes = 0;
	this->SetPublicScore(-POINT_PUBLIC);
	this->gameInstance->GetGameScreen()->CheckLoss();
}

void Player::FailNote()
{
	if (this->strikeNotes > SHAKE_STRAKE)
	{
		this->gameInstance->GetGameScreen()->GetCameraShake()->startShake(0.5f, 10.0f);
	}
	this->failNotes++;
	this->strikeNotes = 0;
	this->SetPublicScore(-POINT_PUBLIC);
	this->gameInstance->GetGameScreen()->CheckLoss();
}

void Player::ThreadDoblePoints()
{
	while (!this->deadThreadDoblePoints)
	{
		if (!this->gameInstance->GetGameScreen()->GetIsPause())
		{
			this->timerDoblePoints = this->timerDoblePoints - this->deltaTime;
			if (this->timerDoblePoints <= 0)
			{
				this->timerDoblePoints = 0.0f;
				this->doblePoints = false;
				break;
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}	
}

void Player::DeathThreadDoblePoints()
{
	this->deadThreadDoblePoints = true;
	if (this->doblePointsThread.joinable())
	{
		this->doblePointsThread.join();
	}
}

int Player::CheckNote(sf::Sprite button)
{
	sf::FloatRect currentBounds = button.getGlobalBounds();
	for (int i = 0; i < this->gameInstance->GetGameScreen()->notes.size(); i++)
	{
		sf::FloatRect otherBounds = this->gameInstance->GetGameScreen()->notes[i]->GetSpriteNote()->getGlobalBounds();
		if (currentBounds.intersects(otherBounds)) 
		{
			return i;
		}
	}
	return -1;
}
