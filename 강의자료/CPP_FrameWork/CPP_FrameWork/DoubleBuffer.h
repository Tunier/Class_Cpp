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
	//** �츮���� ���� �׸����� 2�� ����� �ش�.
	HANDLE	m_HBuffer[2];

	//** �׸����� ��ġ�� ����
	int	m_iBufferIndex;

public:
	void CreateBuffer(const int& _width, const int& _height); // ���� ����
	void WriteBuffer(float _x, float _y, char *_string);           // ���� ����
	void FlippingBuffer();                                  // ���� ��ȯ
	void ClearBuffer();                                     // ���� �����
	void DestroyBuffer();                                   // ���� ����

	bool MyCloseHandle(HANDLE& _hFile);         // �����ϰ� CloseHandle ó��

private:
	DoubleBuffer();
public:
	~DoubleBuffer();
};


