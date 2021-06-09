#include <stdio.h>


//void SetNumber(int _i);
void SetNumber(int* _i);



int main(void)
{
	//** 선언과 동시에 초기화.
	int iNumber = 10; 

	//** SetNumber(int) 함수 호출
	//SetNumber(&iNumber); //** 매개변수 iNumber의 값을 넘겨줌.



	printf_s("%d\n", iNumber);

	return 0;
}

/*
//** call by value
void SetNumber(int _i)
{
	//** 받아온 값에 100 을 더함.
	_i += 100;
}
*/

//** call by refernce
void SetNumber(int* _i)
{
	//** 받아온 값에 100 을 더함.
	(*_i) += 100;
}