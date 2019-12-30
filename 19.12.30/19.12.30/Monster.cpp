#include "Monster.h"


void Monster::Initialize()
{
	Att = 10;
	Def = 10;
}

void Monster::Progress()
{

}

void Monster::Render()
{
	cout << "Monster Att : " << Att << endl;
	cout << "Monster Def : " << Def << endl;
}

void Monster::Release()
{

}
