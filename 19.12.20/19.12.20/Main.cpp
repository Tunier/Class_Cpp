#include <stdio.h>
#include <stdlib.h>

// SetNumber ���� ����. ������ ȣ��.
void SetNumber(int* _i);

int main(void)
{
	// iNumber = 10 ���� �ʱ�ȭ.
	int iNum = 10;
	
	
	// SetNumber �Լ� ȣ��
	SetNumber(&iNum);
		

	printf_s("%d\n", iNum);


	return 0;
}

/*
// call by value
void SetNumber(int _i)
{
	// SetNumber �Լ��� ȣ���ϸ� i�� 100�� ����.
	_i += 100;
}
*/

// call by reference
void SetNumber(int *_i)
{
	// SetNumber �Լ��� ȣ���ϸ� i�� 100�� ����.
	*_i += 100;
}

/* 
---------------------------------------------------------------------

CPU ���� : �������� �޸�, ������ġ, ������ġ
32 bit cpu = int(4 Byte) �� �ѹ��� ó��.
64 bit cpu = double(8 Byte) �� �ѹ��� ó��.(int ���� ���͵� �ѹ��� �ΰ� ó���� ����.)

---------------------------------------------------------------------

Char = 8 bit (1 Byte) = �ַ� ���ڿ� ǥ���Ҷ� ���.
Short = 16 bit (2 Byte)
int = 32 bit (4 Byte)

float = 32 bit (4 Byte)
double = 64 bit (8 Byte)

������ ���� ũ�� : 32 bit ȯ�濡���� 4 Byte ��, 64 bit ȯ�濡���� 8 byte

---------------------------------------------------------------------

8 bit (1 Byte) = 00000000
32 bit = 00000000 00000000 00000000 00000000
64 bit = 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000

(2�������)
00000001 = 1 
00000010 = 2
00000011 = 3

---------------------------------------------------------------------

�޸� ����
	Stack ���� 
		�������� & �Ű����� ����.
	Heap ����
		���� �����͸� �����ϴ� ����

	LIFO ���� : Last In First Out -> (RAM) �޸��� Stack ����
	
	FIFO ���� : First In First Out

	ex) ������ ������������ Ȱ��.
		Stack ����								Heap ����
		Object* Target -> 4	or 8 Byte =====>	Struct Object -> 21 Byte	
*/
