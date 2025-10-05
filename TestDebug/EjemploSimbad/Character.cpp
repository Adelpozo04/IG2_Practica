#include "Character.h"

Character::Character(): IG2Object()
{
}

Character::Character(Vector3 initPos, SceneNode* node, SceneManager* sceneMng) :
	IG2Object(initPos, node, sceneMng)
{
}

Character::Character(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh) :
	IG2Object(initPos, node, sceneMng, mesh)
{
}

