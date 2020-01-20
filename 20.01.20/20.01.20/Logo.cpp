#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"

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
	DWORD Key = InputManager::GetInstance()->GetKey();

	if (Key &= KEYID_ENTER)
		SceneManager::GetInstance()->SetScene(SCENEIDS_MENU);
}

void Logo::Render()
{
	cout << "Logo" << endl;
}

void Logo::Release()
{
}
