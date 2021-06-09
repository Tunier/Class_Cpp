#include <iostream>

using namespace std;




/*
//** 상속
class A 
{
private:	//** 비공개 상태

protected://** 상속관계만 공개, 나머지는 비공개 상태
	int i;

public:	//** 공개상태
	void Output_A()
	{
		cout << i << endl;
	}
};


//** A 를 상속받음.
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


//** A 를 상속받음.
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
	//** 부모의 데이터나 기능을 자식클레스에서 사용 할 수 있다.
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
	//** 부모 자식 클레스 모두에 똑같은 이름을 갖은 함수가 존재 할 때 형변환 기능으로 원하는 함수를 호출 할 수 있다.
	B* b = new B;
	C* c = new C;

	b->Initialize();
	c->Initialize();

	((A*)b)->Output();
	((A*)c)->Output();
	*/








	/*
	//** 부모 클레스에 자식 클레스를 동적할당하여 사용 할 수 있다. (다음시간 수업 예비)
	A* b = new B;
	A* c = new C;

	b->Initialize();
	b->Output();

	c->Initialize();
	c->Output();
	*/


	return 0;
}