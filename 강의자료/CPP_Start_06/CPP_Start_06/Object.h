#pragma once
#include "Headers.h"

class Object
{
public:
	Object();
	virtual ~Object();
public:
	//** 순수 가상 함수.
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;
};

