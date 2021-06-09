#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

SceneManager* SceneManager::m_pInstance = NULL;


SceneManager::SceneManager() : m_SceneStage(NULL)
{
}


SceneManager::~SceneManager()
{
}

void SceneManager::SetScene(SCENEID _sceneID)
{
	if (m_SceneStage != NULL)
	{
		delete m_SceneStage;
		m_SceneStage = NULL;
	}

	switch (_sceneID)
	{
	case SCENEIDS_LOGO:
		m_SceneStage = new Logo;
		break;

	case SCENEIDS_MENU:
		m_SceneStage = new Menu;
		break;

	case SCENEIDS_STAGE:
		m_SceneStage = new Stage;
		break;

	case SCENEIDS_EXIT:
		cout << "게임이 종료 됩니다" << endl;
		exit(NULL);
		break;
	}

	m_SceneStage->Initialize();
}

void SceneManager::Update()
{
	m_SceneStage->Update();
}

void SceneManager::Render()
{
	m_SceneStage->Render();
}
