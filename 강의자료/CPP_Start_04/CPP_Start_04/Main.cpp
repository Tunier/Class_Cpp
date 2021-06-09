#include "Headers.h"
#include "Stage.h"

/*
namespace Player
{
	void Move()
	{

	}
}

namespace Monster
{
	void Move()
	{

	}
}
*/



int main(void)
{
	cout << "Main()" << endl;

	/*
	char* Name = (char*)"È«±æµ¿";
	printf_s("%s", Name);

	cout << Name << endl;

	int iNumber;

	cout << "ÀÔ·Â : ";
	cin >> iNumber;
	*/

	Stage s;
	s.Initialize();

	s.Progress();
	s.Render();


	return 0;
}