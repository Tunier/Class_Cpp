#include "Stage.h"
#include "SceneManager.h"
#include "ObjectFactory.h"
#include "InputManager.h"
#include "ObjectManager.h"

#include "Player.h"
#include "Monster.h"
#include "Bullet.h"
#include "Wall.h"

Stage::Stage()
{
}

Stage::~Stage()
{
	Release();
}

void Stage::Initialize()
{
	m_pMonster = ObjectFactory<Monster>::CreateObject(Vector3(20.f, 20.f));
	ObjectManager::GetInstance()->SetMonster(m_pMonster);

	m_pPlayer = ObjectFactory<Player>::CreateObject(Vector3(10.f, 11.f));
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

	m_pMonster->Update();
	m_pPlayer->Update();

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	switch (dwKey)
	{
	case KEYID_ENTER:
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

	/*for (int i = 0; i < 64; ++i)
	{
		if (ObjectManager::GetInstance()->GetBullet(i)->GetPosition().x > 118)
			ObjectManager::GetInstance()->GetBullet(i)->SetRender(0);

		if (ObjectManager::GetInstance()->GetBullet(i)->GetPosition().x < 0)
			ObjectManager::GetInstance()->GetBullet(i)->SetRender(0);

		if (ObjectManager::GetInstance()->GetBullet(i)->GetPosition().y > 40)
			ObjectManager::GetInstance()->GetBullet(i)->SetRender(0);

		if (ObjectManager::GetInstance()->GetBullet(i)->GetPosition().y < 0)
			ObjectManager::GetInstance()->GetBullet(i)->SetRender(0);
	}*/

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
		if (ObjectManager::GetInstance()->GetBullet(i)->GetPosition().x < ObjectManager::GetInstance()->GetMonster()->GetPosition().x + ObjectManager::GetInstance()->GetMonster()->GetScale().x &&
			ObjectManager::GetInstance()->GetMonster()->GetPosition().x < ObjectManager::GetInstance()->GetBullet(i)->GetPosition().x + ObjectManager::GetInstance()->GetBullet(i)->GetScale().x &&
			ObjectManager::GetInstance()->GetBullet(i)->GetPosition().y == ObjectManager::GetInstance()->GetMonster()->GetPosition().y)
		{
			ObjectManager::GetInstance()->GetBullet(i)->SetRender(0);
			ObjectManager::GetInstance()->GetMonster()->SetRender(0);
			ObjectManager::GetInstance()->GetMonster()->SetPosition(Vector3());
		}
	}


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

		else
		{
			ObjectManager::GetInstance()->GetWall(i)->SetPosition(Vector3(0.f, 0.f));
			ObjectManager::GetInstance()->GetWall(i)->SetRender(0);
		}
	}

}

void Stage::Render()
{
	if (ObjectManager::GetInstance()->GetMonster()->GetRender())
	{
		m_pMonster->Render();
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
}

void Stage::Release()
{
	ObjectManager::GetInstance()->SetPlayer(m_pPlayer);

	ObjectManager::GetInstance()->SetMonster(m_pMonster);

	delete m_pPlayer;
	m_pPlayer = NULL;

	delete m_pMonster;
	m_pMonster = NULL;
}
