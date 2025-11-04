#ifndef SCENE_H
#define SCENE_H

#include "Ogre.h"
#include <OgreApplicationContext.h>

class Scene
{

public:

	Scene(Ogre::SceneManager* mSM, OgreBites::ApplicationContext* AC);

	virtual void Update(float dt) = 0;

protected:

	virtual void GenerateScene() = 0;

	Ogre::SceneManager* mSM = nullptr;
	OgreBites::ApplicationContext* mAplicCont = nullptr;
};

#endif // !SCENE_H



