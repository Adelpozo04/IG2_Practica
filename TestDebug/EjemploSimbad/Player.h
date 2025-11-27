#pragma once
#include "Character.h"
class Player : public Character
{

public:

	Player();
	Player(Vector3 initPos, SceneNode* node, SceneManager* sceneMng);

	void move(MazeManager* MM, float dt) override;

	void inlineAnimation(float dt) override;

private:

	void Config() override;	

	Ogre::AnimationState* _animationStateRunTop = nullptr;
	Ogre::AnimationState* _animationStateRunBase = nullptr;
};

