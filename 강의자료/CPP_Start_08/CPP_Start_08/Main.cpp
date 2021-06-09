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
//** Singleton (�̱���)

//** 1. (�ܵ�) ��ü
//** 2. ������(��ȥ�� �� �߰ų� ������ ���� ���)
//** 3. (�ֵ��̰� �ƴ�) �ܵ���


//** ���α׷��� ������ Singleton (�̱���) �� �ܵ���ü �μ��� ������ �����ϱ����� ����.

class Singleton
{
//** �ܺο��� ��ü�� �����Ҽ� ������ �����ڸ� private ���� ������ �д�.
private:
	Singleton();
public:
	~Singleton();

private:
	//** static �۷ι� ���� ����
	static Singleton* m_pInstance;
public:
	//**  Get �Լ��� ��ȯ�� �������� ���¿� �Լ��� ��ȯ���°� ���ƾ� �Ѵ�.
	static Singleton* GetInstance()
	{
		//** m_pInstance �� NULL �϶�...
		if (m_pInstance == NULL)
		{
			//** ���� �Ҵ�
			m_pInstance = new Singleton;

			//** �����Ҵ��� �ѹ��� �����ϱ� ����.
		}

		//** ��ȯ
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