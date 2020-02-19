#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"

#include "DoubleBuffer.h"

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
		SceneManager::GetInstance()->SetScene(SCENEIDES_MENU);
}

void Logo::Render()
{
	DoubleBuffer::GetInstance()->WriteBuffer(
		(CONSOL_MAX_WIDTH / 2) - 32,
		CONSOL_MAX_HEIGHT / 2 - 3,
		(char*)" _______  __   __  __    _  _______  _______  _______  __    _ ");
	
	DoubleBuffer::GetInstance()->WriteBuffer(
		(CONSOL_MAX_WIDTH / 2) - 32,
		(CONSOL_MAX_HEIGHT / 2) -2,
		(char*)"|       ||  | |  ||  |  | ||       ||       ||       ||  |  | |");

	DoubleBuffer::GetInstance()->WriteBuffer(
		(CONSOL_MAX_WIDTH / 2) - 32,
		(CONSOL_MAX_HEIGHT / 2) -1,
		(char*)"|    ___||  | |  ||   |_| ||    ___||    ___||   _   ||   |_| |");
	
	DoubleBuffer::GetInstance()->WriteBuffer(
		(CONSOL_MAX_WIDTH / 2) - 32,
		(CONSOL_MAX_HEIGHT / 2),
		(char*)"|   | __ |  |_|  ||       ||   | __ |   |___ |  | |  ||       |");
	
	DoubleBuffer::GetInstance()->WriteBuffer(
		(CONSOL_MAX_WIDTH / 2) - 32,
		(CONSOL_MAX_HEIGHT / 2)+1,
		(char*)"|   ||  ||       ||  _    ||   ||  ||    ___||  |_|  ||  _    |");
	
	DoubleBuffer::GetInstance()->WriteBuffer(
		(CONSOL_MAX_WIDTH / 2) - 32,
		(CONSOL_MAX_HEIGHT / 2) + 2,
		(char*)"|   |_| ||       || | |   ||   |_| ||   |___ |       || | |   |");
	
	DoubleBuffer::GetInstance()->WriteBuffer(
		(CONSOL_MAX_WIDTH / 2) - 32,
		(CONSOL_MAX_HEIGHT / 2) + 3,
		(char*)"|_______||_______||_|  |__||_______||_______||_______||_|  |__|");

/*
 _______  __   __  __    _  _______  _______  _______  __    _ 
|       ||  | |  ||  |  | ||       ||       ||       ||  |  | |
|    ___||  | |  ||   |_| ||    ___||    ___||   _   ||   |_| |
|   | __ |  |_|  ||       ||   | __ |   |___ |  | |  ||       |
|   ||  ||       ||  _    ||   ||  ||    ___||  |_|  ||  _    |
|   |_| ||       || | |   ||   |_| ||   |___ |       || | |   |
|_______||_______||_|  |__||_______||_______||_______||_|  |__|

*/

}

void Logo::Release()
{
}
