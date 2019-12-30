#pragma once
#include "Headers.h"

class Monster
{
private:
	int Att;
	int Def;

public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
};