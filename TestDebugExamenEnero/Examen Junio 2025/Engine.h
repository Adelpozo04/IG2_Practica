#pragma once
#include "IG2Object.h"
#include <vector>
class Engine : public IG2Object
{
public:
	Engine(Vector3 initPos, SceneNode* node, SceneManager* sceneMng);
	virtual ~Engine();
	void createRockets();
private:
	SceneNode* barrelNode;
	IG2Object* barrelObject;

	SceneNode* fatherRocket;
	std::vector<IG2Object*> rockets;
};

