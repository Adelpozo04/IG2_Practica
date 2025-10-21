#include <stdlib.h>

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

EnemyHead::EnemyHead(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, MazeManager* MM) :
	Enemy(initPos, node, sceneMng, SIMPLE_ENEMY_MESH_NAME)
{

	_lifes = SIMPLE_ENEMY_LIFES;
	_speed = SIMPLE_ENEMY_SPEED;
	_currentDir = { 0, 0, 0 };
	_nextDir = { 0, 0, 0 };
	_offset = { 0, 0, 0 };
	Config();
	setDir(ChooseNextDir(MM));
	mNode->rotate(getOrientation().getRotationTo(getDir()));
}

void EnemyHead::Config()
{
	setScale(SIMPLE_ENEMY_SCALE);
}

void EnemyHead::move(MazeManager* MM, float dt)
{
	if (CanGo(getNextDir(), MM)) {
		if (getNextDir() != Ogre::Vector3::ZERO && canTurn(getNextDir(), MM, dt)) {
			setDir(getNextDir());
			Vector3 center = MM->getTileCenter(getPosition());
			setPosition(center);
			mNode->rotate(getOrientation().getRotationTo(getDir()));
			setNextDir({ 0, 0, 0 });
		}
	}

	if (passCenterTile(MM, dt)) {
		Vector3 selectDir = ChooseNextDir(MM);

		if (getDir() != selectDir) {
			setNextDir(selectDir);
		}	
	}

	if (!CanGo(getDir(), MM)) {
		setDir({ 0, 0, 0 });
		Vector3 center = MM->getTileCenter(getPosition());
		setPosition(center);
		setNextDir(ChooseNextDir(MM));
	}

	Ogre::Vector3 newPos = getPosition() + getDir() * getSpeed() * dt;

	if (newPos.x < MM->GetNumTilesX() * CUBE_SIZE.x && newPos.z < MM->GetNumTilesZ() * CUBE_SIZE.z &&
		newPos.x >= 0 && newPos.z >= 0) {
		IG2Object::move(getDir() * getSpeed() * dt);
	}
}

void EnemyHead::inlineAnimation(float dt)
{

}
