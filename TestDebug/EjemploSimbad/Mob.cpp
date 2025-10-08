#include "Mob.h"
#include "Config.h"
#include "MazeManager.h"

Mob::Mob(Vector3 initPos, Vector3 dirA, SceneNode* node, SceneManager* sceneMng, string meshName, float _speed) :
	IG2Object(initPos, node, sceneMng, meshName), speed(_speed), dirAct(dirA)
{
	//PosX = initPos.x + CUBE_SIZE * 0.5;
	//PosZ = initPos.z + CUBE_SIZE * 0.5;
	node->showBoundingBox(true);
}

Mob::~Mob()
{
}

void Mob::changeDirection(Vector3 newDir)
{
	newDir = newDir;
}