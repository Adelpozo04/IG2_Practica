#include "PlayerManager.h"
#include "constantes.h"

PlayerManager::PlayerManager() : CharacterManager()
{


}

PlayerManager::PlayerManager(Ogre::SceneManager* SM, String mesh, MazeManager* MM) : CharacterManager(SM, MM)
{

	CreateCharacters(mesh);
	_characters.front()->setOffset(CalculateOffset(_characters.front()));

}

void PlayerManager::CreateCharacters(String mesh)
{
	Ogre::Vector3 initPos = _MM->GetPlayerInitialPos();
	SceneNode* mPlayerNode = mSM->getRootSceneNode()->createChildSceneNode("nPlayer");
	_characters.push_back(new Player(initPos, mPlayerNode, mSM, mesh));
	
}

bool PlayerManager::keyPressed(const OgreBites::KeyboardEvent& evt) {

	switch (evt.keysym.sym)
	{
	case SDLK_DOWN:

		_characters.front()->setNextDir(Ogre::Vector3::UNIT_Z);
		break;

	case SDLK_UP:

		_characters.front()->setNextDir(Ogre::Vector3::NEGATIVE_UNIT_Z);
		break;

	case SDLK_LEFT:

		_characters.front()->setNextDir(Ogre::Vector3::NEGATIVE_UNIT_X);
		break;

	case SDLK_RIGHT:

		_characters.front()->setNextDir(Ogre::Vector3::UNIT_X);
		break;

	}

	return true;

}

void PlayerManager::frameRendered(const Ogre::FrameEvent& evt) {

	if (CanGo(_characters.front()->getNextDir(), _characters.front())) {

		if (_characters.front()->getNextDir() != Ogre::Vector3::ZERO) {
			_characters.front()->setDir(_characters.front()->getNextDir());
		}	
		_characters.front()->setNextDir({ 0, 0, 0 });
	}

	if (!CanGo(_characters.front()->getDir(), _characters.front())) {
		_characters.front()->setDir({ 0, 0, 0 });
	}

	Ogre::Vector3 newPos = _characters.front()->getPosition() + (_characters.front()->getDir() * _characters.front()->getSpeed());
	_characters.front()->setPosition(newPos);

}
