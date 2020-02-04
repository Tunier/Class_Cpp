#pragma once
#include "Object.h"

class Bullet : public Object
{
public:
	Bullet();
	Bullet(const Bullet& tcv);
	virtual ~Bullet();

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
};