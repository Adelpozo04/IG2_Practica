#ifndef OPENINGSCENE_H
#define OPENINGSCENE_H

#include "Scene.h"

class OpeningScene : public Scene
{

public:

	OpeningScene(Ogre::SceneManager* SM, OgreBites::ApplicationContext* AC);

	~OpeningScene();

	void Update(float dt) override;

private:

	void GenerateScene() override;

	void CreateFloor();
	void CreateCamara();
	void CreateLight();
	void CreateCharacters();
	void CreateAnimations();

	void CreateKeyframe(Ogre::TransformKeyFrame* kf, Ogre::NodeAnimationTrack* track, int index, Ogre::Real durStep, 
		Ogre::Vector3 traslationValue = { 0, 0, 0 }, Ogre::Vector3 rotationValue = { 0, 0, 0 }, float degrees = 0, 
		Ogre::Vector3 scaleValue = { 1, 1, 1 });

	Ogre::SceneNode* _simbad = nullptr;
	Ogre::SceneNode* _ogreHead = nullptr;

	Ogre::SceneNode* _light = nullptr;
	Ogre::SceneNode* mCamNode = nullptr;

	Ogre::Entity* _simbadEnt = nullptr;
	Ogre::Entity* _rightSword = nullptr;
	Ogre::Entity* _leftSword = nullptr;

	Ogre::AnimationState* _animationStateDance = nullptr;
	Ogre::AnimationState* _animationStateRunTop = nullptr;
	Ogre::AnimationState* _animationStateRunBase = nullptr;

	bool _isDancing = false;
	bool _isRunning = false;

};

#endif // !OPENINGSCENE_H


