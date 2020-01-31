#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "DoubleBuffer.h"

#include "Object.h"

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

	SceneManager::GetInstance()->SetScene(SCENEIDES_LOGO);
}

void MainUpdate::Update()
{
	InputManager::GetInstance()->CheckKey();
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
