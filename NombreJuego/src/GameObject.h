#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <atomic>
#include <thread>
#include <vector>
#include "Settings.h"
#include <algorithm> 

class GameObject
{
public:
	virtual void Update(float deltaTime) { } ;
	virtual void Draw(sf::RenderWindow& render) { };
	bool isVisible = true;
};

