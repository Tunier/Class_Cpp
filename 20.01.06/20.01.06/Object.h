#pragma once
#include "Headers.h"

class Object
{
public:
	Object();
	virtual ~Object();
private:

public:
	// 순수 가상 함수.
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

	/*
	virtual 함수 => 가상함수, 자식이 있을때 적용.
	new 로 정의된 class로 함수 적용됨.
	*/
};

