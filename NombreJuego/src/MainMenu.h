#pragma once

#include "Screens.h"

enum class MenuOption
{
	None = 0,
	Play = 1,
	Config = 2,
	Exit = 3
};

class MainMenu : public Screens
{
public:
	MainMenu(Game* gameInstance);
	~MainMenu();
	TypeScreen SelectOption() override;
};

