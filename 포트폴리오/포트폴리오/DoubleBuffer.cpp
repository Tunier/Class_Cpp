#include "DoubleBuffer.h"

DoubleBuffer* DoubleBuffer::m_pInstance = NULL;

DoubleBuffer::DoubleBuffer() : m_iBufferIndex(0)
{
}

DoubleBuffer::~DoubleBuffer()
{
}

void DoubleBuffer::CreateBuffer(const int& _width, const int& _height)
{
	COORD size = { (SHORT)_width, (SHORT)_height };

	SMALL_RECT rect;

	rect.Left = 0;
	rect.Right = _width - 1;
	rect.Top = 0;
	rect.Bottom = _height - 1;

	m_HBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(m_HBuffer[0], size);
	SetConsoleWindowInfo(m_HBuffer[0], TRUE, &rect);

	m_HBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(m_HBuffer[1], size);
	SetConsoleWindowInfo(m_HBuffer[1], TRUE, &rect);

	CONSOLE_CURSOR_INFO DeCursor;

	DeCursor.dwSize = 1;
	DeCursor.bVisible = FALSE;

	SetConsoleCursorInfo(m_HBuffer[0], &DeCursor);
	SetConsoleCursorInfo(m_HBuffer[1], &DeCursor);
}

void DoubleBuffer::WriteBuffer(float _x, float _y, char* _string)
{
	DWORD dw;

	COORD CursorPosition = { (SHORT)_x, (SHORT)_y };

	SetConsoleCursorPosition(m_HBuffer[m_iBufferIndex], CursorPosition);

	WriteFile(m_HBuffer[m_iBufferIndex], _string, strlen(_string), &dw, NULL);
}

void DoubleBuffer::WriteBuffer(float _x, float _y, int _value)
{
	DWORD dw;

	COORD CursorPosition = { (SHORT)_x, (SHORT)_y };

	SetConsoleCursorPosition(m_HBuffer[m_iBufferIndex], CursorPosition);

	char* _string = new char[4];

	_itoa(_value, _string, 10);

	WriteFile(m_HBuffer[m_iBufferIndex], _string, strlen(_string), &dw, NULL);
}

void DoubleBuffer::FlippingBuffer()
{
	SetConsoleActiveScreenBuffer(m_HBuffer[m_iBufferIndex]);

	m_iBufferIndex = !m_iBufferIndex;
}

void DoubleBuffer::ClearBuffer()
{
	COORD Coor = { 0,0 };
	DWORD dw;

	FillConsoleOutputCharacter(m_HBuffer[m_iBufferIndex], ' ', CONSOL_MAX_WIDTH * CONSOL_MAX_HEIGHT, Coor, &dw);
}

void DoubleBuffer::DestroyBuffer()
{
	MyCloseHandle(m_HBuffer[0]);
	MyCloseHandle(m_HBuffer[1]);
	if (m_pInstance != NULL)
	{
		delete m_pInstance;
		m_pInstance = NULL;
	}
}

bool DoubleBuffer::MyCloseHandle(HANDLE& _hFile)
{
	if (INVALID_HANDLE_VALUE != _hFile)
	{
		_hFile = INVALID_HANDLE_VALUE;
	}
	return (0 != ::CloseHandle(_hFile));
}

