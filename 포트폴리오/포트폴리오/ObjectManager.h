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
	Object* m_pWall;

public:
	Object* GetPlayer() { return m_pPlayer; }
	Object* GetMonster() { return m_pMonster; }
	Object* GetBullet(int _i) { return m_pBullet[_i]; }
	Object* GetWall() { return m_pWall; }

	void SetPlayer(Object* _pPlayer) { m_pPlayer = _pPlayer; }
	void SetMonster(Object* _pMonster) { m_pMonster = _pMonster; }
	void SetBullet(Object* _pBullet, int _i) { m_pBullet[_i] = _pBullet; }
	void SetWall(Object* _pWall) { m_pWall = _pWall; }
};

