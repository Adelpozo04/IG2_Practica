#include "Enemy.h"

Enemy::Enemy() : Character()
{



}

Enemy::Enemy(Vector3 initPos, SceneNode* node, SceneManager* sceneMng) : 
	Character(initPos, node, sceneMng)
{



}

Enemy::Enemy(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh) : 
	Character(initPos, node, sceneMng, mesh)
{

}
