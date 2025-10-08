#pragma once
#include "Character.h"
class Player : public Character
{

public:

	Player();
	Player(Vector3 initPos, SceneNode* node, SceneManager* sceneMng);
	Player(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh);

	float getSpeed();

private:

	void ConfigPlayer();

};

