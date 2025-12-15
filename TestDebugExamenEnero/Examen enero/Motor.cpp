#include "Motor.h"
#include "DataSizes.h"
#include <Ogre.h>  

Motor::Motor(Vector3 initPos, SceneNode* node, SceneManager* sceneMng):
	IG2Object(initPos,node,sceneMng)
{
	motorNode = node->createChildSceneNode();
	motorObject = new IG2Object(Vector3(0, 0, 0), motorNode, mSM, "Barrel.mesh");
	motorObject->setMaterialName("BaseMaterial");
	motorObject->setScale(DataSizes::ENGINE_BASE_SIZE / motorObject->calculateBoxSize());

	Ogre::SceneNode* particleNode = node->createChildSceneNode();
	particleNode->setPosition(motorObject->getPosition() - Vector3(0, motorObject->calculateBoxSize().y / 2, 0));
	fireSys = mSM->createParticleSystem("psFire", "FireParticle");
	fireSys->setEmitting(false);
	particleNode->attachObject(fireSys);


	CreateRockets();
}

Motor::~Motor()
{
}

void Motor::activateParticles(bool enable)
{
	fireSys->setEmitting(enable);
	for (ParticleSystem* p : smokeSystems)
		p->setEmitting(enable);
}

void Motor::update(double dt) {
	fatherRocketNode->yaw(-Ogre::Degree(DataSizes::SHIP_ROTATION * dt), Ogre::Node::TS_LOCAL);
}

void Motor::CreateRockets()
{
	int n = DataSizes::NUM_ROCKETS;
	float degrees = (float)360 / n;
	rocketNodes.resize(n);
	smokeSystems.resize(n);
	int radius = (motorObject->calculateBoxSize().z/2) * 0.8;
	fatherRocketNode = mNode->createChildSceneNode();
	//uv_sphere.mesh
	for (int i = 0; i < n;i++) {
		rocketNodes[i] = fatherRocketNode->createChildSceneNode();
		rocketNodes[i]->setPosition(Vector3(motorNode->getPosition() - Vector3(0,motorObject->calculateBoxSize().y/2 * 0.6, 0)));

		IG2Object* RocketCube = new IG2Object(Vector3(0, 0, 0), rocketNodes[i]->createChildSceneNode(), mSM, "cube.mesh");
		RocketCube->setScale(DataSizes::ROCKET_CUBE_SIZE/RocketCube->calculateBoxSize());
		RocketCube->setMaterialName("CubeMaterial");

		IG2Object* RocketBall = new IG2Object(Vector3(0, -RocketCube->calculateBoxSize().y / 2, 0),
			rocketNodes[i]->createChildSceneNode(),mSM,"uv_sphere.mesh");
		RocketBall->setScale(DataSizes::ROCKET_SPHERE_SIZE / RocketBall->calculateBoxSize());
		RocketBall->setMaterialName("SphereMaterial");

		Ogre::SceneNode* particleNode = rocketNodes[i]->createChildSceneNode();
		particleNode->setPosition(RocketBall->getPosition() - Vector3(0,RocketBall->calculateBoxSize().y/2, 0));
		string pSName;
		i % 2 == 0 ? pSName = "SmokeParticleWhite" : pSName = "SmokeParticleGray";
		ParticleSystem* pSys = mSM->createParticleSystem("psSmoke" + std::to_string(i), pSName);
		pSys->setEmitting(false);
		particleNode->attachObject(pSys);
		smokeSystems[i] = pSys;

		rocketNodes[i]->yaw(Ogre::Degree(degrees * i), Ogre::Node::TS_LOCAL);
		rocketNodes[i]->translate(rocketNodes[i]->getPosition() + Vector3(0, 0, radius),Ogre::Node::TS_LOCAL);
		i % 2 == 0 ? rocketNodes[i]->roll(Ogre::Degree(DataSizes::ROCKET_DEGREE),Ogre::Node::TS_LOCAL) :
			rocketNodes[i]->roll(- Ogre::Degree(DataSizes::ROCKET_DEGREE), Ogre::Node::TS_LOCAL);

	}
}
