#include "Headers.h"
#include "MainUpdate.h"


int main(void)
{
	MainUpdate Main;
	Main.Initialize();

	DWORD dwTime = GetTickCount();

	while (true)
	{
		if (dwTime + 50 < GetTickCount())
		{
			dwTime = GetTickCount();
			system("cls");

			Main.Update();
			Main.Render();
		}
	}

	return 0;
}
