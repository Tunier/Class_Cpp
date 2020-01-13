#include "Menu.h"
#include "SceneManager.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::Initailize()
{
	cout << "Menu" << endl;
	SceneManager::GetInstance()->SetScene(SCENEIDS_STAGE);
}

void Menu::Update()
{

}

void Menu::Render()
{

}

void Menu::Release()
{

}
