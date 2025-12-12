#include "Rocket.h"
#include "DataSizes.h"

Rocket::Rocket(Vector3 initPos, SceneNode* node, SceneManager* sceneMng) : IG2Object(initPos, node, sceneMng, "uv_sphere.mesh")
{
	
	SceneNode* nodeMotor = node->createChildSceneNode();

	nodeMotor->setInheritScale(false);

	_motor = new Motor({ 0, 0, 0 }, nodeMotor, sceneMng);

	nodeMotor->translate({0, -70, 0}, Ogre::Node::TS_WORLD);

	this->setMaterialName("body");

	Config();
}

Rocket::~Rocket()
{
}

void Rocket::Update(float dt)
{
	if (_elapsedTime >= DataSizes::TIME_ENGINE_START) {
		Ogre::Vector3 newPosition = this->getPosition() + Ogre::Vector3{ 0, DataSizes::SHIP_SPEED * dt, 0 };

		this->setPosition(newPosition);
		_motor->Update(dt);
	}
	else {
		_elapsedTime += dt;
	}
		
}

void Rocket::Config()
{
	this->setScale(DataSizes::SPACESHIP_BODY_SIZE / this->calculateBoxSize());
}
