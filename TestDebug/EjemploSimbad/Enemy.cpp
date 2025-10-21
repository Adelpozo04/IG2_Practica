#include "Enemy.h"

Enemy::Enemy() : Character()
{



}

Enemy::Enemy(Vector3 initPos, SceneNode* node, SceneManager* sceneMng) : 
	Character(initPos, node, sceneMng)
{



}

Enemy::Enemy(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh) : 
	Character(initPos, node, sceneMng, mesh)
{

}

Ogre::Vector3 Enemy::ChooseNextDir(MazeManager* MM) {
	std::vector<Ogre::Vector3> posibleDir;

	if (getDir() * -1 != Ogre::Vector3::UNIT_X && CanGo(Ogre::Vector3::UNIT_X, MM)) {
		posibleDir.push_back(Ogre::Vector3::UNIT_X);
	}
	
	if (getDir() * -1 != Ogre::Vector3::UNIT_Z && CanGo(Ogre::Vector3::UNIT_Z, MM)) {
		posibleDir.push_back(Ogre::Vector3::UNIT_Z);
	}
	
	if (getDir() * -1 != Ogre::Vector3::NEGATIVE_UNIT_X && CanGo(Ogre::Vector3::NEGATIVE_UNIT_X, MM)) {
		posibleDir.push_back(Ogre::Vector3::NEGATIVE_UNIT_X);
	}
	
	if (getDir() * -1 != Ogre::Vector3::NEGATIVE_UNIT_Z && CanGo(Ogre::Vector3::NEGATIVE_UNIT_Z, MM)) {
		posibleDir.push_back(Ogre::Vector3::NEGATIVE_UNIT_Z);
	}

	srand(time(NULL));

	int randomIndex = rand() % posibleDir.size();

	return posibleDir[randomIndex];
}
