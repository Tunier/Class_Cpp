#include "Option.h"
#include "SceneManager.h"
#include "InputManager.h"

#include "DoubleBuffer.h"

Option::Option()
{
}

Option::~Option()
{
}

void Option::Initialize()
{
}

void Option::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	switch (dwKey)
	{
	case KEYID_ENTER:
		SceneManager::GetInstance()->SetScene(SCENEIDES_MENU);
		break;
	}
}

void Option::Render()
{
	DoubleBuffer::GetInstance()->WriteBuffer(
		CONSOL_MAX_WIDTH / 2,
		CONSOL_MAX_HEIGHT / 2,
		(char*)"Option");
}

void Option::Release()
{
}
