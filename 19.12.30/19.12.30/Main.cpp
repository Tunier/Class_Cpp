#include <iostream>

using namespace std;
// -> 아래와 같은 내용을 줄여서 적을수 있음.
/*
using std::cout;
using std::endl;
*/


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


int main(void)
{
	char* Name = (char*)"홍길동";


	//printf_s("%s", Name);
	cout << Name << endl;

	// :: <- 핵심기능

	Player::Move();
	Monster::Move();

	int iNumber;
	cout << "입력 : ";
	std::cin >> iNumber;
	cout << iNumber << endl;

	return 0;
}