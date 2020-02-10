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
	if (m_dwTime + 500 < GetTickCount())
	{
		m_dwTime = GetTickCount();

		srand(GetTickCount() * GetTickCount() * (rand() % 10 + 1));
		
		int iRand = rand() % 5 + 1;

		switch (iRand)
		{
		case 1:
			m_tInfo.Rotate = ROTATEIDS_NEUTRALITY;
			break;

		case 2:
			m_tInfo.Rotate = ROTATEIDS_UP;
			m_tInfo.Position.y -= 1;
			break;

		case 3:
			m_tInfo.Rotate = ROTATEIDS_DOWN;
			m_tInfo.Position.y += 1;
			break;

		case 4:
			m_tInfo.Rotate = ROTATEIDS_LEFT;
			m_tInfo.Position.x -= 2;
			break;

		case 5:
			m_tInfo.Rotate = ROTATEIDS_RIGHT;
			m_tInfo.Position.x += 2;
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
