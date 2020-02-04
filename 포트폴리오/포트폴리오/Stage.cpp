#include "Stage.h"
#include "SceneManager.h"
#include "ObjectFactory.h"
#include "InputManager.h"
#include "ObjectManager.h"

#include "Player.h"
#include "Monster.h"
#include "Bullet.h"

Stage::Stage()
{
}

Stage::~Stage()
{
	Release();
}

void Stage::Initialize()
{
	m_pPlayer = ObjectFactory<Player>::CreateObject(Vector3(10.f, 10.f));
	ObjectManager::GetInstance()->SetPlayer(m_pPlayer);

	m_pBullet = ObjectFactory<Bullet>::CreateObject();
	for (int i = 0; i < 64; ++i)
		ObjectManager::GetInstance()->SetBullet(m_pBullet, i);

	m_pMonster = ObjectFactory<Monster>::CreateObject(Vector3(20.f, 20.f));
	ObjectManager::GetInstance()->SetMonster(m_pMonster);
}

void Stage::Update()
{
	m_pPlayer->Update();
	m_pMonster->Update();
	m_pBullet->Update();

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	switch (dwKey)
	{
	case KEYID_ENTER:
		SceneManager::GetInstance()->SetScene(SCENEIDES_EXIT);

	case KEYID_SPACE:
		for (int i = 0; i < 64; ++i)
			if (ObjectManager::GetInstance()->GetBullet(i)->GetRender())
			{
				ObjectManager::GetInstance()->GetBullet(i)->Initialize();
				break;
			}
	}

	for (int i = 0; i < 64; ++i)
		if (ObjectManager::GetInstance()->GetBullet(i)->GetPosition().x > 118)
			ObjectManager::GetInstance()->GetBullet(i)->SetRender(0);

	for (int i = 0; i < 64; ++i)
		if (ObjectManager::GetInstance()->GetBullet(i)->GetPosition().y > 40)
			ObjectManager::GetInstance()->GetBullet(i)->SetRender(0);
}

void Stage::Render()
{
	m_pMonster->Render();

	for (int i = 0; i < 64; ++i)
	{
		if (ObjectManager::GetInstance()->GetBullet(i)->GetRender())
		{
			m_pBullet->Render();
		}
	}

	m_pPlayer->Render();
	m_pWall->Render();
}

void Stage::Release()
{
	ObjectManager::GetInstance()->SetPlayer(m_pPlayer);

	ObjectManager::GetInstance()->SetMonster(m_pMonster);

	for (int i = 0; i < 64; ++i)
		ObjectManager::GetInstance()->SetBullet(m_pBullet, i);

	ObjectManager::GetInstance()->SetWall(m_pWall);

	delete m_pPlayer;
	m_pPlayer = NULL;

	delete m_pMonster;
	m_pMonster = NULL;

	delete m_pBullet;
	m_pBullet = NULL;

	delete m_pWall;
	m_pWall = NULL;
}
