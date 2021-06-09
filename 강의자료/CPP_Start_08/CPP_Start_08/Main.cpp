#include "Headers.h"
#include "MainUpdate.h"


int main(void)
{
	MainUpdate Main;
	Main.Initialize();

	DWORD dwTime = GetTickCount();

	while (true)
	{
		if (dwTime < GetTickCount())
		{
			dwTime = GetTickCount();
			system("cls");

			Main.Update();
			Main.Render();
		}
	}

	return 0;
}






/*
//** Singleton (싱글톤)

//** 1. (단독) 개체
//** 2. 독신자(결혼을 안 했거나 애인이 없는 사람)
//** 3. (쌍둥이가 아닌) 외둥이


//** 프로그래밍 언어에서의 Singleton (싱글톤) 은 단독개체 로서의 역할을 수행하기위해 사용됨.

class Singleton
{
//** 외부에서 객체를 생성할수 없도록 생성자를 private 으로 지정해 둔다.
private:
	Singleton();
public:
	~Singleton();

private:
	//** static 글로벌 변수 선언
	static Singleton* m_pInstance;
public:
	//**  Get 함수는 반환할 데이터의 형태와 함수의 반환형태가 같아야 한다.
	static Singleton* GetInstance()
	{
		//** m_pInstance 가 NULL 일때...
		if (m_pInstance == NULL)
		{
			//** 동적 할당
			m_pInstance = new Singleton;

			//** 동적할당을 한번만 진행하기 위함.
		}

		//** 반환
		return m_pInstance;
	}

public:
	void Output();
};

Singleton* Singleton::m_pInstance = NULL;



Singleton::Singleton()
{

}

Singleton::~Singleton()
{

}

void Singleton::Output()
{
	cout << "Hello Singleton" << endl;
}
*/