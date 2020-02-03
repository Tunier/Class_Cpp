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
		{
			m_pInstance = new ObjectManager;
		}
		return m_pInstance;
	}
private:
	Object* m_pPlayer;
	Object* m_pMonster;
	Object* m_pBullet[64];

public:
	Object* GetPlayer() { return m_pPlayer; }
	Object* GetMonster() { return m_pMonster; }
	Object* GetBullet(int i) { return m_pBullet[i]; }

	void SetPlayer(Object* _pPlayer) { m_pPlayer = _pPlayer; }
	void SetMonster(Object* _pMonster) { m_pMonster = _pMonster; }
	void SetBullet(Object* _pBullet) { m_pBullet = _pBullet; }
};

