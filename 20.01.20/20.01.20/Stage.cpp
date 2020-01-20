#include "Stage.h"
#include "SceneManager.h"
#include "ObjectFactory.h"


Stage::Stage()
{
}

Stage::~Stage()
{
	Release();
}

void Stage::Initialize()
{
	m_pPlayer = ObjectFactory::CreatePlayer();
	m_pMonster = ObjectFactory::CreateMonster();
	m_pBullet = ObjectFactory::CreateBullet();
}


void Stage::Update()
{
	m_pPlayer->Update();
	m_pMonster->Update();
	m_pBullet->Update();
	
	if (GetAsyncKeyState('D'))
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
	delete m_pPlayer;
	m_pPlayer = NULL;

	delete m_pMonster;
	m_pMonster = NULL;

	delete m_pBullet;
	m_pBullet = NULL;
}
