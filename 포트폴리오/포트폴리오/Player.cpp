#include "Player.h"
#include "ObjectManager.h"
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
	m_tInfo.Rotate = ROTATEIDS_RIGHT;

	m_tInfo.Scale = Vector3(2.f, 1.f);
}

void Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	switch (dwKey)
	{
	case KEYID_UP:
		m_tInfo.Position.y -= 1;
		m_tInfo.Rotate = ROTATEIDS_UP;
		break;

	case KEYID_DOWN:
		m_tInfo.Position.y += 1;
		m_tInfo.Rotate = ROTATEIDS_DOWN;
		break;

	case KEYID_LEFT:
		m_tInfo.Position.x -= 2;
		m_tInfo.Rotate = ROTATEIDS_LEFT;
		break;

	case KEYID_RIGHT:
		m_tInfo.Position.x += 2;
		m_tInfo.Rotate = ROTATEIDS_RIGHT;
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
