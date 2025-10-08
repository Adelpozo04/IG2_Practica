#include "Hero.h"

Hero::Hero(Vector3 initPos, Vector3 dirAct, SceneNode* node, SceneManager* sceneMng, string meshName, float speed, uint iniLifes, uint iniPoints):
	Mob(initPos,dirAct,node,sceneMng,meshName, speed), nLifes(iniLifes), points(iniPoints)
{
}

Hero::~Hero()
{
}
