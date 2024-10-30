#pragma once
#include "GameObject.h"

class CameraShake : public GameObject
{
public:
    CameraShake(sf::View& view);
    void startShake(float duration, float magnitude);
    void Update(float deltatime) override;
private:
    sf::View& view;
    float shakeDuration;
    float elapsedTime;
    float shakeMagnitude;
    sf::Vector2f originalCenter;
};

