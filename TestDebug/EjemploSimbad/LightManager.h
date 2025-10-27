#pragma once
#include <Ogre.h>
#include <OgreSceneManager.h>
class PlayerManager;
class LightManager
{
public:

	/**
	 * @brief Constructor de la clase que inicializa la luz segun el formato especificado por fichero
	 * @param pM Manager del player para atacharle la luz
	 * @param SM SceneManager
	 * @param light Tipo de luz que se debe crear en la escena
	 */
	LightManager(PlayerManager* pM,Ogre::SceneManager* SM, std::string light);

private:
	Ogre::SceneManager* mSM;
	Ogre::SceneNode* mLightNode;
};

