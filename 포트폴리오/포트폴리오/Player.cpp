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

	m_tInfo.bRender = 1;

	m_tInfo.Position = Vector3(10.f, 10.f);
}

void Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();



	switch (dwKey)
	{
	case KEYID_UP:
		for (int i = 0; i < 512; ++i)
		{
			if (!(m_tInfo.Position.y - 2 == ObjectManager::GetInstance()->GetWall(i)->GetPosition().y)) {}
			else
			{
				m_tInfo.Position.y -= 1;
				break;
			}
			m_tInfo.Rotate = ROTATEIDS_UP;
		}
		break;

	case KEYID_DOWN:
		for (int i = 0; i < 512; ++i)
		{
			if (!(m_tInfo.Position.y + 2 == ObjectManager::GetInstance()->GetWall(i)->GetPosition().y)) {}
			else
			{
				m_tInfo.Position.y += 1;
				break;
			}
			m_tInfo.Rotate = ROTATEIDS_DOWN;
		}
		break;

	case KEYID_LEFT:
		for (int i = 0; i < 512; ++i)
		{
			if (!(m_tInfo.Position.x - 4 == ObjectManager::GetInstance()->GetWall(i)->GetPosition().x)) {}
			else
			{
				m_tInfo.Position.x -= 2;
				break;
			}
			m_tInfo.Rotate = ROTATEIDS_LEFT;
		}
		break;

	case KEYID_RIGHT:
		for (int i = 0; i < 512; ++i)
		{
			if (!(m_tInfo.Position.x + 4 == ObjectManager::GetInstance()->GetWall(i)->GetPosition().x)) {}
			else
			{
				m_tInfo.Position.x += 2;
				break;
			}
			m_tInfo.Rotate = ROTATEIDS_RIGHT;
		}
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
