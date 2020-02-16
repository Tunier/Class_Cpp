#include "Stone.h"
#include "ObjectManager.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "DoubleBuffer.h"

Stone::Stone()
{
}

Stone::~Stone()
{
}

void Stone::Initialize()
{
	m_tInfo.Position = Vector3();

	m_tInfo.Scale = Vector3(4.f, 2.f);

	m_tInfo.bRender = 0;
}

void Stone::Update()
{
}

void Stone::Render()
{
	DoubleBuffer::GetInstance()->WriteBuffer(
		m_tInfo.Position.x,
		m_tInfo.Position.y,
		(char*)"W W");
	DoubleBuffer::GetInstance()->WriteBuffer(
		m_tInfo.Position.x,
		m_tInfo.Position.y+1,
		(char*)"W W");
}

void Stone::Release()
{
}
