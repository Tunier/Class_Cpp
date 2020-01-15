#pragma once
#include "Headers.h"
#include "Player.h"
#include "Monster.h"
#include "Bullet.h"

class ObjectFactory
{
public:
	static Object* CreatePlayer()
	{
		Object* pObj = new Player;
		pObj->Initialize();
		
		return pObj;
	}

	static Object* CreatePlayer(Vector3 _vPos)
	{
		Object* pObj = new Player;
		pObj->Initialize();
		pObj->SetPosotion(_vPos);

		return pObj;
	}
	
	static Object* CreateMonster()
	{
		Object* pObj = new Monster;
		pObj->Initialize();

		return pObj;
	}

	static Object* CreateMonster(Vector3 _vPos)
	{
		Object* pObj = new Monster;
		pObj->Initialize();
		pObj->SetPosotion(_vPos);

		return pObj;
	}
	
	static Object* CreateBullet()
	{
		Object* pObj = new Bullet;
		pObj->Initialize();

		return pObj;
	}

	static Object* CreateBullet(Vector3 _vPos)
	{
		Object* pObj = new Bullet;
		pObj->Initialize();
		pObj->SetPosotion(_vPos);

		return pObj;
	}
};