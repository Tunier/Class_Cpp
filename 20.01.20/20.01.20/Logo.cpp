#include "Logo.h"
#include "SceneManager.h"

Logo::Logo()
{
}

Logo::~Logo()
{
}

void Logo::Initialize()
{
}

void Logo::Update()
{
	if (GetAsyncKeyState('A'))
		SceneManager::GetInstance()->SetScene(SCENEIDS_MENU);
}

void Logo::Render()
{
	cout << "Logo" << endl;
}

void Logo::Release()
{
}
