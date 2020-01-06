#pragma once
#include "Headers.h"

class Object
{
public:
	Object();
	virtual ~Object();
private:

public:
	// ���� ���� �Լ�.
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

	/*
	virtual �Լ� => �����Լ�, �ڽ��� ������ ����.
	new �� ���ǵ� class�� �Լ� �����.
	*/
};

