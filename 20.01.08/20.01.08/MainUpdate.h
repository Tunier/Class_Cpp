#pragma once
#include "Headers.h"

class Scene;
class MainUpdate
{
public:
	MainUpdate();
	~MainUpdate();
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
private:
	int m_iState;
	Scene* m_pLogo;
	Scene* m_pMenu;
	Scene* m_pStage;
};

