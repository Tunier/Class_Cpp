#pragma once
#include "Headers.h"

class Player;
class Monster;

class Stage
{
public:
	Stage();
	~Stage();
private:
	Player* p;
	Player* m;
public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
};

