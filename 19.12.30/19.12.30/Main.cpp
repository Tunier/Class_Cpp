#include <iostream>

using namespace std;
// -> �Ʒ��� ���� ������ �ٿ��� ������ ����.
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
	char* Name = (char*)"ȫ�浿";


	//printf_s("%s", Name);
	cout << Name << endl;

	// :: <- �ٽɱ��

	Player::Move();
	Monster::Move();

	int iNumber;
	cout << "�Է� : ";
	std::cin >> iNumber;
	cout << iNumber << endl;

	return 0;
}