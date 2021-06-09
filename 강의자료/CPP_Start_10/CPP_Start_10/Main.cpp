#include "Headers.h"
#include "MainUpdate.h"



#include "Player.h"
#include "Monster.h"

template <typename T>
class Test
{
public:
	static Object* CreateObject()
	{
		Object* pObj = new T;
		pObj->Initialize();

		return pObj;
	}
};


int main(void)
{
	/*
	Test <Player>t1;
	Object* pObj1 = t1.CreateObject();
	pObj1->Render();


	Object* pt = Test<Monster>::CreateObject();
	*/



	
	MainUpdate Main;
	Main.Initialize();

	DWORD dwTime = GetTickCount();

	while (true)
	{
		if (dwTime < GetTickCount())
		{
			dwTime = GetTickCount();
			system("cls");

			Main.Update();
			Main.Render();
		}
	}
	

	return 0;
}
