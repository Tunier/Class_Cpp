#include <iostream>
#include <Windows.h>

/*
struct tagObject
{
public: // C에서 쓰는 struct는 자동 public 상태.
	int iNumber;


};
*/

class Object
{
private: // 정보가 '은닉' 상태. C++은 자동 private 상태.
	int Index;
	int Password;
	int Age;
	char* Name;

public: // 정보가 '공개' 상태.
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

	Obj[0].SetName((char*)"홍길동");
	Obj[1].SetName((char*)"김길동");
	Obj[2].SetName((char*)"이길동");


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
private 상태에서 정보를 물어보면(여러번 계속 가능)[물어보는 '기능']{기본적으로 외부에 공개된 상태} -> 실패든 성공이든 답변이나옴.
geter seter
*/

