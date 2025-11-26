#include "SmokeObject.h"
#include "constantes.h"

SmokeObject::SmokeObject(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, int index): IG2Object(initPos,node,sceneMng)
{
	//_pSysSmokeNode = node->createChildSceneNode();
	_pSysSmoke = mSM->createParticleSystem("psSmokeBomb" + index, "explosionSmoke");
	_pSysSmoke->setEmitting(false);
	mNode->attachObject(_pSysSmoke);
}

SmokeObject::~SmokeObject()
{
}

bool SmokeObject::update(float dt)
{
	_elapsedTime += dt;

	return _elapsedTime <= BOMB_SMOKE_TIME;
}

void SmokeObject::reset(Ogre::Vector3 pos)
{
	_elapsedTime = 0;
	_pSysSmoke->clear();
	_pSysSmoke->setEmitting(true);
	setPosition(pos);
	mNode->setVisible(true);
}

void SmokeObject::stop()
{
	_pSysSmoke->clear();
	_pSysSmoke->setEmitting(false);
	mNode->setVisible(false);
}
