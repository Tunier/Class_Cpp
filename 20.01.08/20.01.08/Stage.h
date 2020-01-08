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
	//** ( m_ ) 맴버 변수를 나타내는 헝가리안 표기법  
	//** ( p  ) 포인터 변수를 나타내는 헝가리안 표기법
	Object* m_pPlayer;
	Object* m_pMonster;
};

