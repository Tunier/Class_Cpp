#include "Headers.h"
#include "Mainupdate.h"

#include "Player.h"
#include "Monster.h"


class Test
{
public:
	Test() {}
	~Test() {}
public:
	void Initialize() {}
	void Update() {}
	void Render() {}
	void Release() {}
public:
	template <typename T>
	Object* CreateObject()
	{
		Object* pObj = new T;
		pObj->Initialize();

		return pObj;
	}
};



int main(void)
{
	/*
	Test t;
	Object* pObj1 = t.CreateObject<Player>();
	Object* pObj2 = t.CreateObject<Monster>();

	pObj1->Render();
	pObj2->Render();
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