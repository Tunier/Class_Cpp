#include "Stage.h"
#include "SceneManager.h"

Stage::Stage()
{

}

Stage::~Stage()
{

}

void Stage::Initailize()
{
	cout << "Stage" << endl;
	SceneManager::GetInstance()->SetScene(SCENEIDS_EXIT);
}

void Stage::Update()
{

}

void Stage::Render()
{

}

void Stage::Release()
{

}
