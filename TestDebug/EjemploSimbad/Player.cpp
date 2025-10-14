#include "Player.h"
#include "constantes.h"

Player::Player() :
	Character()
{
	_lifes = PLAYER_LIFES;
	_speed = PLAYER_SPEED;
	Config();
}

Player::Player(Vector3 initPos, SceneNode* node, SceneManager* sceneMng) :
	Character(initPos, node, sceneMng)
{
	_lifes = PLAYER_LIFES;
	_speed = PLAYER_SPEED;
	Config();
}

Player::Player(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh):
	Character(initPos, node, sceneMng, mesh)
{
	_lifes = PLAYER_LIFES;
	_speed = PLAYER_SPEED;
	Config();
}

void Player::Config()
{
	setScale(PLAYER_SCALE);
}


