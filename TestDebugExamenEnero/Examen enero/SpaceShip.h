#pragma once
#include "IG2Object.h"
#include <Ogre.h>

class Motor;

class SpaceShip: public IG2Object
{
public:
	SpaceShip(Vector3 initPos, SceneNode* node, SceneManager* sceneMng);
	~SpaceShip();

	void activate(bool e = true);
	void update(double dt);


private:
	Ogre::SceneNode* bodyNode = nullptr;
	IG2Object* bodyObject = nullptr;
	Ogre::SceneNode* motorNode = nullptr;
	Motor* motor = nullptr;
	bool enable;
	float timeToEngineStart;
};

