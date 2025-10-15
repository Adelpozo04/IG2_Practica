#include "PlayerManager.h"
#include "constantes.h"

PlayerManager::PlayerManager() : _player(nullptr), mSM(nullptr), _MM(nullptr), _offset(0, 0, 0)
{


}

PlayerManager::PlayerManager(Ogre::SceneManager* SM, String mesh, MazeManager* MM) : mSM (SM), _MM(MM)
{

	CreatePlayer(_MM->GetPlayerInitialPos(), PLAYER_MESH_NAME);
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

		Vector3 margen = Vector3(_player->getPosition().x + (dir.x + CUBE_SIZE.x) / 2, _player->getPosition().y,
			_player->getPosition().z + (CUBE_SIZE.z) / 2);

		return(_MM->IsTrasferable(nextPos));
	}
	else {
		return (_MM->IsTrasferable(_player->getPosition()));
	}
	/*double margenX = (dir.x * CUBE_SIZE) / -2;
	double margenZ = (dir.z * CUBE_SIZE) / -2;
	uint _x = (mHero->getX() + margenX) / CUBE_SIZE;
	uint _y = (mHero->getZ() + margenZ) / CUBE_SIZE;
	if (mHero->getNewDir().x != 0) {
		uint aux = _x + mHero->getNewDir().x;
		return mzM->canWalk(_y, aux);
	}
	else if (mHero->getNewDir().z != 0) {
		uint aux = _y + mHero->getNewDir().z;
		return mzM->canWalk(aux, _x);
	}
	else
		return false;*/
	
}

Ogre::Vector3 PlayerManager::CalculateOffset()
{
	return ((_MM->GetTileSize() - _player->calculateBoxSize()) / 2) + (_player->calculateBoxSize() / 2);
}

bool PlayerManager::keyPressed(const OgreBites::KeyboardEvent& evt) {

	switch (evt.keysym.sym)
	{
	case SDLK_DOWN:

		_nextDir = Ogre::Vector3::UNIT_Z;		
		break;

	case SDLK_UP:

		_nextDir = Ogre::Vector3::NEGATIVE_UNIT_Z;
		break;

	case SDLK_LEFT:

		_nextDir = Ogre::Vector3::NEGATIVE_UNIT_X;
		break;

	case SDLK_RIGHT:

		_nextDir = Ogre::Vector3::UNIT_X;
		break;

	}

	return true;

}

void PlayerManager::frameRendered(const Ogre::FrameEvent& evt) {

	if (CanGo(_nextDir /* _offset.x)*/)) {

		if (_nextDir != Ogre::Vector3::ZERO) {
			_currentDir = _nextDir;
		}	
		_nextDir = { 0, 0, 0 };
	}

	if (!CanGo(_currentDir /* _offset.x)*/)) {
		_currentDir = { 0, 0, 0 };
	}

	//Ogre::Vector3 newPos = _player->getPosition() + (_currentDir * _player->getSpeed());
	//_player->setPosition(newPos);
	_player->move(_currentDir * _player->getSpeed());
}



/*
void HeroManager::frameRendered(const Ogre::FrameEvent& ev)
{//Aquí comprueba si hay que hacer algún cambio de dirección
	if (mHero->getDirAct() != mHero->getNewDir()) {
		if (checkDir()) {
			mHero->setDirAct(mHero->getNewDir());
			Quaternion q = mHero->getOrientation().getRotationTo(mHero->getNewDir());
			//rotate(q);
			heroNode->rotate(q);
		}
	}
	uint frenador = 1;
	/*if (checkWallCollision(dirAct)) {
		frenador = 0;
	}
float speed = mHero->getSpeed();
Vector3 dir = mHero->getDirAct();
mHero->move(dir* speed* frenador);
mHero->setPosX(dir.x* speed* frenador);
mHero->setPosZ(dir.z* speed* frenador);

/*move(mher * speed * frenador);
PosX += dirAct.x * speed * frenador;
PosZ += dirAct.z * speed * frenador;
}


bool HeroManager::checkDir()
{

	double margenX = (mHero->getDirAct().x * CUBE_SIZE) / -2;
	double margenZ = (mHero->getDirAct().z * CUBE_SIZE) / -2;
	uint _x = (mHero->getX() + margenX) / CUBE_SIZE;
	uint _y = (mHero->getZ() + margenZ) / CUBE_SIZE;
	if (mHero->getNewDir().x != 0) {
		uint aux = _x + mHero->getNewDir().x;
		return mzM->canWalk(_y, aux);
	}
	else if (mHero->getNewDir().z != 0) {
		uint aux = _y + mHero->getNewDir().z;
		return mzM->canWalk(aux, _x);
	}
	else
		return false;
}

bool HeroManager::checkWallCollisions(Vector3 dir)
{
	//Aquí comprueba si se va a chocar con un muro
	double margenX = (dir.x * CUBE_SIZE) / -2;
	double margenZ = (dir.z * CUBE_SIZE) / -2;
	uint _x = (mHero->getX() + margenX) / CUBE_SIZE;
	uint _y = (mHero->getZ() + margenZ) / CUBE_SIZE;
	uint aux = _x + dir.x;
	uint aux2 = _y + dir.z;

	return mzM->canWalk(_x, _y);
}*/