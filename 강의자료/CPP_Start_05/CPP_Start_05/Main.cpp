#include <iostream>

using namespace std;




/*
//** ���
class A 
{
private:	//** ����� ����

protected://** ��Ӱ��踸 ����, �������� ����� ����
	int i;

public:	//** ��������
	void Output_A()
	{
		cout << i << endl;
	}
};


//** A �� ��ӹ���.
class B : public A
{
protected:
	int j;

public:
	void Initialize()
	{
		i = 1;
		j = 2;
	}
	void Output_A1()
	{
		cout << j << endl;
	}
};


//** A �� ��ӹ���.
class C : public B
{
public:
	void Initialize()
	{
		i = 10;
		j = 20;
	}
};
*/





/*
class A
{
protected:
	int ia;
public:
	void Initialize()
	{
		ia = 0;
	}
	void Output()
	{
		cout << ia << endl;
	}
};


class B : public A
{
protected:
	int ib;
public:
	void Initialize()
	{
		ia = 1;
	}

	void Output()
	{
		cout << ib << endl;
	}
};


class C : public A
{
protected:
	int ic;
public:
	void Initialize()
	{
		ia = 10;
	}
	
	void Output()
	{
		cout << ic << endl;
	}
	
};
*/







int main(void)
{
	/*
	//** �θ��� �����ͳ� ����� �ڽ�Ŭ�������� ��� �� �� �ִ�.
	B b;
	a1.Initialize();

	C c;
	a2.Initialize();

	b.Output_A();
	b.Output_A1();

	c.Output_A();
	c.Output_A1();
	*/








	/*
	//** �θ� �ڽ� Ŭ���� ��ο� �Ȱ��� �̸��� ���� �Լ��� ���� �� �� ����ȯ ������� ���ϴ� �Լ��� ȣ�� �� �� �ִ�.
	B* b = new B;
	C* c = new C;

	b->Initialize();
	c->Initialize();

	((A*)b)->Output();
	((A*)c)->Output();
	*/








	/*
	//** �θ� Ŭ������ �ڽ� Ŭ������ �����Ҵ��Ͽ� ��� �� �� �ִ�. (�����ð� ���� ����)
	A* b = new B;
	A* c = new C;

	b->Initialize();
	b->Output();

	c->Initialize();
	c->Output();
	*/


	return 0;
}