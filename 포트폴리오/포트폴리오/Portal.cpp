#include "Portal.h"
#include "ObjectManager.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "DoubleBuffer.h"

Portal::Portal()
{
}

Portal::~Portal()
{
}

void Portal::Initialize()
{
	m_tInfo.Position = Vector3(Vector3(56.f, 14.f));

	m_tInfo.Scale = Vector3(4.f, 2.f);

	m_tInfo.bRender = 0;
}

void Portal::Update()
{
	int MonsterAliveCheck = 0;

	for (int i = 0; i < 64; ++i)
	{
		if (ObjectManager::GetInstance()->GetMonster(i)->GetRender() == 1)
		{
			MonsterAliveCheck = 1;
		}
	}

	if (ObjectManager::GetInstance()->GetPlayer()->GetPosition().x < m_tInfo.Position.x + m_tInfo.Scale.x &&
		m_tInfo.Position.x < ObjectManager::GetInstance()->GetPlayer()->GetPosition().x + ObjectManager::GetInstance()->GetPlayer()->GetScale().x &&
		(ObjectManager::GetInstance()->GetPlayer()->GetPosition().y == m_tInfo.Position.y ||
			ObjectManager::GetInstance()->GetPlayer()->GetPosition().y == m_tInfo.Position.y + 1) &&
		MonsterAliveCheck == 0)
	{
		SceneManager::GetInstance()->SetScene(SCENEIDES_CLEAR);
	}

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
