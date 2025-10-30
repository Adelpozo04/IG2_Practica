#ifndef SCENE_H
#define SCENE_H

#include "Ogre.h"

class Scene
{

public:

	Scene(Ogre::SceneManager* mSM);

	virtual void Update(float dt) = 0;

protected:

	virtual void GenerateScene() = 0;

	Ogre::SceneManager* mSM = nullptr;
};

#endif // !SCENE_H



