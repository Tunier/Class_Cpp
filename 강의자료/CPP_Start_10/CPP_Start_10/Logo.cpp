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
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey &= KEYID_ENTER)
		SceneManager::GetInstance()->SetScene(SCENEIDS_MENU);
}

void Logo::Render()
{
	cout << "Logo" << endl;
}

void Logo::Release()
{
}
