#pragma once

#include "Screens.h"

enum class ConfigOptions : int
{
	None = 0,
	Resolution = 1,
	Audio = 2,
	ScreenMode = 3,
	Back = 4
};

class ConfigMenu : public Screens
{
public:
	ConfigMenu(Game* gameInstance);
	~ConfigMenu();
	TypeScreen SelectOption() override;
	TypeScreen ProcessInput(sf::Event event) override;
};

