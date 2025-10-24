#include "CharacterManager.h"

CharacterManager::~CharacterManager()
{
	for (auto& a : _characters) {
		delete a;
		a = nullptr;
	}
}

CharacterManager::CharacterManager() : mSM(nullptr), _MM(nullptr)
{

}

CharacterManager::CharacterManager(Ogre::SceneManager* SM, MazeManager* MM) : mSM(SM), _MM(MM)
{

}

