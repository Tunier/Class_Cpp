//** Ÿ�ڿ���
//** http://www.speedcoder.net/lessons/cpp/1/
#include <iostream>
#include <Windows.h>



struct Vector3
{
	float x, y;
};


class Object
{
private:	//** ������ ���е� ����
	
	Vector3 Position;

	int Index;
	int Password;
	int Age;
	char* Name;

public:	//** ������ ������ ����
	//** Initialize : �ʱ� ������ �����ϴ�.
	void Initialize()
	{
		Password = 0;
		Index = 0;
	}

	char* GetName() { return Name; }
	void SetName(char* _name) { Name = _name; }

	int GetAge() { return Age; }
	void SetAge(int _age) { Age = _age; }

	int GetIndex() { return Index; }
	void SetIndex(int _index) { Index = _index; }

	int GetPassword() { return Password; }
	void SetPassword(int _password) { Password = _password; }

	Vector3 GetPosition() { return Position; }
	void SetPosition(Vector3 _position) { Position = _position; }
};



int main(void)
{
	Object Obj[8];

	for (int i = 0; i < 8; ++i)
	{
		Obj[i].Initialize();
		Obj[i].SetPassword(i);
		Obj[i].SetIndex(i + 1);
	}

	Obj[0].GetPosition().x;
	Obj[0].GetPosition().y;

	/*
	Obj[0].SetName((char*)"ȫ�浿");
	Obj[1].SetName((char*)"�Ӳ���");
	Obj[2].SetName((char*)"�̸���");


	DWORD dwTime = GetTickCount();

	while (true)
	{
		if (dwTime + 500 < GetTickCount())
		{
			system("cls");
			dwTime = GetTickCount();

			for (int i = 0; i < 8; ++i)
				if (Obj[i].GetPassword() > 10)
					Obj[i].SetPassword(0);

			for (int i = 0; i < 8; ++i)
			{
				Obj[i].SetPassword(Obj[i].GetPassword() + 1);
				std::cout << Obj[i].GetIndex() << " : " << Obj[i].GetPassword() << std::endl;
			}

			std::cout << Obj[0].GetName() << std::endl;
			std::cout << Obj[1].GetName() << std::endl;
			std::cout << Obj[2].GetName() << std::endl;
		}
	}
	*/

	return 0;
}