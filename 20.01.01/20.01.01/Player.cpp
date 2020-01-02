#include "Player.h"

Player::Player()
{
	cout << "Player:: 持失切" << endl;
}

Player::~Player()
{
	Release();

	cout << "Player:: 社瑚切" << endl;
}

void Player::Initialize()
{
	cout << "Player::Initialize" << endl;
	Att = 100;
	Def = 100;
}

void Player::Progress()
{
	cout << "Player::Progress" << endl;
}

void Player::Render()
{
	cout << "Player::Render" << endl;

	cout << "Monster Att : " << Att << endl;
	cout << "Monster Def : " << Def << endl;
}

void Player::Release()
{
	cout << "Player::Release" << endl;
}
