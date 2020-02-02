#include "Bullet.h"
#include "Player.h"
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
	m_tInfo.Position = ObjectManager::GetInstance()->GetPlayer()->SetPosition;
}

void Bullet::Update()
{
	m_tInfo.Position = ObjectManager::GetInstance()->GetPlayer()->GetPosition();
}

void Bullet::Render()
{
	DoubleBuffer::GetInstance()->WriteBuffer(
		m_tInfo.Position.x,
		m_tInfo.Position.y,
		(char*)"O");
}

void Bullet::Release()
{
}
