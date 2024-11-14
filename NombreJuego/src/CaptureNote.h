#pragma once
#include "GameObject.h"

class CaptureNote : public GameObject
{
public:
	CaptureNote(int notaIndex, float initialTime, float endTime, int isSpecial);
	int notaIndex;
	float initialTime;
	float endTime;
	int isSpecial;
};

