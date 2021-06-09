#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "DoubleBuffer.h"

#include "Player.h"
#include "ObjectFactory.h"
#include "ObjectManager.h"

MainUpdate::MainUpdate()
{

}

MainUpdate::~MainUpdate()
{
	Release();
}

void MainUpdate::Initialize()
{
	DoubleBuffer::GetInstance()->CreateBuffer(CONSOL_MAX_WIDTH, CONSOL_MAX_HEIGHT);

	//ObjectManager::GetInstance()->SetPlayer(\
		ObjectFactory<Player>::CreateObject( Vector3(10.f, 10.f) ) );

	SceneManager::GetInstance()->SetScene(SCENEIDS_LOGO);
}

void MainUpdate::Update()
{
	InputManager::GetInstance()->Checkkey();
	SceneManager::GetInstance()->Update();

	DoubleBuffer::GetInstance()->FlippingBuffer();
	DoubleBuffer::GetInstance()->ClearBuffer();
}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render();
}

void MainUpdate::Release()
{
	DoubleBuffer::GetInstance()->DestroyBuffer();
}
