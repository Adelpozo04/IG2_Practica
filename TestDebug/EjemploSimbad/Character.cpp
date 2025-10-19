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
		Ogre::Vector3 nextPos = getPosition() + (dir * CUBE_SIZE/2);
		return MM->IsTrasferable(nextPos);
	}
	else {
		return MM->IsTrasferable(getPosition());
	}
}

bool Character::canTurn(Ogre::Vector3 dir, MazeManager* MM)
{
	bool ret = false;

	Vector3 pos = getPosition();
	Vector3 centro = MM->getTileCenter(pos);

	if (dir == Ogre::Vector3::UNIT_X || dir == Ogre::Vector3::UNIT_Z) {
		ret = pos.x >= centro.x &&  pos.z >= centro.z;
	}
	else if (dir == Ogre::Vector3::NEGATIVE_UNIT_X || dir == Ogre::Vector3::NEGATIVE_UNIT_Z) {
		ret = pos.x <= centro.x && pos.z <= centro.z;
	}
	return ret;
}

