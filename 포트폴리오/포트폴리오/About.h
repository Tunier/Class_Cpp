#pragma once
#include "Scene.h"

class About : public Scene
{
public:
	About();
	virtual ~About();
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
};

