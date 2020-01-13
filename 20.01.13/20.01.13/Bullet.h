#pragma once
#include "Object.h"

class Bullet : public Object
{
public:
	Bullet();
	virtual ~Bullet();
public:
	virtual void Initailize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
};

