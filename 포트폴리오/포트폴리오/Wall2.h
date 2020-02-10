#pragma once
#include "Object.h"

class Wall2 : public Object
{
public:
	Wall2();
	virtual ~Wall2();
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
};