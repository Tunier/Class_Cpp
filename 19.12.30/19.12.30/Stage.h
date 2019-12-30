#pragma once
#include "Headers.h"

// 클레스 전방선언
class Player;

class Stage
{
public:
	Stage();	// 생성자
	~Stage();	// 소멸자

private:
	Player* P;
};

