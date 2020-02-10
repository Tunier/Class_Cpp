#pragma once
#include "Object.h"

class Monster : public Object
{
public:
	Monster();
	virtual ~Monster();
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
private:
	int MonsterMoveTurn = 0;
	DWORD m_dwTime;

};