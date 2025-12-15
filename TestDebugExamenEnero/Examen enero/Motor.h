#pragma once
#include "IG2Object.h"
#include <vector>
class Motor: public IG2Object
{
public:
	Motor(Vector3 initPos, SceneNode* node, SceneManager* sceneMng);
	~Motor();

	void activateParticles(bool enable = true);
	void update(double dt);

	void CreateRockets();
private:

	Ogre::SceneNode* motorNode = nullptr;
	IG2Object* motorObject = nullptr;
	Ogre::SceneNode* fatherRocketNode;
	std::vector<Ogre::SceneNode*> rocketNodes;
	std::vector< ParticleSystem*> smokeSystems;
	ParticleSystem* fireSys = nullptr;

};

