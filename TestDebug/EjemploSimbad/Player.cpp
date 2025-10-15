#include "Player.h"
#include "constantes.h"

Player::Player() :
	Character()
{
	_lifes = PLAYER_LIFES;
	_speed = PLAYER_SPEED;
	_currentDir = { 0, 0, 0 };
	_nextDir = { 0, 0, 0 };
	_offset = { 0, 0, 0 };
	Config();
}

Player::Player(Vector3 initPos, SceneNode* node, SceneManager* sceneMng) :
	Character(initPos, node, sceneMng)
{
	_lifes = PLAYER_LIFES;
	_speed = PLAYER_SPEED;
	_currentDir = { 0, 0, 0 };
	_nextDir = { 0, 0, 0 };
	_offset = { 0, 0, 0 };
	Config();
}

Player::Player(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh):
	Character(initPos, node, sceneMng, mesh)
{
	_lifes = PLAYER_LIFES;
	_speed = PLAYER_SPEED;
	_currentDir = { 0, 0, 0 };
	_nextDir = { 0, 0, 0 };
	_offset = { 0, 0, 0 };
	Config();
}

void Player::Config()
{
	setScale(PLAYER_SCALE);
}


