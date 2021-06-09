#include "Stage.h"
#include "SceneManager.h"


Stage::Stage()
{
}

Stage::~Stage()
{
}

void Stage::Initialize()
{
}

void Stage::Update()
{
	if (GetAsyncKeyState('D'))
		SceneManager::GetInstance()->SetScene(SCENEIDS_EXIT);
}

void Stage::Render()
{
	cout << "Stage" << endl;
}

void Stage::Release()
{
}
