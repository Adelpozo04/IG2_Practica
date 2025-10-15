#include "CharacterManager.h"

CharacterManager::CharacterManager() : mSM(nullptr), _MM(nullptr)
{

}

CharacterManager::CharacterManager(Ogre::SceneManager* SM, MazeManager* MM) : mSM(SM), _MM(MM)
{

}

bool CharacterManager::CanGo(Ogre::Vector3 dir, Character* ch) {

	if (dir != Ogre::Vector3::ZERO) {
		Ogre::Vector3 nextPos = ch->getPosition() + (dir * ch->getSpeed());
		return _MM->IsTrasferable(nextPos);
	}
	else {
		return _MM->IsTrasferable(ch->getPosition());
	}

}

Ogre::Vector3 CharacterManager::CalculateOffset(Character* ch) {
	return ((_MM->GetTileSize() - ch->calculateBoxSize()) / 2) + (ch->calculateBoxSize() / 2);
}
