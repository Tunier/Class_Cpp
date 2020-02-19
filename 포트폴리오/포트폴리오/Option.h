#pragma once
#include "Scene.h"

class Option : public Scene
{
public:
	Option();
	virtual ~Option();
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
};
