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
32 bit cpu = int(4Byte) �� �ѹ��� ó��.
64 bit cpu = double(8Byte) �� �ѹ��� ó��.(int ���� ���͵� �ѹ��� �ΰ� ó���� ����.)

---------------------------------------------------------------------

Char = 8bit (1Byte) = �ַ� ���ڿ� ǥ���Ҷ� ���.
Short = 16bit (2Byte)
int = 32bit (4Byte)

float = 32bit (4Byte)
double = 64bit (8Byte)

������ ���� ũ�� : 32bit ȯ�濡���� 4Byte ��, 64bit ȯ�濡���� 8byte

---------------------------------------------------------------------

8bit(1Byte) = 00000000
32bit = 00000000 00000000 00000000 00000000
64bit = 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000

(2�������)
00000001 = 1 
00000010 = 2
00000011 = 3

---------------------------------------------------------------------

�޸� ����
	Stack ���� 
		�������� & �Ű����� ����.
	Hip ����
		���� �����͸� �����ϴ� ����

	LIFO ���� : Last In First Out -> (RAM) �޸��� Stack ����
	FIFO ���� : First In First Out

	ex) ������ ������������ Ȱ��.
		Stack ����								Heap ����
		Object* Target -> 4	or 8 Byte =====>	Struct Object -> 21Byte	
*/
