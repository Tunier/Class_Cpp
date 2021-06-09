#include "Stage.h"

#include "Player.h"
#include "Monster.h"


Stage::Stage()
{
	cout << "Stage:: 생성자" << endl;
}

Stage::~Stage()
{
	cout << "Stage:: 소멸자" << endl;
	Release();
}

void Stage::Initialize()
{
	cout << "Stage:: Initialize" << endl;

	p = new Player;
	p->Initialize();

	m = new Monster;
	m->Initialize();
}

void Stage::Progress()
{
	cout << "Stage:: Progress" << endl;
	p->Progress();
	m->Progress();
}

void Stage::Render()
{
	cout << "Stage:: Render" << endl;
	p->Render();
	m->Render();
}

void Stage::Release()
{
	cout << "Stage:: Release" << endl;

	delete p;
	p = NULL;

	if (p == NULL)
		cout << "Player 가 정상적으로 삭제되었습니다." << endl;


	delete m;
	m = NULL;

	if (m == NULL)
		cout << "Monster 가 정상적으로 삭제되었습니다." << endl;
}
