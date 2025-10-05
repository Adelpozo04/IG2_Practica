#include "PlayerManager.h"

PlayerManager::PlayerManager() : _player(nullptr), mSM(nullptr)
{


}

PlayerManager::PlayerManager(Ogre::SceneManager* SM, Ogre::Vector3 initPos, String mesh) : mSM (SM)
{

	CreatePlayer(initPos, mesh);

}

void PlayerManager::CreatePlayer(Ogre::Vector3 initPos, String mesh)
{

	SceneNode* mPlayerNode = mSM->getRootSceneNode()->createChildSceneNode("nPlayer");
	_player = new Player(initPos, mPlayerNode, mSM, mesh);

}

bool PlayerManager::keyPressed(const OgreBites::KeyboardEvent& evt) {

	switch (evt.keysym.sym)
	{
	case SDLK_UP:

		_nextDir = Ogre::Vector3::UNIT_Z;
		break;

	case SDLK_DOWN:

		_nextDir = Ogre::Vector3::NEGATIVE_UNIT_Z;
		break;

	case SDLK_RIGHT:

		_nextDir = Ogre::Vector3::NEGATIVE_UNIT_X;
		break;

	case SDLK_LEFT:

		_nextDir = Ogre::Vector3::UNIT_X;
		break;

	}

	return true;

}

void PlayerManager::frameRendered(const Ogre::FrameEvent& evt) {

	

	Ogre::Vector3 newPos = _player->getPosition() + (_currentDir * _player->getSpeed());
	_player->setPosition(newPos);

}

