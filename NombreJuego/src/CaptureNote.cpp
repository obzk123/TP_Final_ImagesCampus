#include "CaptureNote.h"

CaptureNote::CaptureNote(int notaIndex, float initialTime, float endTime, int isSpecial)
{
	this->notaIndex = notaIndex;
	this->initialTime = initialTime;
	this->endTime = endTime;
	this->isSpecial = isSpecial;
}
