#include "PlayerManager.h"

PlayerManager::PlayerManager() : CharacterManager(), _player(nullptr)
{


}

PlayerManager::PlayerManager(Ogre::SceneManager* SM, String mesh, MazeManager* MM) : CharacterManager(SM, MM)
{

	CreateCharacters(mesh);
	_player->setOffset(CalculateOffset(_player));

}

void PlayerManager::CreateCharacters(String mesh)
{
	Ogre::Vector3 initPos = _MM->GetPlayerInitialPos();
	SceneNode* mPlayerNode = mSM->getRootSceneNode()->createChildSceneNode("nPlayer");
	_player = new Player(initPos, mPlayerNode, mSM, mesh);
}

bool PlayerManager::keyPressed(const OgreBites::KeyboardEvent& evt) {

	switch (evt.keysym.sym)
	{
	case SDLK_UP:

		_player->setNextDir(Ogre::Vector3::UNIT_Z);		
		break;

	case SDLK_DOWN:

		_player->setNextDir(Ogre::Vector3::NEGATIVE_UNIT_Z);
		break;

	case SDLK_RIGHT:

		_player->setNextDir(Ogre::Vector3::NEGATIVE_UNIT_X);
		break;

	case SDLK_LEFT:

		_player->setNextDir(Ogre::Vector3::UNIT_X);
		break;

	}

	return true;

}

void PlayerManager::frameRendered(const Ogre::FrameEvent& evt) {

	if (CanGo(_player->getNextDir() * _player->getOffset().x, _player)) {

		if (_player->getNextDir() != Ogre::Vector3::ZERO) {
			_player->setDir(_player->getNextDir());
		}	
		_player->setNextDir({ 0, 0, 0 });
	}

	if (!CanGo(_player->getDir() * _player->getOffset().x, _player)) {
		_player->setDir({ 0, 0, 0 });
	}

	Ogre::Vector3 newPos = _player->getPosition() + (_player->getDir() * _player->getSpeed());
	_player->setPosition(newPos);

}

