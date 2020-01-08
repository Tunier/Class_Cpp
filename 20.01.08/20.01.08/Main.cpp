#include "Headers.h"
#include "MainUpdate.h"

//#include "Object.h"
//#include "Monster.h"
//#include "Player.h"


int main(void)
{
	MainUpdate Main;
	Main.Initialize();

	while (true)
	{
		Main.Update();
		Main.Render();
	}











	return 0;
}