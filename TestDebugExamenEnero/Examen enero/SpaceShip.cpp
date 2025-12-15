#include "SpaceShip.h"
#include "DataSizes.h"
#include "Motor.h"

SpaceShip::SpaceShip(Vector3 initPos, SceneNode* node, SceneManager* sceneMng): 
	IG2Object(initPos,node,sceneMng), enable(false), timeToEngineStart(DataSizes::TIME_ENGINE_START)
{
	bodyNode = node->createChildSceneNode();
	bodyObject = new IG2Object(Vector3(0,0,0), bodyNode, mSM,"uv_sphere.mesh");
	bodyObject->setMaterialName("BodyMaterial");

	bodyObject->setScale(DataSizes::SPACESHIP_BODY_SIZE / bodyObject->calculateBoxSize());

	motorNode = node->createChildSceneNode();
	motor = new Motor(Vector3(0, 20 - bodyObject->calculateBoxSize().y/2, 0), motorNode, mSM);

}

SpaceShip::~SpaceShip()
{
}

void SpaceShip::activate(bool b)
{
	enable = b;
	motor->activateParticles(b);
}

void SpaceShip::update(double dt)
{
	if (!enable)
		return;

	timeToEngineStart -= dt;

	if (timeToEngineStart <= 0) {
		mNode->translate(Vector3(0, DataSizes::SHIP_SPEED * dt, 0));
		motor->update(dt);
	}
}
