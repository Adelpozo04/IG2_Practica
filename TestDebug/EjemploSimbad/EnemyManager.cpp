#include <cassert>

#include "EnemyManager.h"
#include "EnemyHead.h"
#include "EnemyPenguin.h"
#include "constantes.h"

EnemyManager::EnemyManager() : CharacterManager()
{


}

EnemyManager::EnemyManager(Ogre::SceneManager* SM, MazeManager* MM) : CharacterManager(SM, MM)
{

	CreateCharacters();

}

void EnemyManager::CreateCharacters()
{

	std::vector<Ogre::Vector3> enemiesInitialPos = _MM->GetEnemiesInitialPos();

	assert((enemiesInitialPos.size() != 0));
	assert((enemiesInitialPos.size() <= NUM_ENEMIES));

	int initPosCounter = 0;

	for (int i = 0; i < SIMPLE_ENEMY_AMOUNT && initPosCounter < enemiesInitialPos.size(); ++i) {
		SceneNode* mEnemyNode = mSM->getRootSceneNode()->createChildSceneNode("nSimpleEnemy" + i);
		_characters.push_back(new EnemyHead(enemiesInitialPos[initPosCounter], mEnemyNode, mSM, _MM));
		_characters.back()->setIterator(--_characters.end());
		initPosCounter++;
	}

	for (int i = 0; i < COMPLEX_ENEMY_AMOUNT && initPosCounter < enemiesInitialPos.size(); ++i) {
		SceneNode* mEnemyNode = mSM->getRootSceneNode()->createChildSceneNode("nComplexEnemy" + i);
		_characters.push_back(new EnemyPenguin(enemiesInitialPos[initPosCounter], mEnemyNode, mSM, i, _MM));
		_characters.back()->setIterator(--_characters.end());
		initPosCounter++;
	}

}

void EnemyManager::Update(float dt) {

	for (auto it = _characters.begin(); it != _characters.end(); ++it) {
		(*it)->move(_MM, dt);
		(*it)->inlineAnimation(dt);
	}

}
