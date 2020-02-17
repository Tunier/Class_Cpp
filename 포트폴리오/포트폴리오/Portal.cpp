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
	m_tInfo.Position = Vector3();

	m_tInfo.Scale = Vector3(4.f, 2.f);

	m_tInfo.bRender = 0;
}

void Portal::Update()
{
}

void Portal::Render()
{
	DoubleBuffer::GetInstance()->WriteBuffer(
		m_tInfo.Position.x,
		m_tInfo.Position.y,
		(char*)"¦£ ¦¤");
	DoubleBuffer::GetInstance()->WriteBuffer(
		m_tInfo.Position.x,
		m_tInfo.Position.y+1,
		(char*)"¦¦ ¦¥");
}

void Portal::Release()
{
}
