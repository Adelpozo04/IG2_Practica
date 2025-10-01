#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include <OgreInput.h>
#include <SDL_keycode.h>
#include "Player.h"

class PlayerManager : public OgreBites::InputListener
{

public:

	PlayerManager();

private:

	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);

	void CreatePlayer();

	Player* _player;
	Ogre::SceneManager* mSM;

	Ogre::Vector3 _initPos;
	String mesh;
};

#endif // !PLAYERMANAGER_H



