#include "PlayerManager.h"

PlayerManager::PlayerManager() : _player(nullptr), mSM(nullptr), _MM(nullptr)
{


}

PlayerManager::PlayerManager(Ogre::SceneManager* SM, String mesh, MazeManager* MM) : mSM (SM), _MM(MM)
{

	CreatePlayer(_MM->GetPlayerInitialPos(), mesh);
	_player->setOffset(CalculateOffset());

}

void PlayerManager::CreatePlayer(Ogre::Vector3 initPos, String mesh)
{
	SceneNode* mPlayerNode = mSM->getRootSceneNode()->createChildSceneNode("nPlayer");
	_player = new Player(initPos, mPlayerNode, mSM, mesh);
}

bool PlayerManager::CanGo(Ogre::Vector3 dir)
{
	if (dir != Ogre::Vector3::ZERO) {
		Ogre::Vector3 nextPos = _player->getPosition() + (dir * _player->getSpeed());
		return _MM->IsTrasferable(nextPos);
	}
	else {
		return _MM->IsTrasferable(_player->getPosition());
	}
	
}

Ogre::Vector3 PlayerManager::CalculateOffset()
{
	return ((_MM->GetTileSize() - _player->calculateBoxSize()) / 2) + (_player->calculateBoxSize() / 2);
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

	if (CanGo(_player->getNextDir() * _player->getOffset().x)) {

		if (_player->getNextDir() != Ogre::Vector3::ZERO) {
			_player->setDir(_player->getNextDir());
		}	
		_player->setNextDir({ 0, 0, 0 });
	}

	if (!CanGo(_player->getDir() * _player->getOffset().x)) {
		_player->setDir({ 0, 0, 0 });
	}

	Ogre::Vector3 newPos = _player->getPosition() + (_player->getDir() * _player->getSpeed());
	_player->setPosition(newPos);

}

