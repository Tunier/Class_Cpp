#include "Clear.h"
#include "SceneManager.h"
#include "InputManager.h"

#include "DoubleBuffer.h"

Clear::Clear()
{
}

Clear::~Clear()
{
}

void Clear::Initialize()
{
}

void Clear::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	switch (dwKey)
	{
	case KEYID_ENTER:
		SceneManager::GetInstance()->SetScene(SCENEIDES_EXIT);
		break;
	}
}

void Clear::Render()
{
	DoubleBuffer::GetInstance()->WriteBuffer(
		CONSOL_MAX_WIDTH / 2,
		CONSOL_MAX_HEIGHT / 2,
		(char*)"Clear!!");
}

void Clear::Release()
{
}
