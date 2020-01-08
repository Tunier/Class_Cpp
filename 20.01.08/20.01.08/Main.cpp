#include "Headers.h"
#include "MainUpdate.h"


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