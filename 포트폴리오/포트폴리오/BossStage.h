#pragma once
#include "Scene.h"

class BossStage : public Scene
{
public:
	BossStage();
	virtual ~BossStage();
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
};