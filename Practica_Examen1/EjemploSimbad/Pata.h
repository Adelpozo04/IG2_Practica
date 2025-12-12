#pragma once
#include "IG2Object.h"
class Pata : public IG2Object
{

public:

	Pata(Vector3 initPos, SceneNode* node, SceneManager* sceneMng);

	~Pata();

	void Update(float dt);

private:

	void Config();

	IG2Object* _esferaObject = nullptr;
	Ogre::SceneNode* _esfera = nullptr;

	IG2Object* _columnaObject = nullptr;
	Ogre::SceneNode* _columna = nullptr;

};

