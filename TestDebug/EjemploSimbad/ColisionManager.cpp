#include "ColisionManager.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "constantes.h"

ColisionManager::ColisionManager() : _PM(nullptr), _EM(nullptr){

}

ColisionManager::ColisionManager(PlayerManager* PM, EnemyManager* EM) : _PM(PM), _EM(EM) {

}

void ColisionManager::Update()
{

	for (auto itP = _PM->getCharacters().begin(); itP != _PM->getCharacters().end(); ++itP) {
		for (auto itE = _EM->getCharacters().begin(); itE != _EM->getCharacters().end(); ++itE) {
			if ((*itE)->getAABB().intersects((*itP)->getAABB())) {
				_PM->HitPlayer(ENEMIES_DAMAGE);
			}
		}
	}
	
}
