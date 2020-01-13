#pragma once
#include "Headers.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();
public:
	virtual void Initailize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;
};

