#include "Monster.h"

Monster::Monster()
{
	cout << "Monster:: 持失切" << endl;
}

Monster::~Monster()
{
	Release();

	cout << "Monster:: 社瑚切" << endl;
}

void Monster::Initialize()
{
	cout << "Monster::Initialize" << endl;
	Att = 100;
	Def = 100;
}

void Monster::Progress()
{
	cout << "Monster::Progress" << endl;
}

void Monster::Render()
{
	cout << "Monster::Render" << endl;

	cout << "Monster Att : " << Att << endl;
	cout << "Monster Def : " << Def << endl;
}

void Monster::Release()
{
	cout << "Monster::Release" << endl;
}
