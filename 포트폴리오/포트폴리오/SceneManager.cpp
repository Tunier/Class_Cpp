#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"
#include "BossStage.h"
#include "Option.h"
#include "Clear.h"
#include "About.h"

SceneManager* SceneManager::m_pInstance = NULL;

SceneManager::SceneManager() : m_SceneState(NULL)
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::SetScene(SCENEIDE _sceneID)
{
	if (m_SceneState != NULL)
	{
		delete m_SceneState;
		m_SceneState = NULL;
	}

	switch (_sceneID)
	{
	case SCENEIDES_LOGO:
		m_SceneState = new Logo;
		break;

	case SCENEIDES_MENU:
		m_SceneState = new Menu;
		break;

	case SCENEIDES_STAGE:
		m_SceneState = new Stage;
		break;

	case SCENEIDES_BOSS_STAGE:
		m_SceneState = new BossStage;
		break;

	case SCENEIDES_OPTION:
		m_SceneState = new Option;
		break;

	case SCENEIDES_ABOUT:
		m_SceneState = new About;
		break;

	case SCENEIDES_CLEAR:
		m_SceneState = new Clear;
		break;

	case SCENEIDES_EXIT:
		exit(NULL);
		break;
	}

	m_SceneState->Initialize();
}

void SceneManager::Update()
{
	m_SceneState->Update();
}

void SceneManager::Render()
{
	m_SceneState->Render();
}