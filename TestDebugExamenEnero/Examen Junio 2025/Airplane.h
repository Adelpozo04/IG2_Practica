#pragma once
#include "IG2Object.h"

class Engine;
class Airplane : public IG2Object
{
public:
	Airplane(Vector3 initPos, SceneNode* node, SceneManager* sceneMng);
	virtual ~Airplane();

private:
	SceneNode* bodyNode;
	IG2Object* bodyObject;

	SceneNode* wingLNode;
	IG2Object* wingLObject;

	SceneNode* wingRNode;
	IG2Object* wingRObject;

	SceneNode* rudderNode;
	IG2Object* rudderObject;

	Engine* engineL;
	Engine* engineR;
};

