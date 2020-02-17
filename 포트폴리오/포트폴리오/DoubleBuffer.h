#pragma once
#include "Headers.h"

class DoubleBuffer
{
private:
	DoubleBuffer();
public:
	~DoubleBuffer();
private:
	static DoubleBuffer* m_pInstance;
public:
	static DoubleBuffer* GetInstance()
	{
		if (m_pInstance == NULL)
		{
			m_pInstance = new DoubleBuffer;
		}
		return m_pInstance;
	}

private:
	HANDLE m_HBuffer[2];

	int m_iBufferIndex;

public:
	void CreateBuffer(const int& _width, const int& _height);
	void WriteBuffer(float _x, float _y, char* _string);
	void WriteBuffer(float _x, float _y, int _value);
	void FlippingBuffer();
	void ClearBuffer();
	void DestroyBuffer();

	bool MyCloseHandle(HANDLE& _hFile);

};

