#pragma once
#include "Object.h"

class Monster : public Object
{
public:
	Monster();
	virtual ~Monster();
private:
	
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
	
	// ���� ���̵� = ��Ӱ��� �Լ��̸��� �Ȱ����� � �Լ��� ȣ����� �����ϴ°�.
};

