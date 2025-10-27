#pragma once
#include <Ogre.h>
#include <OgreSceneManager.h>
class PlayerManager;
class LightManager
{
public:
	LightManager(PlayerManager* pM,Ogre::SceneManager* SM, std::string light);
	//~LightManager();
private:
	Ogre::SceneManager* mSM;
	Ogre::SceneNode* mLightNode;
};

