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
	m_MenuState = 0;

	for (int i = 0; i < 5; ++i)
	{
		MenuButten[i] = new Transform;

		MenuButten[i]->Position = Vector3((float)57, (float)18 + i);

		MenuButten[i]->Scale = Vector3((float)0, (float)1);
	}

	MenuButten[0]->Position = Vector3((float)54, (float)18 + 1);
}

void Menu::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey == KEYID_UP)
	{
		if (m_MenuState != 0)
		{
			--m_MenuState;
			--MenuButten[0]->Position.y;
		}
	}

	if (dwKey == KEYID_DOWN)
	{
		if (m_MenuState != 3)
		{
			++m_MenuState;
			++MenuButten[0]->Position.y;
		}
	}
	
	if (dwKey == KEYID_ENTER)
	{
		switch (m_MenuState)
		{
		case 0:
			SceneManager::GetInstance()->SetScene(SCENEIDES_STAGE);
			break;

		case 1:
			SceneManager::GetInstance()->SetScene(SCENEIDES_OPTION);
			break;

		case 2:
			SceneManager::GetInstance()->SetScene(SCENEIDES_ABOUT);
			break;

		case 3:
			SceneManager::GetInstance()->SetScene(SCENEIDES_EXIT);
			break;
		}
	}
}

void Menu::Render()
{
	DoubleBuffer::GetInstance()->WriteBuffer(
		(CONSOL_MAX_WIDTH / 2) - 32,
		6,
		(char*)" _______  __   __  __    _  _______  _______  _______  __    _ ");

	DoubleBuffer::GetInstance()->WriteBuffer(
		(CONSOL_MAX_WIDTH / 2) - 32,
		7,
		(char*)"|       ||  | |  ||  |  | ||       ||       ||       ||  |  | |");

	DoubleBuffer::GetInstance()->WriteBuffer(
		(CONSOL_MAX_WIDTH / 2) - 32,
		8,
		(char*)"|    ___||  | |  ||   |_| ||    ___||    ___||   _   ||   |_| |");

	DoubleBuffer::GetInstance()->WriteBuffer(
		(CONSOL_MAX_WIDTH / 2) - 32,
		9,
		(char*)"|   | __ |  |_|  ||       ||   | __ |   |___ |  | |  ||       |");

	DoubleBuffer::GetInstance()->WriteBuffer(
		(CONSOL_MAX_WIDTH / 2) - 32,
		10,
		(char*)"|   ||  ||       ||  _    ||   ||  ||    ___||  |_|  ||  _    |");

	DoubleBuffer::GetInstance()->WriteBuffer(
		(CONSOL_MAX_WIDTH / 2) - 32,
		11,
		(char*)"|   |_| ||       || | |   ||   |_| ||   |___ |       || | |   |");

	DoubleBuffer::GetInstance()->WriteBuffer(
		(CONSOL_MAX_WIDTH / 2) - 32,
		12,
		(char*)"|_______||_______||_|  |__||_______||_______||_______||_|  |__|");
	
	DoubleBuffer::GetInstance()->WriteBuffer(
		MenuButten[0]->Position.x,
		MenuButten[0]->Position.y,
		(char*)"¢º");

	DoubleBuffer::GetInstance()->WriteBuffer(
		MenuButten[1]->Position.x,
		MenuButten[1]->Position.y,
		(char*)"Start");

	DoubleBuffer::GetInstance()->WriteBuffer(
		MenuButten[2]->Position.x,
		MenuButten[2]->Position.y,
		(char*)"Option");

	DoubleBuffer::GetInstance()->WriteBuffer(
		MenuButten[3]->Position.x,
		MenuButten[3]->Position.y,
		(char*)"About");

	DoubleBuffer::GetInstance()->WriteBuffer(
		MenuButten[4]->Position.x,
		MenuButten[4]->Position.y,
		(char*)"EXIT");
}

void Menu::Release()
{
}