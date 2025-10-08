#include "PlayerManager.h"

PlayerManager::PlayerManager() : _player(nullptr), mSM(nullptr), _MM(nullptr), _offset(0, 0, 0)
{


}

PlayerManager::PlayerManager(Ogre::SceneManager* SM, String mesh, MazeManager* MM) : mSM (SM), _MM(MM)
{

	CreatePlayer(_MM->GetPlayerInitialPos(), mesh);
	_offset = CalculateOffset();

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

	if (CanGo(_nextDir * _offset.x)) {

		if (_nextDir != Ogre::Vector3::ZERO) {
			_currentDir = _nextDir;
		}	
		_nextDir = { 0, 0, 0 };
	}

	if (!CanGo(_currentDir * _offset.x)) {
		_currentDir = { 0, 0, 0 };
	}

	Ogre::Vector3 newPos = _player->getPosition() + (_currentDir * _player->getSpeed());
	_player->setPosition(newPos);

}

