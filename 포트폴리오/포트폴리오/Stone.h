#pragma once
#include "Object.h"

class Stone : public Object
{
public:
	Stone();
	virtual ~Stone();
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
};