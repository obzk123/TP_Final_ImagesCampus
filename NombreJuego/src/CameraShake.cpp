#include "CameraShake.h"


CameraShake::CameraShake(sf::View& view) : view(view), shakeDuration(0.0f), elapsedTime(0.0f)
{
    this->shakeMagnitude = 0.0f;
    this->originalCenter = view.getCenter(); // Guarda el centro original de la vista
}

void CameraShake::startShake(float duration, float magnitude) 
{
    shakeDuration = duration;
    shakeMagnitude = magnitude;
    elapsedTime = 0.0f;
    originalCenter = view.getCenter();
}

void CameraShake::Update(float deltaTime) 
{
    if (elapsedTime < shakeDuration) {
        elapsedTime += deltaTime;

        // Generar desplazamientos aleatorios en x e y
        float offsetX = ((rand() % 100) / 100.0f - 0.5f) * 2 * shakeMagnitude;
        float offsetY = ((rand() % 100) / 100.0f - 0.5f) * 2 * shakeMagnitude;

        // Aplicar la sacudida a la vista
        view.setCenter(originalCenter.x + offsetX, originalCenter.y + offsetY);
    }
    else {
        // Restaurar la vista a su posición original
        view.setCenter(originalCenter);
    }
}

