#pragma once
#include "Headers.h"

class Object;
class ObjectManager
{
private:
	ObjectManager();
public:
	~ObjectManager();
private:
	static ObjectManager* m_pInstance;

public:
	static ObjectManager* GetInstance()
	{
		if (m_pInstance == NULL)
			m_pInstance = new ObjectManager;
		return m_pInstance;
	}
private:
	Object* m_pPlayer;
public:
	/*
	void Update();
	void Render();
	*/
public:
	Object* GetPlayer() { return m_pPlayer; }
	void SetPlayer(Object* _pPlayer) { m_pPlayer = _pPlayer; }
};

