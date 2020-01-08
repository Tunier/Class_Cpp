#include "MainUpdate.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

MainUpdate::MainUpdate()
{

}

MainUpdate::~MainUpdate()
{
	Release();
}

void MainUpdate::Initialize()
{
	m_iState = 0;

	m_pLogo = new Logo;
	m_pLogo->Initialize();

	m_pMenu = new Menu;
	m_pMenu->Initialize();

	m_pStage = new Stage;
	m_pStage->Initialize();
}

void MainUpdate::Update()
{
	switch (m_iState)
	{
	case 0:
		m_pLogo->Update();
		break;

	case 1:
		m_pMenu->Update();
		break;

	case 2:
		m_pStage->Update();
		break;
	}
}

void MainUpdate::Render()
{
	switch (m_iState)
	{
	case 0:
		m_pLogo->Render();
		break;

	case 1:
		m_pMenu->Render();
		break;

	case 2:
		m_pStage->Render();
		break;
	}

	if (m_iState < 3)
		m_iState++;
}

void MainUpdate::Release()
{
	delete m_pLogo;
	m_pLogo = NULL;

	delete m_pMenu;
	m_pMenu = NULL;

	delete m_pStage;
	m_pStage = NULL;
}
