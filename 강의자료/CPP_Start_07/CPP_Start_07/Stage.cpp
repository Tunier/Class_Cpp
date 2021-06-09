#include "Stage.h"

#include "Player.h"
#include "Monster.h"


Stage::Stage()
{
}

Stage::~Stage()
{
	Release();
}

void Stage::Initialize()
{
	m_pPlayer = new Player;
	m_pPlayer->Initialize();

	m_pMonster = new Monster;
	m_pMonster->Initialize();
}

void Stage::Update()
{
	m_pPlayer->Update();
	m_pMonster->Update();
}

void Stage::Render()
{
	m_pPlayer->Render();
	m_pMonster->Render();
}

void Stage::Release()
{
	delete m_pPlayer;
	m_pPlayer = NULL;

	delete m_pMonster;
	m_pMonster = NULL;
}
