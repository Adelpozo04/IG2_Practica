#include "CharacterManager.h"

CharacterManager::CharacterManager() : mSM(nullptr), _MM(nullptr)
{

}

CharacterManager::CharacterManager(Ogre::SceneManager* SM, MazeManager* MM) : mSM(SM), _MM(MM)
{

}

