#include "CharacterManager.h"

CharacterManager::CharacterManager() : mSM(nullptr), _MM(nullptr)
{

}

CharacterManager::CharacterManager(Ogre::SceneManager* SM, MazeManager* MM) : mSM(SM), _MM(MM)
{

}

Ogre::Vector3 CharacterManager::CalculateOffset(Character* ch) {
	return ((_MM->GetTileSize() - ch->calculateBoxSize()) / 2) + (ch->calculateBoxSize() / 2);
}
