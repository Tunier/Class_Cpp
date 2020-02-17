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
	m_tInfo.Position = Vector3(10.f, 11.f);

	m_tInfo.Scale = Vector3(2.f, 1.f);

	m_tInfo.Rotate = ROTATEIDS_RIGHT;

	m_tInfo.bRender = 0;
}

void Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	int CollisionCheck = 0;

	switch (dwKey)
	{
	case KEYID_UP:
		for (int i = 0; i < 512; ++i)
		{
			if (ObjectManager::GetInstance()->GetWall(i)->GetPosition().y + ObjectManager::GetInstance()->GetWall(i)->GetScale().y == m_tInfo.Position.y &&
				m_tInfo.Position.x == ObjectManager::GetInstance()->GetWall(i)->GetPosition().x)
				CollisionCheck = 1;
			
			if (CollisionCheck == 1)
				break;
		}

		if (CollisionCheck == 0)
		{
			m_tInfo.Position.y -= 1;
		}	

		m_tInfo.Rotate = ROTATEIDS_UP;
		break;

	case KEYID_DOWN:
		for (int i = 0; i < 512; ++i)
		{
			if (ObjectManager::GetInstance()->GetWall(i)->GetPosition().y == m_tInfo.Position.y + m_tInfo.Scale.y &&
				m_tInfo.Position.x == ObjectManager::GetInstance()->GetWall(i)->GetPosition().x)
				CollisionCheck = 1;

			if (CollisionCheck == 1)
				break;
		}

		if (CollisionCheck == 0)
		{
			m_tInfo.Position.y += 1;
		}

		m_tInfo.Rotate = ROTATEIDS_DOWN;
		break;

	case KEYID_LEFT:
		for (int i = 0; i < 512; ++i)
		{
			if (ObjectManager::GetInstance()->GetWall(i)->GetPosition().x + ObjectManager::GetInstance()->GetWall(i)->GetScale().x == m_tInfo.Position.x &&
				m_tInfo.Position.y == ObjectManager::GetInstance()->GetWall(i)->GetPosition().y)
				CollisionCheck = 1;

			if (CollisionCheck == 1)
				break;
		}

		if (CollisionCheck == 0)
		{
			m_tInfo.Position.x -= 2;
		}

		m_tInfo.Rotate = ROTATEIDS_LEFT;
		break;

	case KEYID_RIGHT:
		for (int i = 0; i < 512; ++i)
		{
			if (ObjectManager::GetInstance()->GetWall(i)->GetPosition().x == m_tInfo.Position.x + m_tInfo.Scale.x &&
				m_tInfo.Position.y == ObjectManager::GetInstance()->GetWall(i)->GetPosition().y)
				CollisionCheck = 1;

			if (CollisionCheck == 1)
				break;
		}

		if (CollisionCheck == 0)
		{
			m_tInfo.Position.x += 2;
		}

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
