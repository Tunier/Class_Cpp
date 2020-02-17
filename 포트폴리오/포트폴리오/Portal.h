#pragma once
#include "Object.h"

class Portal : public Object
{
public:
	Portal();
	virtual ~Portal();
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
};