#pragma once
#include "Headers.h"

//** 穿号識情
class Player;
class Monster;

class Stage
{
public:
	Stage();	//** 持失切
	~Stage();	//** 社瑚切
private:
	Player* p;
	Monster* m;
public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
};

