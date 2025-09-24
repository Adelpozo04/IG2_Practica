#ifndef MAZE_CREATOR
#define MAZE_CREATOR

#include <OgreApplicationContext.h>
#include <OgreSceneManager.h>
#include <string>
#include "Ogre.h"

class MazeCreator
{
public:
	MazeCreator(std::string map, Ogre::SceneManager& SM) {}

private:

	std::string _map;
	Ogre::SceneManager* mSM;

};

#endif // !MAZE_CREATOR





