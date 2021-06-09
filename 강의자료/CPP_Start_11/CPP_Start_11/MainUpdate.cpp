#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"

#include "Player.h"
#include "ObjectFactory.h"
#include "ObjectManager.h"

MainUpdate::MainUpdate()
{

}

MainUpdate::~MainUpdate()
{

}

void MainUpdate::Initialize()
{
	ObjectManager::GetInstance()->SetPlayer(
		ObjectFactory<Player>::CreateObject( Vector3(0, 0) ) );`

	SceneManager::GetInstance()->SetScene(SCENEIDS_LOGO);
}

void MainUpdate::Update()
{
	InputManager::GetInstance()->Checkkey();
	SceneManager::GetInstance()->Update();
}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render();
}

void MainUpdate::Release()
{

}
