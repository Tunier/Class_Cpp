#pragma once
#include "Headers.h"

class Player
{
public:
	Player();
	~Player();
private:
	int Att;
	int Def;
public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
};

