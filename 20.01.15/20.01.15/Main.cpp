#include "Headers.h"
#include "MainUpdate.h"
#include "SceneManager.h"

int main(void)
{
	MainUpdate Main;
	Main.Initialize();

	DWORD dwTime = GetTickCount();
	
	while (true)
	{
		if (dwTime + 250 < GetTickCount())
		{
			dwTime = GetTickCount();
			system("cls");

			Main.Update();
			Main.Render();
		}
	}






	return 0;
}


//MainUpdate* pA = CreateObject();
//
//MainUpdate* CreateObject()
//{
//	MainUpdate* pObj = new MainUpdate;
//	pObj->Initialize();
//
//	return pObj;
//}