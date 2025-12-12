#pragma once
#include "IG2Object.h"
#include "Motor.h"
class Rocket : public IG2Object
{

public:

	Rocket(Vector3 initPos, SceneNode* node, SceneManager* sceneMng);
	~Rocket();

	void Update(float dt);

private:

	void Config();

	Motor* _motor = nullptr;

	float _elapsedTime = 0;

};

