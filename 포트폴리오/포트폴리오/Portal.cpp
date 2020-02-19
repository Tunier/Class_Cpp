#include "Portal.h"
#include "ObjectManager.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "DoubleBuffer.h"

#include "Stage.h"

Portal::Portal()
{
}

Portal::~Portal()
{
}

void Portal::Initialize()
{
	m_tInfo.Position = Vector3();

	m_tInfo.Scale = Vector3(4.f, 2.f);

	m_tInfo.bRender = 0;
}

void Portal::Update()
{
	/*int MonsterAliveCheck = 1;

	for (int i = 0; i < 64; ++i)
	{
		if (ObjectManager::GetInstance()->GetMonster(i)->GetRender() == 1)
		{
			MonsterAliveCheck = 1;
		}
	}*/


}

void Portal::Render()
{
	DoubleBuffer::GetInstance()->WriteBuffer(
		m_tInfo.Position.x,
		m_tInfo.Position.y,
		(char*)"@ @");
	DoubleBuffer::GetInstance()->WriteBuffer(
		m_tInfo.Position.x,
		m_tInfo.Position.y + 1,
		(char*)"@ @");
}

void Portal::Release()
{
}
