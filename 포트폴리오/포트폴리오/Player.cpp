#include "Player.h"
#include "InputManager.h"
#include "DoubleBuffer.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	m_tInfo.Position = Vector3(10.f, 10.f);
}

void Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	switch (dwKey)
	{
	case KEYID_UP:
		m_tInfo.Position.y -= 1;
		break;

	case KEYID_DOWN:
		m_tInfo.Position.y += 1;
		break;

	case KEYID_LEFT:
		m_tInfo.Position.x -= 2;
		break;

	case KEYID_RIGHT:
		m_tInfo.Position.x += 2;
		break;
	}
}

void Player::Render()
{
	DoubleBuffer::GetInstance()->WriteBuffer(
		m_tInfo.Position.x,
		m_tInfo.Position.y,
		(char*)"P");
}

void Player::Release()
{
}
