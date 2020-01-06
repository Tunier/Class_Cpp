#include "Headers.h"

#include "Object.h"
#include "Player.h"
#include "Monster.h"
#include "Bullet.h"

/*
   추상화
*/

int main(void)
{
	/*
	Player* pPlayer = new Player;

	pPlayer->Initialize();

	pPlayer->Update();
	pPlayer->Render();


	Monster* pMonster = new Monster;

	pMonster->Initialize();

	pMonster->Update();
	pMonster->Render();
	*/

	/* Ojbect 로 추상화
	
	Object* pPlayer = new Player;

	pPlayer->Initialize();

	pPlayer->Update();
	pPlayer->Render();


	Object* pMonster = new Monster;

	pMonster->Initialize();

	pMonster->Update();
	pMonster->Render();
	*/

	Object* pObj[3];

	pObj[0] = new Player;
	pObj[0]->Initialize();

	pObj[0]->Update();
	pObj[0]->Render();

	pObj[1] = new Monster;
	pObj[1]->Initialize();

	pObj[1]->Update();
	pObj[1]->Render();

	pObj[2] = new Bullet;
	pObj[2]->Initialize();

	pObj[2]->Update();
	pObj[2]->Render();



	for (int i = 0; i < 3; ++i)
	{
		delete pObj[i];
		pObj[i] = NULL;
	}
	/*
	delete pMonster;
	pMonster = NULL;*/
	// 스택의 개념 filo
	// 모든 클레스는 객체가 아니다. ex) 추상클레스 / 모든 객체는 클레스다.

	return 0;
}