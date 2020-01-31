#include "ObjectManager.h"

ObjectManager* ObjectManager::m_pInstance = NULL;

ObjectManager::ObjectManager() : m_pPlayer(NULL)
{
}

ObjectManager::~ObjectManager()
{
}
