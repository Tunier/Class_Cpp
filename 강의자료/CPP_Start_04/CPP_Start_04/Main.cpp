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
	char* Name = (char*)"ȫ�浿";
	printf_s("%s", Name);

	cout << Name << endl;

	int iNumber;

	cout << "�Է� : ";
	cin >> iNumber;
	*/

	Stage s;
	s.Initialize();

	s.Progress();
	s.Render();


	return 0;
}