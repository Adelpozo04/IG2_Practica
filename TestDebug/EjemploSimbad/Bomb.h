#ifndef BOMB_H
#define BOMB_H

#include "IG2Object.h"

class Bomb : public IG2Object
{

public:

	Bomb(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, int index);

	void InlineAnimation(float dt);

	bool Update(float dt);

	void reset(Ogre::Vector3 pos);

	void explode();
private:

	void CompleteMesh(SceneNode* node);
	void CreateParticlesSystems(SceneNode* node);
	void Config(SceneNode* node);
	void CreateAnimations();
	void createKf(Ogre::TransformKeyFrame* kf, Ogre::NodeAnimationTrack* track, Ogre::Real durStep,Ogre::Vector3& keyframePos,
		Ogre::Vector3 traslationValue,Ogre::Vector3 rotationValue,float degrees,Ogre::Vector3 scaleValue);


	SceneNode* _wickNode = nullptr;
	SceneNode* _BombNode = nullptr;

	SceneNode* _pSysFlameNode = nullptr;
	Ogre::ParticleSystem* _pSysFlame = nullptr;
	SceneNode* _pSysSmokeNode = nullptr;
	//Ogre::ParticleSystem* _pSysSmoke = nullptr;

	Ogre::AnimationState* _animationNodeBomb = nullptr;
	Ogre::AnimationState* _animationNodeFlame = nullptr;

	float _elapsedTime = 0;
	bool _isVisible = false;
	int _index = 0;
};

#endif // !BOMB_H




