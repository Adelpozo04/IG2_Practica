#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include <OgreInput.h>
#include <SDL_keycode.h>
#include "Player.h"
#include "MazeManager.h"

class PlayerManager : public OgreBites::InputListener
{

public:

	PlayerManager();
	PlayerManager(Ogre::SceneManager* SM, String mesh, MazeManager* MM);

private:

	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);

	virtual void frameRendered(const Ogre::FrameEvent& evt);

	void CreatePlayer(Ogre::Vector3 initPos, String mesh);

	bool CanGo(Ogre::Vector3 dir);

	Ogre::Vector3 CalculateOffset();

	Player* _player;
	Ogre::SceneManager* mSM;
	MazeManager* _MM;

	Ogre::Vector3 _currentDir;
	Ogre::Vector3 _nextDir;

	Ogre::Vector3 _offset;
};

#endif // !PLAYERMANAGER_H



