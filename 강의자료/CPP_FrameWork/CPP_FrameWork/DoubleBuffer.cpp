#include "DoubleBuffer.h"

DoubleBuffer* DoubleBuffer::m_Instance = NULL;


DoubleBuffer::DoubleBuffer(void) : m_iBufferIndex(0)
{
}


DoubleBuffer::~DoubleBuffer(void)
{
}

// 버퍼 생성
void DoubleBuffer::CreateBuffer(const int& _width, const int& _height)
{
	//** 그림판 크기를 저장하는 구조체
	COORD size = { (SHORT)_width, (SHORT)_height };     

	// 창 크기를 저장하는 구조체
	SMALL_RECT rect;                    

	//** 콘솔창 사이즈
	rect.Left = 0;
	rect.Right = _width - 1;
	rect.Top = 0; 
	rect.Bottom = _height - 1;


	// 1번 그림판 생성
	m_HBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE , 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(m_HBuffer[0], size);  // 버퍼 크기 설정
	SetConsoleWindowInfo(m_HBuffer[0], TRUE, &rect); // 창 크기 설정


	// 2번 그림판 생성
	m_HBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE , 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(m_HBuffer[1], size);  // 버퍼 크기 설정
	SetConsoleWindowInfo(m_HBuffer[1], TRUE, &rect); // 창 크기 설정



	//** 콘솔창 깜박이는 커서
	CONSOLE_CURSOR_INFO DeCursor;

	DeCursor.dwSize = 1;
	DeCursor.bVisible = FALSE;

	SetConsoleCursorInfo(m_HBuffer[0], &DeCursor); // 1번 버퍼에 깜박이는 커서 지움
	SetConsoleCursorInfo(m_HBuffer[1], &DeCursor); // 2번 버퍼에 깜박이는 커서 지움
}

// 버퍼 쓰기
void DoubleBuffer::WriteBuffer(float _x, float _y, char *_string)
{
	DWORD dw;

	// 좌표 저장 구조체
	COORD CursorPosition = { (SHORT)_x, (SHORT)_y };    // 좌표 설정

	// 좌표 이동
	SetConsoleCursorPosition(m_HBuffer[m_iBufferIndex], CursorPosition);

	// 버퍼에 쓰기
	WriteFile(m_HBuffer[m_iBufferIndex], _string, strlen(_string), &dw, NULL);
}

// 버퍼 전환
void DoubleBuffer::FlippingBuffer()
{
	// 버퍼 활성화. 버퍼의 내용을 한번에 출력
	SetConsoleActiveScreenBuffer(m_HBuffer[m_iBufferIndex]);

	// 그림판을 순번을 변경해줌.
	m_iBufferIndex = !m_iBufferIndex;
}

// 버퍼 지우기
void DoubleBuffer::ClearBuffer()
{
	COORD Coor = { 0, 0 };  // 아래 함수를 위한 구조체
	DWORD dw;               // 아래 함수를 위한 구조체

	// 해당 버퍼의 Coor 좌표부터 ' '값을 채워서 지워진 것처럼 만들기
	FillConsoleOutputCharacter(m_HBuffer[m_iBufferIndex], ' ', CONSOL_MAX_WIDTH * CONSOL_MAX_HEIGHT, Coor, &dw);
}

// 버퍼 해제
void DoubleBuffer::DestroyBuffer()
{
	MyCloseHandle(m_HBuffer[0]);    // 1번 버퍼 해제
	MyCloseHandle(m_HBuffer[1]);    // 2번 버퍼 해제
	// (HANDLE이 지정한 정수값은 그대로. 해당 정수에 대한 HANDLE 커널만 삭제)
	// CloseHandle(m_hBuffer[0]); 
	// CloseHandle(m_hBuffer[1]);
	if (m_Instance != NULL)
	{
		delete m_Instance;
		m_Instance = NULL;
	}
}

// 안전하게 CloseHandle을 처리하기 위해 MyCloseHandle 만듬
bool DoubleBuffer::MyCloseHandle(HANDLE& _hFile)
{
	if (INVALID_HANDLE_VALUE != _hFile)
	{
		_hFile = INVALID_HANDLE_VALUE;
	}
	return (0 != ::CloseHandle(_hFile));
}

