#include <stdio.h>


//void SetNumber(int _i);
void SetNumber(int* _i);



int main(void)
{
	//** ����� ���ÿ� �ʱ�ȭ.
	int iNumber = 10; 

	//** SetNumber(int) �Լ� ȣ��
	//SetNumber(&iNumber); //** �Ű����� iNumber�� ���� �Ѱ���.



	printf_s("%d\n", iNumber);

	return 0;
}

/*
//** call by value
void SetNumber(int _i)
{
	//** �޾ƿ� ���� 100 �� ����.
	_i += 100;
}
*/

//** call by refernce
void SetNumber(int* _i)
{
	//** �޾ƿ� ���� 100 �� ����.
	(*_i) += 100;
}