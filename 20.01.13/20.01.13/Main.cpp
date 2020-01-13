#include "Headers.h"
#include "MainUpdate.h"
#include "SceneManager.h"

// Singleton (싱글톤) 
// 사전적 의미 : 개체, 독신자, 외둥이
// 프로그레밍 언어에서의 의미 : "단독개체" 로서의 역할을 수행하기위해 사용됨. 

/*
class Singleton
{
	// 외부에서 객체 생성불가하게 생성자를 private로 지정해둔다.
private:
	Singleton();
public:
	~Singleton();
private:
	// static : 전역변수(글로벌변수) 선언을 해줌.
	static Singleton* m_pInstance;
public:
	// Get 함수는 반환할 데이터의 형태와 함수의 반환형태가 같아야 한다.
	static Singleton* GetInstance()
	{
		// m_pInstance 가 NULL 일때
		if (m_pInstance == NULL)
		{
			// 동적 할당
			m_pInstance = new Singleton;

			// 동적할당을 한번만 해야됨.
		}

		// 반환
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
	cout << "Hellow Singleton !!" << endl;
}
*/


// Getter의 특징
// 반환할 데이터의 형태가 같음.




int main(void)
{
	// Singleton::GetInstance()->Output();
	
	DWORD dwTime = GetTickCount();

	while (true)
	{
		if (dwTime + 250 < GetTickCount() )
		{
			system("cls");

			dwTime = GetTickCount();
		}
	}
	/*
	MainUpdate Main;
	Main.Initailize();

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
	*/














	return 0;
}