#include "ColisionManager.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "MazeManager.h"
#include "BombsManager.h"
#include "constantes.h"

ColisionManager::ColisionManager() : _PM(nullptr), _EM(nullptr){

}

ColisionManager::ColisionManager(PlayerManager* PM, EnemyManager* EM, BombsManager* BM, MazeManager* MM) : _PM(PM), _EM(EM), _BM(BM), _MM(MM) {

}

void ColisionManager::Update()
{

	for (auto itP = _PM->getCharacters().begin(); itP != _PM->getCharacters().end(); ++itP) {
		for (auto itE = _EM->getCharacters().begin(); itE != _EM->getCharacters().end(); ++itE) {
			if ((*itE)->getIfAlive() && (*itE)->getAABB().intersects((*itP)->getAABB())) {
				_PM->HitPlayer(ENEMIES_DAMAGE);
			}
		}
	}
	
	for (Ogre::Vector3 v : _BM->getPositionsWithDamage()) {
		Ogre::Vector3 centerBomb = _MM->getTileCenter(v);
		for (auto itE : _EM->getCharacters()) {
			if (isTheSamePos(_MM->getTileCenter(itE->getPosition()), centerBomb))
				_EM->hitEnemy(itE, BOMB_EXPLOSION_DAMAGE);
		}

		for (auto player : _PM->getCharacters()) {
			if (isTheSamePos(_MM->getTileCenter(player->getPosition()), centerBomb))
				_PM->HitPlayer(BOMB_EXPLOSION_DAMAGE);
		}

	}
}

bool ColisionManager::isTheSamePos(Ogre::Vector3 a, Ogre::Vector3 b)
{
	return a.x == b.x && a.y == b.y && a.z == b.z;
}
