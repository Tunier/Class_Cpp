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
	Object* m_pMonster[64];
	Object* m_pBullet[64];
	Object* m_pWall[512];

public:
	Object* GetPlayer() { return m_pPlayer; }
	Object* GetMonster(int _i) { return m_pMonster[_i]; }
	Object* GetBullet(int _i) { return m_pBullet[_i]; }
	Object* GetWall(int _i) { return m_pWall[_i]; }
	Object* GetWallList() { return *m_pWall; }

	void SetPlayer(Object* _pPlayer) { m_pPlayer = _pPlayer; }
	void SetMonster(Object* _pMonster, int _i) { m_pMonster[_i] = _pMonster; }
	void SetBullet(Object* _pBullet, int _i) { m_pBullet[_i] = _pBullet; }
	void SetWall(Object* _pWall, int _i) { m_pWall[_i] = _pWall; }
};

