#pragma once
#include "IG2Object.h"
#include "Rockets.h"

class Wing : public IG2Object
{

public:

	Wing(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, int index);

private:

	void Config();

	Ogre::SceneNode* _engineNode = nullptr;
	IG2Object* _engine = nullptr;

	Ogre::SceneNode* _wingNode = nullptr;
	IG2Object* _wing = nullptr;

	Rockets* _rockets = nullptr;

};

