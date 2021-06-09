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
	//m_pPlayer = ObjectFactory<Player>::CreateObject( Vector3(0, 0) );
	m_pPlayer = ObjectManager::GetInstance()->GetPlayer();

	m_pMonster = ObjectFactory<Monster>::CreateObject();
	m_pBullet = ObjectFactory<Bullet>::CreateObject();
}

void Stage::Update()
{
	m_pPlayer->Update();
	m_pMonster->Update();
	m_pBullet->Update();
	
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey &= KEYID_ENTER)
		SceneManager::GetInstance()->SetScene(SCENEIDS_EXIT);
}

void Stage::Render()
{
	m_pPlayer->Render();
	m_pMonster->Render();
	m_pBullet->Render();

	cout << "Stage" << endl;
}

void Stage::Release()
{
	ObjectManager::GetInstance()->SetPlayer(m_pPlayer);

	delete m_pPlayer;
	m_pPlayer = NULL;

	delete m_pMonster;
	m_pMonster = NULL;

	delete m_pBullet;
	m_pBullet = NULL;
}
