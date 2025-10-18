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

bool Character::CanGo(Ogre::Vector3 dir, MazeManager* MM)
{
	if (dir != Ogre::Vector3::ZERO) {
		Ogre::Vector3 nextPos = getPosition() + (dir * getSpeed());
		return MM->IsTrasferable(nextPos);
	}
	else {
		return MM->IsTrasferable(getPosition());
	}
}

