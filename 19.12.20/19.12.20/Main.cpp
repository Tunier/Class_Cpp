#include <stdio.h>
#include <stdlib.h>

// SetNumber 전방 선언. 정수값 호출.
void SetNumber(int* _i);

int main(void)
{
	// iNumber = 10 으로 초기화.
	int iNum = 10;
	
	
	// SetNumber 함수 호출
	SetNumber(&iNum);
		

	printf_s("%d\n", iNum);


	return 0;
}

/*
// call by value
void SetNumber(int _i)
{
	// SetNumber 함수를 호출하면 i에 100을 더함.
	_i += 100;
}
*/

// call by reference
void SetNumber(int *_i)
{
	// SetNumber 함수를 호출하면 i에 100을 더함.
	*_i += 100;
}

/* 
---------------------------------------------------------------------

CPU 구성 : 레지스터 메모리, 연산장치, 제어장치
32 bit cpu = int(4 Byte) 값 한번에 처리.
64 bit cpu = double(8 Byte) 값 한번에 처리.(int 값이 들어와도 한번에 두개 처리는 못함.)

---------------------------------------------------------------------

Char = 8 bit (1 Byte) = 주로 문자열 표현할때 사용.
Short = 16 bit (2 Byte)
int = 32 bit (4 Byte)

float = 32 bit (4 Byte)
double = 64 bit (8 Byte)

포인터 변수 크기 : 32 bit 환경에서는 4 Byte 로, 64 bit 환경에서는 8 byte

---------------------------------------------------------------------

8 bit (1 Byte) = 00000000
32 bit = 00000000 00000000 00000000 00000000
64 bit = 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000

(2진수사용)
00000001 = 1 
00000010 = 2
00000011 = 3

---------------------------------------------------------------------

메모리 구성
	Stack 영역 
		지역변수 & 매개변수 저장.
	Heap 영역
		동적 데이터를 관리하는 영역

	LIFO 구조 : Last In First Out -> (RAM) 메모리의 Stack 공간
	
	FIFO 구조 : First In First Out

	ex) 데이터 절약차원에서 활용.
		Stack 영역								Heap 영역
		Object* Target -> 4	or 8 Byte =====>	Struct Object -> 21 Byte	
*/
