#pragma once
#include "Scene.h"

class Clear : public Scene
{
public:
	Clear();
	virtual ~Clear();
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
};

