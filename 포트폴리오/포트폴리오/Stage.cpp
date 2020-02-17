#include "Stage.h"
#include "SceneManager.h"
#include "ObjectFactory.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "DoubleBuffer.h"

#include "Player.h"
#include "Monster.h"
#include "Bullet.h"
#include "Wall.h"
#include "Portal.h"

Stage::Stage()
{
}

Stage::~Stage()
{
	Release();
}

void Stage::Initialize()
{
	for (int i = 0; i < 64; ++i)
	{
		Object* pObj = ObjectFactory<Monster>::CreateObject();
		ObjectManager::GetInstance()->SetMonster(pObj, i);
		ObjectManager::GetInstance()->GetMonster(i)->SetRender(0);
	}
	
	ObjectManager::GetInstance()->GetMonster(0)->SetPosition(Vector3(20.f, 20.f));
	ObjectManager::GetInstance()->GetMonster(0)->SetRender(1);

	ObjectManager::GetInstance()->GetMonster(1)->SetPosition(Vector3(40.f, 18.f));
	ObjectManager::GetInstance()->GetMonster(1)->SetRender(1);


	m_pPlayer = ObjectFactory<Player>::CreateObject(Vector3(10.f, 11.f));
	ObjectManager::GetInstance()->SetPlayer(m_pPlayer);

	m_pPortal = ObjectFactory<Portal>::CreateObject(Vector3(56.f, 14.f));
	ObjectManager::GetInstance()->SetPlayer(m_pPlayer);


	for (int i = 0; i < 64; ++i)
	{
		Object* pObj = ObjectFactory<Bullet>::CreateObject();
		ObjectManager::GetInstance()->SetBullet(pObj, i);
		ObjectManager::GetInstance()->GetBullet(i)->SetRender(0);
	}

	for (int i = 0; i < 512; ++i)
	{
		Object* pObj = ObjectFactory<Wall>::CreateObject();
		ObjectManager::GetInstance()->SetWall(pObj, i);
		ObjectManager::GetInstance()->GetWall(i)->SetRender(0);
	}

	for (int i = 0; i < 512; ++i)
	{
		if (i == 0)
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(Vector3(8.f, 8.f));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i <= 31)
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(
				Vector3(ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().x + 2,
					ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().y));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i <= 44)
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(
				Vector3(ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().x,
					ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().y + 1));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i <= 75)
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(
				Vector3(ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().x - 2,
					ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().y));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i <= 88)
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(
				Vector3(ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().x,
					ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().y - 1));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i == 89)
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(Vector3(16.f, 9.f));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i <= 92)
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(
				Vector3(ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().x,
					ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().y + 1));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i == 93)
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(Vector3(16.f, 18.f));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i <= 96)
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(
				Vector3(ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().x,
					ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().y + 1));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i == 97)
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(Vector3(10.f, 15.f));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i <= 104)
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(
				Vector3(ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().x + 2,
					ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().y));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i <= 107)
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(
				Vector3(ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().x,
					ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().y - 1));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i == 108)
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(Vector3(32.f, 12.f));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i <= 116)
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(
				Vector3(ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().x,
					ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().y + 1));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i == 117)
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(Vector3(24.f, 16.f));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i <= 118)
		{
		ObjectManager::GetInstance()->GetWall(i)->SetPosition(
			Vector3(ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().x,
				ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().y + 1));
		ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i == 119)
		{
		ObjectManager::GetInstance()->GetWall(i)->SetPosition(Vector3(34.f, 12.f));
		ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i <= 133)
		{
		ObjectManager::GetInstance()->GetWall(i)->SetPosition(
			Vector3(ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().x + 2,
				ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().y));
		ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i <= 138)
		{
		ObjectManager::GetInstance()->GetWall(i)->SetPosition(
			Vector3(ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().x,
				ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().y + 1));
		ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i <= 149)
		{
		ObjectManager::GetInstance()->GetWall(i)->SetPosition(
			Vector3(ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().x - 2,
				ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().y));
		ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(Vector3(0.f, 0.f));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(0);
		}
	}

}

void Stage::Update()
{
	for (int i = 0; i < 64; ++i)
	{
		if (ObjectManager::GetInstance()->GetBullet(i)->GetRender())
		{
			ObjectManager::GetInstance()->GetBullet(i)->Update();
		}
	}

	for (int i = 0; i < 512; ++i)
	{
		if (ObjectManager::GetInstance()->GetWall(i)->GetRender())
		{
			ObjectManager::GetInstance()->GetWall(i)->Update();
		}
	}

	/*
	for (int i = 0; i < 512; ++i)
	{
		if (i == 0)
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(Vector3(8.f, 8.f));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i <= 51)
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(
				Vector3(ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().x + 2,
					ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().y));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i <= 74)
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(
				Vector3(ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().x,
					ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().y + 1));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i <= 125)
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(
				Vector3(ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().x - 2,
					ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().y));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i <= 148)
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(
				Vector3(ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().x,
					ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().y - 1));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i == 149)
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(Vector3(18.f, 9.f));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i <= 154)
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(
				Vector3(ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().x,
					ObjectManager::GetInstance()->GetWall(i - 1)->GetPosition().y + 1));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else if (i == 155)
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(Vector3(18.f, 25.f));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(1);
		}

		else
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(Vector3(0.f, 0.f));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(0);
		}
	}
	*/

	for (int i = 0; i < 64; ++i)
	{
		if (ObjectManager::GetInstance()->GetMonster(i)->GetRender())
		{
			ObjectManager::GetInstance()->GetMonster(i)->Update();
		}
	}

	m_pPlayer->Update();

	m_pPortal->Update();

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	switch (dwKey)
	{
	case KEYID_ESCAPE:
		SceneManager::GetInstance()->SetScene(SCENEIDES_EXIT);
		break;

	case KEYID_SPACE:
		for (int i = 0; i < 64; ++i)
			if (!ObjectManager::GetInstance()->GetBullet(i)->GetRender())
			{
				ObjectManager::GetInstance()->GetBullet(i)->Initialize();
				ObjectManager::GetInstance()->GetBullet(i)->SetPosition(m_pPlayer->GetPosition());
				ObjectManager::GetInstance()->GetBullet(i)->SetRender(1);
				break;
			}
		break;
	}

	for (int i = 0; i < 64; ++i)
	{
		for (int j = 0; j < 512; ++j)
		{
			if (ObjectManager::GetInstance()->GetBullet(i)->GetPosition().x < ObjectManager::GetInstance()->GetWall(j)->GetPosition().x + ObjectManager::GetInstance()->GetWall(j)->GetScale().x &&
				ObjectManager::GetInstance()->GetWall(j)->GetPosition().x < ObjectManager::GetInstance()->GetBullet(i)->GetPosition().x + ObjectManager::GetInstance()->GetBullet(i)->GetScale().x &&
				ObjectManager::GetInstance()->GetBullet(i)->GetPosition().y == ObjectManager::GetInstance()->GetWall(j)->GetPosition().y)
			{
				ObjectManager::GetInstance()->GetBullet(i)->SetRender(0);
				ObjectManager::GetInstance()->GetBullet(i)->SetPosition(Vector3());
			}
		}
	}

	for (int i = 0; i < 64; ++i)
	{
		for (int j = 0; j < 64; ++j)
		{
			if (ObjectManager::GetInstance()->GetBullet(i)->GetPosition().x < ObjectManager::GetInstance()->GetMonster(j)->GetPosition().x + ObjectManager::GetInstance()->GetMonster(j)->GetScale().x &&
				ObjectManager::GetInstance()->GetMonster(j)->GetPosition().x < ObjectManager::GetInstance()->GetBullet(i)->GetPosition().x + ObjectManager::GetInstance()->GetBullet(i)->GetScale().x &&
				ObjectManager::GetInstance()->GetBullet(i)->GetPosition().y == ObjectManager::GetInstance()->GetMonster(j)->GetPosition().y)
			{
				ObjectManager::GetInstance()->GetBullet(i)->SetRender(0);
				ObjectManager::GetInstance()->GetMonster(j)->SetRender(0);
				ObjectManager::GetInstance()->GetBullet(i)->SetPosition(Vector3());
				ObjectManager::GetInstance()->GetMonster(j)->SetPosition(Vector3());
			}
		}
	}



}

void Stage::Render()
{
	for (int i = 0; i < 64; ++i)
	{
		if (ObjectManager::GetInstance()->GetMonster(i)->GetRender())
		{
			ObjectManager::GetInstance()->GetMonster(i)->Render();
		}
	}

	for (int i = 0; i < 64; ++i)
	{
		if (ObjectManager::GetInstance()->GetBullet(i)->GetRender())
		{
			ObjectManager::GetInstance()->GetBullet(i)->Render();
		}
	}

	for (int i = 0; i < 512; ++i)
	{
		if (ObjectManager::GetInstance()->GetWall(i)->GetRender())
		{
			ObjectManager::GetInstance()->GetWall(i)->Render();
		}
	}

	m_pPlayer->Render();

	m_pPortal->Render();

	DoubleBuffer::GetInstance()->WriteBuffer(
		80,	8, (char*)"Information");

	DoubleBuffer::GetInstance()->WriteBuffer(
		80,	10,	(char*)"@ : Portal");

	DoubleBuffer::GetInstance()->WriteBuffer(
		80,	12,	(char*)"Beat The Monsters All.");

	DoubleBuffer::GetInstance()->WriteBuffer(
		80, 14, m_Score);
}

void Stage::Release()
{
	ObjectManager::GetInstance()->SetPlayer(m_pPlayer);

	ObjectManager::GetInstance()->SetPlayer(m_pPortal);

	delete m_pPlayer;
	m_pPlayer = NULL;

	delete m_pPortal;
	m_pPortal = NULL;
}
