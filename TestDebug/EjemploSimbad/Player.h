#pragma once
#include "Character.h"
class Player : public Character
{

public:

	Player();
	Player(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, int lifes, int speed);
	Player(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh, int lifes, int speed);

private:



};

