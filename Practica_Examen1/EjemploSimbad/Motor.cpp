#include "Motor.h"
#include "DataSizes.h"
#include "OgreParticleSystem.h"

Motor::Motor(Vector3 initPos, SceneNode* node, SceneManager* sceneMng) : IG2Object(initPos, node, sceneMng, "Barrel.mesh")
{

	float degree = (float)360 / DataSizes::NUM_ROCKETS;
	

	for (int i = 0; i < DataSizes::NUM_ROCKETS; ++i) {

		Ogre::SceneNode* pataNode = node->createChildSceneNode();

		pataNode->setInheritScale(false);

		_patas.push_back(new Pata{ {0,0,0}, pataNode, sceneMng });

		pataNode->yaw(i * Ogre::Degree(degree), Ogre::Node::TS_WORLD);

		pataNode->translate(0, -4, 2, Ogre::Node::TS_LOCAL);

		if (i % 2 == 0) {
			ParticleSystem* smokeGrayAux = sceneMng->createParticleSystem("psGraySmoke" + std::to_string(i), "graySmoke");
			smokeGrayAux->setEmitting(true);

			_graySmoke.push_back(smokeGrayAux);

			Ogre::SceneNode* particleNode = pataNode->createChildSceneNode();
			particleNode->attachObject(smokeGrayAux);

			pataNode->pitch(Ogre::Degree(DataSizes::ROCKET_DEGREE));
		}
		else {
			ParticleSystem* smokeWhiteAux = mSM->createParticleSystem("psWhiteSmoke" + std::to_string(i), "whiteSmoke");

			smokeWhiteAux->setEmitting(true);

			_graySmoke.push_back(smokeWhiteAux);

			Ogre::SceneNode* particleNode = pataNode->createChildSceneNode();
			particleNode->attachObject(smokeWhiteAux);

			pataNode->pitch(Ogre::Degree(-DataSizes::ROCKET_DEGREE));
		}
	}

	_fireSmoke = sceneMng->createParticleSystem("psFireSmoke", "fireRocketSmoke");
	_fireSmoke->setEmitting(false);
	Ogre::SceneNode* particleNode = this->createChildSceneNode();
	particleNode->attachObject(_fireSmoke);


	this->setMaterialName("engine");

	Config();

}

void Motor::Config()
{
	this->setScale(DataSizes::ENGINE_BASE_SIZE / this->calculateBoxSize());
}

Motor::~Motor()
{

	for (auto a : _patas) {
		delete a;
		a = nullptr;
	}

}

void Motor::Update(float dt)
{
	_fireSmoke->setEmitting(true);
	
	this->yaw(Ogre::Degree(DataSizes::SHIP_ROTATION * dt));
}
