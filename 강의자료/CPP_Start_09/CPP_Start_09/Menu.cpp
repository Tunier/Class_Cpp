#include "Menu.h"
#include "SceneManager.h"

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
	if (GetAsyncKeyState('S'))
		SceneManager::GetInstance()->SetScene(SCENEIDS_STAGE);
}

void Menu::Render()
{
	cout << "Menu" << endl;
}

void Menu::Release()
{
}
