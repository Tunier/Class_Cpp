#pragma once
#include "Headers.h"

//** ���漱��
class Player;
class Monster;

class Stage
{
public:
	Stage();	//** ������
	~Stage();	//** �Ҹ���
private:
	Player* p;
	Monster* m;
public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
};

