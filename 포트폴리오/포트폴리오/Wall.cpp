#include "Wall.h"
#include "ObjectManager.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "DoubleBuffer.h"

Wall::Wall()
{

}

Wall::~Wall()
{

}

void Wall::Initialize()
{
	m_tInfo.Scale = Vector3(2.f, 1.f);

	m_tInfo.bRender = 0;
}

void Wall::Update()
{
	
}

void Wall::Render()
{
	DoubleBuffer::GetInstance()->WriteBuffer(
		m_tInfo.Position.x,
		m_tInfo.Position.y,
		(char*)"W");
}

void Wall::Release()
{

}
