#include "InputManager.h"

InputManager* InputManager::m_pInstance = NULL;

void InputManager::CheckKey()
{
	dwKey = 0;
	
	if (GetAsyncKeyState(VK_UP))
		dwKey |= KEYID_UP;
	
	if (GetAsyncKeyState(VK_DOWN))
		dwKey |= KEYID_DOWN;
	
	if (GetAsyncKeyState(VK_LEFT))
		dwKey |= KEYID_LEFT;
	
	if (GetAsyncKeyState(VK_RIGHT))
		dwKey |= KEYID_RIGHT;
	
	if (GetAsyncKeyState(VK_SPACE))
		dwKey |= KEYID_SPACE;
	
	if (GetAsyncKeyState(VK_RETURN))
		dwKey |= KEYID_ENTER;
	
	if (GetAsyncKeyState(VK_ESCAPE))
		dwKey |= KEYID_ESCAPE;
	
	if (GetAsyncKeyState(VK_SHIFT))
		dwKey |= KEYID_SHIFT;
	
}
