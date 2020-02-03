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

	m_pBullet = ObjectFactory<Bullet>::CreateObject(64);
	ObjectManager::GetInstance()->SetBullet(m_pBullet);

	m_pMonster = ObjectFactory<Monster>::CreateObject(Vector3(20.f, 20.f));
	ObjectManager::GetInstance()->SetMonster(m_pMonster);
}

void Stage::Update()
{
	m_pPlayer->Update();
	m_pMonster->Update();
	//m_pBullet->Update();

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	switch (dwKey)
	{
	case KEYID_ENTER:
		SceneManager::GetInstance()->SetScene(SCENEIDES_EXIT);

	case KEYID_SPACE:
		ObjectManager::GetInstance()->GetBullet(0)->Initialize();
	}

	/*
	if (ObjectManager::GetInstance()->GetBullet()->GetPosition().x > 118)
	{
		ObjectManager::GetInstance()->GetBullet()->SetPosition(Vector3(200.f, 200.f));
		ObjectManager::GetInstance()->GetBullet()->SetRotate(ROTATEIDS_NEUTRALITY);
	}
	*/
}

void Stage::Render()
{
	m_pMonster->Render();
	//m_pBullet->Render();
	m_pPlayer->Render();
}

void Stage::Release()
{
	ObjectManager::GetInstance()->SetPlayer(m_pPlayer);
	ObjectManager::GetInstance()->SetBullet(m_pBullet);
	ObjectManager::GetInstance()->SetMonster(m_pMonster);

	delete m_pPlayer;
	m_pPlayer = NULL;

	delete m_pMonster;
	m_pMonster = NULL;

	delete m_pBullet;
	m_pBullet = NULL;
}
