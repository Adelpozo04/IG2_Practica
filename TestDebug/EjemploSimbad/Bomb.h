#ifndef BOMB_H
#define BOMB_H

#include "IG2Object.h"

class Bomb : public IG2Object
{

public:

	Bomb(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, int index);

	void InlineAnimation(float dt);

	void Update(float dt);

	void Reset();

private:

	void CompleteMesh(int index, SceneNode* node);
	void CreateParticlesSystems(SceneNode* node);
	void Config(SceneNode* node);
	void CreateAnimations();

	void Explote();

	SceneNode* _wickNode = nullptr;
	SceneNode* _BombNode = nullptr;

	SceneNode* _pSysFlameNode = nullptr;
	Ogre::ParticleSystem* _pSysFlame = nullptr;
	SceneNode* _pSysSmokeNode = nullptr;
	Ogre::ParticleSystem* _pSysSmoke = nullptr;

	Ogre::AnimationState* _animationNodeBomb = nullptr;
	Ogre::AnimationState* _animationNodeFlame = nullptr;

	float _elapsedTime = 0;
	bool _isVisible = false;
};

#endif // !BOMB_H




