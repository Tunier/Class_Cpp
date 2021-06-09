#include "Player.h"



Player::Player()
{
	cout << "Player:: 持失切" << endl;
}

Player::~Player()
{
	cout << "Player:: 社瑚切" << endl;
	Release();
}

void Player::Initialize()
{
	cout << "Player::Initialize" << endl;
	Att = 10;
	Def = 10;
}

void Player::Progress()
{
	cout << "Player::Progress" << endl;
}

void Player::Render()
{
	cout << "Player::Render" << endl;

	cout << "Player Att : " << Att << endl;
	cout << "Player Def : " << Def << endl;
}

void Player::Release()
{
	cout << "Player::Release" << endl;
}