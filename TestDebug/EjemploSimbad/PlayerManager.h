#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include <OgreInput.h>
#include <SDL_keycode.h>
#include "Player.h"

class PlayerManager : public OgreBites::InputListener
{

public:

	PlayerManager();
	PlayerManager(Ogre::SceneManager* SM, Ogre::Vector3 initPos, String mesh);

private:

	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);

	void CreatePlayer(Ogre::Vector3 initPos, String mesh);

	Player* _player;
	Ogre::SceneManager* mSM;
};

#endif // !PLAYERMANAGER_H



