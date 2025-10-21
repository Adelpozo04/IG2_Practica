#include "Character.h"
#include "constantes.h"

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

bool Character::CanGo(Ogre::Vector3 dir, MazeManager* MM)
{
	if (dir != Ogre::Vector3::ZERO) {
		Ogre::Vector3 nextPos = getPosition() + (dir * CUBE_SIZE/2 * 1.1);
		return MM->IsTrasferable(nextPos);
	}
	else {
		return MM->IsTrasferable(getPosition());
	}
}

bool Character::canTurn(Ogre::Vector3 dir, MazeManager* MM)
{
	
	return CanGo(dir,MM) && passCenterTile(dir, MM);
}

bool Character::passCenterTile(Ogre::Vector3 dir, MazeManager* MM)
{
	bool ret = false;

	Vector3 pos = getPosition();
	Vector3 nextPos = pos + (getDir() * getSpeed());
	Vector3 centro = MM->getTileCenter(pos);

	return ((pos.x >= centro.x && pos.z >= centro.z) && (nextPos.x <= centro.x && nextPos.z <= centro.z)) ||
		((nextPos.x >= centro.x && nextPos.z >= centro.z) && (pos.x <= centro.x && pos.z <= centro.z));

}

