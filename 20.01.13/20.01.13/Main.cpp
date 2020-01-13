#include "Headers.h"
#include "MainUpdate.h"
#include "SceneManager.h"

// Singleton (�̱���) 
// ������ �ǹ� : ��ü, ������, �ܵ���
// ���α׷��� ������ �ǹ� : "�ܵ���ü" �μ��� ������ �����ϱ����� ����. 

/*
class Singleton
{
	// �ܺο��� ��ü �����Ұ��ϰ� �����ڸ� private�� �����صд�.
private:
	Singleton();
public:
	~Singleton();
private:
	// static : ��������(�۷ι�����) ������ ����.
	static Singleton* m_pInstance;
public:
	// Get �Լ��� ��ȯ�� �������� ���¿� �Լ��� ��ȯ���°� ���ƾ� �Ѵ�.
	static Singleton* GetInstance()
	{
		// m_pInstance �� NULL �϶�
		if (m_pInstance == NULL)
		{
			// ���� �Ҵ�
			m_pInstance = new Singleton;

			// �����Ҵ��� �ѹ��� �ؾߵ�.
		}

		// ��ȯ
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


// Getter�� Ư¡
// ��ȯ�� �������� ���°� ����.




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