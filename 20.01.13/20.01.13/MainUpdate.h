#pragma once
#include "Headers.h"

class Scene;
class MainUpdate
{
public:
	MainUpdate();
	virtual ~MainUpdate();
public:
	void Initailize();
	void Update();
	void Render();
	void Release();
private:
	int m_iState;
	Scene* m_pLogo;
	Scene* m_pMenu;
	Scene* m_pStage;
}

