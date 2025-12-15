#include "Body.h"
#include "DataSizes.h"
#include "OgreParticleSystem.h"

Body::Body(Vector3 initPos, SceneNode* node, SceneManager* sceneMng) : IG2Object(initPos, node, sceneMng)
{
	//Body
	_bodyNode = node->createChildSceneNode();
	_bodyNode->setInheritScale(false);
	_body = new IG2Object({ 0, 0, 0 }, _bodyNode, sceneMng, "uv_sphere.mesh");

	_body->setMaterialName("bodyJun");

	//Tail
	_tailNode = node->createChildSceneNode();
	_tail = new IG2Object({ 0, 0, 0 }, _tailNode, sceneMng, "cube.mesh");

	_tail->setMaterialName("wingJun");

	//Wings
	_wingRight = new Wing({ -150, 0, 0 }, node, sceneMng, 1);
	_wingLeft = new Wing({ 150, 0, 0 }, node, sceneMng, 2);

	_fireParticleNode = node->createChildSceneNode();
	_fireParticle = sceneMng->createParticleSystem("fireP", "fireSmokeJun");
	_fireParticle->setEmitting(false);

	_fireParticleNode->attachObject(_fireParticle);

	Config();
}

void Body::Turbo()
{

	_fireParticle->setEmitting(true);

}

void Body::Config()
{
	_body->pitch(Ogre::Degree(90));
	_body->setScale(DataSizes::AIRPLANE_BODY_SIZE / _body->calculateBoxSize());

	_tailNode->roll(Ogre::Degree(90));
	_tailNode->pitch(Ogre::Degree(-30), Ogre::Node::TS_WORLD);
	_tailNode->translate({ 0, 50, -180 });
	_tail->setScale(DataSizes::AIRPLANE_RUDDER_SIZE / _tail->calculateBoxSize());
}
