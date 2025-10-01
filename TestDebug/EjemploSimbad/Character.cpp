#include "Character.h"

Character::Character(): IG2Object(), _lifes(3), _speed(2.5)
{
}

Character::Character(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, int lifes, int speed) :
	IG2Object(initPos, node, sceneMng), _lifes(lifes), _speed(speed)
{
}

Character::Character(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh, int lifes, int speed) :
	IG2Object(initPos, node, sceneMng, mesh), _lifes(lifes), _speed(speed)
{
}
