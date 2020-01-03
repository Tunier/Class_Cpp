#include "Headers.h"



/* ���

public > protected > private
��ɰ� �����͸� �˸������� �־����.
is-a has-a ���� �˻��غ���.
����ȯ
*/

/*
class A
{
private: // ����� ����

protected: // ��Ӱ��踸 ����, �������� ����� ����
	int i;

public: // ���� ����
	void Output_A()
	{
		cout << i << endl;
	}
};


// A �� ��ӹ���.
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
	void Output_A_1()
	{
		cout << j << endl;
	}
};

// C �� ��ӹ���.
class C : public B
{
protected:

public:
	void Initialize()
	{
		i = 10;
		j = 20;
	}
};
*/

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

class D : public C
{
protected:
	int id;
public:
	void Initialize()
	{
		ia = 100;
		id = 25;
	}
	void Output()
	{
		cout << id << endl;
	}
};


int main(void)
{
	/*
	B a1;
	a1.Initialize();


	C a2;
	a2.Initialize();


	a1.Output_A();
	a1.Output_A_1();


	a2.Output_A();
	a2.Output_A_1();
	*/

	/*
	B* b = new B;
	C* c = new C;

	b->Initialize();
	c->Initialize();

	((A*)b)->Output();
	((A*)c)->Output();
	*/

	/*
	A* b = new B;
	A* c = new C;

	b->Initialize();
	b->Output();

	c->Initialize();
	c->Output();
	*/
	
	D d;

	d.Initialize();
	d.Output();

	A* d1 = new D;

	d1->Initialize();
	d1->Output();




	return 0;
}