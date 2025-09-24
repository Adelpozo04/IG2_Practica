#ifndef MAZE_MANAGER
#define MAZE_MANAGER

#include <OgreApplicationContext.h>
#include <OgreSceneManager.h>

#include <string>

#include "Ogre.h"
#include "IG2Object.h"

class MazeManager
{

public:

	/**
	 * @brief 
	 * @param map 
	 * @param SM 
	*/
	MazeManager(std::string map, Ogre::SceneManager& SM) {}

	/**
	 * @brief Destructor de la clase
	 */
	~MazeManager();

private:

};

#endif // !MAZE_MANAGER



