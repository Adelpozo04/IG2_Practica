#include "LightManager.h"
#include "PlayerManager.h"

LightManager::LightManager(PlayerManager* pM, Ogre::SceneManager* SM, std::string light): mSM(SM)
{
	Ogre::Light* luz = mSM->createLight("LuzHeroe");
	if (light == "directional") {
		luz->setType(Ogre::Light::LT_DIRECTIONAL);
		luz->setDiffuseColour(0.75, 0.75, 0.75);

		mLightNode = mSM->getRootSceneNode()->createChildSceneNode();
		mLightNode->attachObject(luz);
		mLightNode->setDirection(Ogre::Vector3(-0.25, -0.45, -0.45));
	}else if(light == "spotLight") {
		luz->setType(Ogre::Light::LT_SPOTLIGHT);
		luz->setDiffuseColour(0.75, 0.75, 0.75);

		mLightNode = pM->getPlayerNode()->createChildSceneNode();
		mLightNode->attachObject(luz);
		mLightNode->setDirection(Ogre::Vector3(0, -1, 0));
		mLightNode->setPosition(Ogre::Vector3(0, 30, 0));
	}
	else if (light == "point") {
		luz->setType(Ogre::Light::LT_POINT);
		luz->setDiffuseColour(1, 1, 1);

		mLightNode = pM->getPlayerNode()->createChildSceneNode();
		mLightNode->attachObject(luz);
	}
	else
	{
		luz->setType(Ogre::Light::LT_DIRECTIONAL);
		luz->setDiffuseColour(0.75, 0.75, 0.75);

		mLightNode = mSM->getRootSceneNode()->createChildSceneNode();
		mLightNode->attachObject(luz);
		mLightNode->setDirection(Ogre::Vector3(-0.25, -0.5, -1));
	}
}
