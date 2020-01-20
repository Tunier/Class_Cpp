#pragma once
#include "Scene.h"

class Object;
class Stage : public Scene
{
public:
	Stage();
	virtual ~Stage();
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
private:
	Object* m_pPlayer;
	Object* m_pMonster;
	Object* m_pBullet;
};
