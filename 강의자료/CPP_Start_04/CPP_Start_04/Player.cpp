#include "Player.h"



Player::Player()
{
	cout << "Player:: ������" << endl;
}

Player::~Player()
{
	cout << "Player:: �Ҹ���" << endl;
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