#include "Player.h"


void Player::Initialize()
{
	Att = 10;
	Def = 10;
}

void Player::Progress()
{

}

void Player::Render()
{
	cout << "Player Att : " << Att << endl;
	cout << "Player Def : " << Def << endl;
}

void Player::Release()
{

}
