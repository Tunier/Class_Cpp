#include "Bullet.h"
#include "DoubleBuffer.h"
#include "ObjectManager.h"

Bullet::Bullet()
{

}

Bullet::~Bullet()
{

}

void Bullet::Initialize()
{
	switch (ObjectManager::GetInstance()->GetPlayer()->GetRotate())
	{
	case ROTATEIDS_UP:
		m_tInfo.Position.x = ObjectManager::GetInstance()->GetPlayer()->GetPosition().x;
		m_tInfo.Position.y = ObjectManager::GetInstance()->GetPlayer()->GetPosition().y - 1;
		m_tInfo.Rotate = ROTATEIDS_UP;
		break;

	case ROTATEIDS_DOWN:
		m_tInfo.Position.x = ObjectManager::GetInstance()->GetPlayer()->GetPosition().x;
		m_tInfo.Position.y = ObjectManager::GetInstance()->GetPlayer()->GetPosition().y + 1;
		m_tInfo.Rotate = ROTATEIDS_DOWN;
		break;

	case ROTATEIDS_LEFT:
		m_tInfo.Position.x = ObjectManager::GetInstance()->GetPlayer()->GetPosition().x - 2;
		m_tInfo.Position.y = ObjectManager::GetInstance()->GetPlayer()->GetPosition().y;
		m_tInfo.Rotate = ROTATEIDS_LEFT;
		break;

	case ROTATEIDS_RIGHT:
		m_tInfo.Position.x = ObjectManager::GetInstance()->GetPlayer()->GetPosition().x + 2;
		m_tInfo.Position.y = ObjectManager::GetInstance()->GetPlayer()->GetPosition().y;
		m_tInfo.Rotate = ROTATEIDS_RIGHT;
		break;

	case ROTATEIDS_NEUTRALITY:
		m_tInfo.Rotate = ROTATEIDS_NEUTRALITY;
		break;
	}
	
	m_tInfo.Position = Vector3();

	m_tInfo.Scale = Vector3(1.f, 1.f);

	m_tInfo.bRender = 0;
}

void Bullet::Update()
{
	switch (m_tInfo.Rotate)
	{
	case ROTATEIDS_UP:
		m_tInfo.Position.y -= 1;
		break;

	case ROTATEIDS_DOWN:
		m_tInfo.Position.y += 1;
		break;

	case ROTATEIDS_LEFT:
		m_tInfo.Position.x -= 2;
		break;

	case ROTATEIDS_RIGHT:
		m_tInfo.Position.x += 2;
		break;
	}

}

void Bullet::Render()
{
	DoubleBuffer::GetInstance()->WriteBuffer(
		m_tInfo.Position.x,
		m_tInfo.Position.y,
		(char*)"B");
}

void Bullet::Release()
{
}
