#include "Rockets.h"
#include "DataSizes.h"
#include "OgreParticleSystem.h"

Rockets::Rockets(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, int index) : IG2Object(initPos, node, sceneMng)
{

	_controlNode = node->createChildSceneNode();

	_controlNode->setPosition(initPos);

	float degree = (float)360 / DataSizes::AIRPLANE_NUM_ROCKETS;

	for (int i = 0; i < DataSizes::AIRPLANE_NUM_ROCKETS; ++i) {

		Ogre::SceneNode* rocketNode = _controlNode->createChildSceneNode();
		IG2Object* rocket = new IG2Object({0, 0, 0}, rocketNode, sceneMng, "uv_sphere.mesh");

		rocket->setMaterialName("rocketJun");

		_rocketsNodes.push_back(rocketNode);
		_rockets.push_back(rocket);

		rocketNode->pitch(Ogre::Degree(degree * i));

		rocketNode->translate({ 0, 0, 25 }, Ogre::Node::TS_LOCAL);

		if (i % 2 == 0) {
			_particleNodeAux = _controlNode->createChildSceneNode();
			_particleAux = sceneMng->createParticleSystem("whiteP" + to_string(i) + "system" + to_string(index), "whiteSmokeJun");
			_particleAux->setEmitting(true);

			_particleNodeAux->attachObject(_particleAux);
			_particleNodeAux->setPosition(rocketNode->getPosition());

			_whiteParticles.push_back(_particleAux);
			_whiteParticlesNodes.push_back(_particleNodeAux);
		}
		else {

			_particleNodeAux = _controlNode->createChildSceneNode();
			_particleAux = sceneMng->createParticleSystem("grayP" + to_string(i) + "system" + to_string(index), "graySmokeJun");
			_particleAux->setEmitting(true);

			_particleNodeAux->attachObject(_particleAux);
			_particleNodeAux->setPosition(rocketNode->getPosition());

			_grayParticles.push_back(_particleAux);
			_grayParticlesNodes.push_back(_particleNodeAux);

		}
	}

	Config();

}

void Rockets::Config()
{

	_controlNode->yaw(Ogre::Degree(90), Ogre::Node::TS_WORLD);
	_controlNode->translate({ 0, -30, -60 }, Ogre::Node::TS_WORLD);

	for (auto r : _rockets) {
		r->setScale(DataSizes::ROCKET_SIZE / r->calculateBoxSize());
	}

	_particleAux = nullptr;
	_particleNodeAux = nullptr;
	
}
