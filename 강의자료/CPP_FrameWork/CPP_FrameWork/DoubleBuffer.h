#pragma once
#include "Headers.h"

class DoubleBuffer
{
private:
	static DoubleBuffer* m_Instance;
public:
	static DoubleBuffer* GetInstance()
	{
		if(m_Instance == NULL)
			m_Instance = new DoubleBuffer;

		return m_Instance;
	}

private:
	//** 우리눈에 보일 그림판을 2장 만들어 준다.
	HANDLE	m_HBuffer[2];

	//** 그림판을 배치할 순번
	int	m_iBufferIndex;

public:
	void CreateBuffer(const int& _width, const int& _height); // 버퍼 생성
	void WriteBuffer(float _x, float _y, char *_string);           // 버퍼 쓰기
	void FlippingBuffer();                                  // 버퍼 전환
	void ClearBuffer();                                     // 버퍼 지우기
	void DestroyBuffer();                                   // 버퍼 해제

	bool MyCloseHandle(HANDLE& _hFile);         // 안전하게 CloseHandle 처리

private:
	DoubleBuffer();
public:
	~DoubleBuffer();
};


