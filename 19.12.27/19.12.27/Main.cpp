#include <iostream>
#include <Windows.h>

/*
struct tagObject
{
public: // C���� ���� struct�� �ڵ� public ����.
	int iNumber;


};
*/

class Object
{
private: // ������ '����' ����. C++�� �ڵ� private ����.
	int Index;
	int Password;
	int Age;
	char* Name;

public: // ������ '����' ����.
	void Initialize()
	{
		Password = 0;
		Index = 0;
		Age = 0;
		Name;
	}	
	
	int GetIndex() { return Index; }
	void SetIndex(int _index) {	Index = _index;	}

	int GetPassword() {	return Password; }
	void SetPassword(int _password)	{ Password = _password;	}

	int GetAge() { return Age; }
	void SetAge(int _age) {	Age = _age;	}

	char* GetName() { return Name; }
	void SetName(char* _name) { Name = (char*)_name; }
	
	/*
	void Output()
	{
		std::cout << iNumber << std::endl;
	}
	*/

};

int main(void)
{
	//tagObject tObj;
	//tObj.iNumber;

	/*
	Object Obj1;
	Obj1.Initialize();
	Obj1.Output();
	*/

	Object Obj[8];

	Obj[0].SetName((char*)"ȫ�浿");
	Obj[1].SetName((char*)"��浿");
	Obj[2].SetName((char*)"�̱浿");


	for (int i = 0; i < 8; ++i)
	{
		Obj[i].Initialize();
		Obj[i].SetPassword(i);
		Obj[i].SetIndex(i + 1);
		Obj[i].SetAge(i + 10);
	}

	DWORD dwTime = GetTickCount();

	while (true)
	{
		if (dwTime + 500 < GetTickCount())
		{
			system("cls");
			dwTime = GetTickCount();

			for (int i = 0; i < 8; ++i)
			{
				if (Obj[i].GetPassword() > 10)
				{
					Obj[i].SetPassword(0);				
				}
			
				if (Obj[i].GetAge() > 20)
				{
					Obj[i].SetAge(10);
				}
			}
			
			for (int i = 0; i < 8; ++i)
			{
				Obj[i].SetPassword(Obj[i].GetPassword() + 1);
				Obj[i].SetAge(Obj[i].GetAge() + 1);
				std::cout << Obj[i].GetIndex() << " : " << Obj[i].GetPassword() << " / Age : "<<Obj[i].GetAge() <<std::endl;
			}
			
			std::cout << Obj[0].GetName() << std::endl;
			std::cout << Obj[1].GetName() << std::endl;
			std::cout << Obj[2].GetName() << std::endl;
		}
	}



	return 0;
}

/*
private ���¿��� ������ �����(������ ��� ����)[����� '���']{�⺻������ �ܺο� ������ ����} -> ���е� �����̵� �亯�̳���.
geter seter
*/

