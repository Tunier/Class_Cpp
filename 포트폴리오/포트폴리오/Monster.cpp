#include "Monster.h"
#include "DoubleBuffer.h"
#include "ObjectManager.h"

Monster::Monster()
{
}

Monster::~Monster()
{
}

void Monster::Initialize()
{
	m_tInfo.Position = Vector3();

	m_tInfo.Scale = Vector3(2.f, 1.f);

	m_tInfo.bRender = 0;

	m_tInfo.Rotate = ROTATEIDS_NEUTRALITY;

	m_dwTime = GetTickCount();
}

void Monster::Update()
{
	int CollisionCheck = 0;

	if (m_dwTime + 500 < GetTickCount())
	{
		m_dwTime = GetTickCount();

		srand(GetTickCount() * GetTickCount() * (rand() % 10 + 1));
		
		int iRand = rand() % 4 + 1;

		switch (iRand)
		{
		case 1:
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

		case 2:
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

		case 3:
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

		case 4:
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
}

void Monster::Render()
{
	DoubleBuffer::GetInstance()->WriteBuffer(
		m_tInfo.Position.x,
		m_tInfo.Position.y,
		(char*)"M");
}

void Monster::Release()
{
}
