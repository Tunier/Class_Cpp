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

	// 오버 라이딩 = 상속간에 함수이름이 똑같을때 어떤 함수가 호출될지 결정하는것.
};

