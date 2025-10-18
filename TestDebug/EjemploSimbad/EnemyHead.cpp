#include "EnemyHead.h"
#include "constantes.h"

EnemyHead::EnemyHead() :
	Enemy()
{
	_lifes = SIMPLE_ENEMY_LIFES;
	_speed = SIMPLE_ENEMY_SPEED;
	_currentDir = { 0, 0, 0 };
	_nextDir = { 0, 0, 0 };
	_offset = { 0, 0, 0 };
	Config();
}

EnemyHead::EnemyHead(Vector3 initPos, SceneNode* node, SceneManager* sceneMng) : 
	Enemy(initPos, node, sceneMng, SIMPLE_ENEMY_MESH_NAME)
{

	_lifes = SIMPLE_ENEMY_LIFES;
	_speed = SIMPLE_ENEMY_SPEED;
	_currentDir = { 0, 0, 0 };
	_nextDir = { 0, 0, 0 };
	_offset = { 0, 0, 0 };
	Config();
}

void EnemyHead::Config()
{
	setScale(SIMPLE_ENEMY_SCALE);
}

void EnemyHead::move(MazeManager* MM)
{

}

void EnemyHead::inlineAnimation()
{

}
