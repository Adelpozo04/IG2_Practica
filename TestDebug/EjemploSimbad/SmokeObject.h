#pragma once
#include "IG2Object.h"
class SmokeObject: public IG2Object
{
public:
	SmokeObject(Vector3 initPos, SceneNode* node, SceneManager* sceneMng,int index);
	virtual ~SmokeObject();

	bool update(float dt);

	void reset(Ogre::Vector3 pos);

	void stop();
private:

	float _elapsedTime = 0;
	Ogre::ParticleSystem* _pSysSmoke = nullptr;
};

