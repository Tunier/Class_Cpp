#include "About.h"
#include "SceneManager.h"
#include "InputManager.h"

#include "DoubleBuffer.h"

About::About()
{
}

About::~About()
{
}

void About::Initialize()
{
}

void About::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	switch (dwKey)
	{
	case KEYID_ENTER:
		SceneManager::GetInstance()->SetScene(SCENEIDES_MENU);
		break;
	}
}

void About::Render()
{
	DoubleBuffer::GetInstance()->WriteBuffer(
		CONSOL_MAX_WIDTH / 2,
		CONSOL_MAX_HEIGHT / 2,
		(char*)"About");
}

void About::Release()
{
}
