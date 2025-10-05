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

	Ogre::Vector3 newPos;

	switch (evt.keysym.sym)
	{
	case SDLK_UP:

		newPos = _player->getPosition() + (Ogre::Vector3::UNIT_Z * _player->getSpeed());
		_player->setPosition(newPos);

		break;
	case SDLK_DOWN:

		newPos = _player->getPosition() + (Ogre::Vector3::NEGATIVE_UNIT_Z * _player->getSpeed());
		_player->setPosition(newPos);

		break;
	case SDLK_RIGHT:

		newPos = _player->getPosition() + (Ogre::Vector3::NEGATIVE_UNIT_X * _player->getSpeed());
		_player->setPosition(newPos);

		break;
	case SDLK_LEFT:

		newPos = _player->getPosition() + (Ogre::Vector3::UNIT_X * _player->getSpeed());
		_player->setPosition(newPos);

		break;
	}

	return true;

}

