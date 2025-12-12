#pragma once
#include "IG2Object.h"
#include "Pata.h"
#include <vector>
class Motor : public IG2Object
{

public:

	Motor(Vector3 initPos, SceneNode* node, SceneManager* sceneMng);
	~Motor();

	void Update(float dt);

private:

	void Config();

	std::vector<Pata*> _patas;

	std::vector<ParticleSystem*> _graySmoke;
	std::vector<ParticleSystem*> _whiteSmoke;
	ParticleSystem* _fireSmoke = nullptr;

};

