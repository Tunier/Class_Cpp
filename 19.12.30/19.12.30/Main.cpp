#include "Headers.h"
#include "Player.h"
#include "Monster.h"

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
	/*
	{
		char* Name = (char*)"È«±æµ¿";


		//printf_s("%s", Name);
		cout << Name << endl;

		// :: <- ÇÙ½É±â´É

		Player::Move();
		Monster::Move();

		int iNumber;
		cout << "ÀÔ·Â : ";
		cin >> iNumber;
		cout << iNumber << endl;
	}
	*/
	
	Player P;

	P.Initialize();
	P.Render();

	cout << endl;

	Monster M;

	M.Initialize();
	M.Render();












	
	return 0;
}