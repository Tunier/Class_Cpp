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
	m_tInfo.Position = Vector3(30.f, 30.f);
}

void Bullet::Update()
{
	Object
}

void Bullet::Render()
{
	DoubleBuffer::GetInstance()->WriteBuffer(
		m_tInfo.Position.x,
		m_tInfo.Position.y,
		(char*)"��");
}

void Bullet::Release()
{
}
