#pragma once
#include "IG2Object.h"
#include "Wing.h"

class Body : public IG2Object
{

public:

	Body(Vector3 initPos, SceneNode* node, SceneManager* sceneMng);

	void Turbo();

private:

	void Config();

	Ogre::SceneNode* _bodyNode = nullptr;
	IG2Object* _body = nullptr;

	Ogre::SceneNode* _tailNode = nullptr;
	IG2Object* _tail = nullptr;

	Wing* _wingRight;
	Wing* _wingLeft;

	Ogre::SceneNode* _fireParticleNode = nullptr;
	Ogre::ParticleSystem* _fireParticle = nullptr;

};

