#include "Logo.h"
#include "SceneManager.h"

Logo::Logo()
{

}

Logo::~Logo()
{

}

void Logo::Initailize()
{
	cout << "Logo" << endl;
	SceneManager::GetInstance()->SetScene(SCENEIDS_MENU);
}

void Logo::Update()
{

}

void Logo::Render()
{

}

void Logo::Release()
{

}
