#include "Wall2.h"
#include "ObjectManager.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "DoubleBuffer.h"

Wall2::Wall2()
{
}

Wall2::~Wall2()
{
}

void Wall2::Initialize()
{
	m_tInfo.Position = Vector3();

	m_tInfo.Scale = Vector3(4.f, 2.f);

	m_tInfo.bRender = 0;
}

void Wall2::Update()
{
}

void Wall2::Render()
{
}

void Wall2::Release()
{
}
