#include "Menu.h"
#include "SceneManager.h"
#include "InputManager.h"

#include "DoubleBuffer.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::Initialize()
{
}

void Menu::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey &= KEYID_ENTER)
		SceneManager::GetInstance()->SetScene(SCENEIDS_STAGE);
}

void Menu::Render()
{
	DoubleBuffer::GetInstance()->WriteBuffer(
		CONSOL_MAX_WIDTH / 2,
		CONSOL_MAX_HEIGHT / 2,
		(char*)"Menu");
}

void Menu::Release()
{
}
