#pragma once
#include "Object.h"

class Bullet : public Object
{
public:
	Bullet();
	virtual ~Bullet();
private:

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

	// ���� ���̵� = ��Ӱ��� �Լ��̸��� �Ȱ����� � �Լ��� ȣ����� �����ϴ°�.
};

