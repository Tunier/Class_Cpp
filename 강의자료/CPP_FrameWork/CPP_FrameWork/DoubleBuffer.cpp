#include "DoubleBuffer.h"

DoubleBuffer* DoubleBuffer::m_Instance = NULL;


DoubleBuffer::DoubleBuffer(void) : m_iBufferIndex(0)
{
}


DoubleBuffer::~DoubleBuffer(void)
{
}

// ���� ����
void DoubleBuffer::CreateBuffer(const int& _width, const int& _height)
{
	//** �׸��� ũ�⸦ �����ϴ� ����ü
	COORD size = { (SHORT)_width, (SHORT)_height };     

	// â ũ�⸦ �����ϴ� ����ü
	SMALL_RECT rect;                    

	//** �ܼ�â ������
	rect.Left = 0;
	rect.Right = _width - 1;
	rect.Top = 0; 
	rect.Bottom = _height - 1;


	// 1�� �׸��� ����
	m_HBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE , 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(m_HBuffer[0], size);  // ���� ũ�� ����
	SetConsoleWindowInfo(m_HBuffer[0], TRUE, &rect); // â ũ�� ����


	// 2�� �׸��� ����
	m_HBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE , 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(m_HBuffer[1], size);  // ���� ũ�� ����
	SetConsoleWindowInfo(m_HBuffer[1], TRUE, &rect); // â ũ�� ����



	//** �ܼ�â �����̴� Ŀ��
	CONSOLE_CURSOR_INFO DeCursor;

	DeCursor.dwSize = 1;
	DeCursor.bVisible = FALSE;

	SetConsoleCursorInfo(m_HBuffer[0], &DeCursor); // 1�� ���ۿ� �����̴� Ŀ�� ����
	SetConsoleCursorInfo(m_HBuffer[1], &DeCursor); // 2�� ���ۿ� �����̴� Ŀ�� ����
}

// ���� ����
void DoubleBuffer::WriteBuffer(float _x, float _y, char *_string)
{
	DWORD dw;

	// ��ǥ ���� ����ü
	COORD CursorPosition = { (SHORT)_x, (SHORT)_y };    // ��ǥ ����

	// ��ǥ �̵�
	SetConsoleCursorPosition(m_HBuffer[m_iBufferIndex], CursorPosition);

	// ���ۿ� ����
	WriteFile(m_HBuffer[m_iBufferIndex], _string, strlen(_string), &dw, NULL);
}

// ���� ��ȯ
void DoubleBuffer::FlippingBuffer()
{
	// ���� Ȱ��ȭ. ������ ������ �ѹ��� ���
	SetConsoleActiveScreenBuffer(m_HBuffer[m_iBufferIndex]);

	// �׸����� ������ ��������.
	m_iBufferIndex = !m_iBufferIndex;
}

// ���� �����
void DoubleBuffer::ClearBuffer()
{
	COORD Coor = { 0, 0 };  // �Ʒ� �Լ��� ���� ����ü
	DWORD dw;               // �Ʒ� �Լ��� ���� ����ü

	// �ش� ������ Coor ��ǥ���� ' '���� ä���� ������ ��ó�� �����
	FillConsoleOutputCharacter(m_HBuffer[m_iBufferIndex], ' ', CONSOL_MAX_WIDTH * CONSOL_MAX_HEIGHT, Coor, &dw);
}

// ���� ����
void DoubleBuffer::DestroyBuffer()
{
	MyCloseHandle(m_HBuffer[0]);    // 1�� ���� ����
	MyCloseHandle(m_HBuffer[1]);    // 2�� ���� ����
	// (HANDLE�� ������ �������� �״��. �ش� ������ ���� HANDLE Ŀ�θ� ����)
	// CloseHandle(m_hBuffer[0]); 
	// CloseHandle(m_hBuffer[1]);
	if (m_Instance != NULL)
	{
		delete m_Instance;
		m_Instance = NULL;
	}
}

// �����ϰ� CloseHandle�� ó���ϱ� ���� MyCloseHandle ����
bool DoubleBuffer::MyCloseHandle(HANDLE& _hFile)
{
	if (INVALID_HANDLE_VALUE != _hFile)
	{
		_hFile = INVALID_HANDLE_VALUE;
	}
	return (0 != ::CloseHandle(_hFile));
}

