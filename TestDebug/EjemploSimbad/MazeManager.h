#ifndef MAZE_MANAGER
#define MAZE_MANAGER

#include <OgreApplicationContext.h>
#include <OgreSceneManager.h>

#include <string>

#include "Ogre.h"
#include "Tile.h"

class MazeManager
{

public:

	/**
	 * @brief 
	 * @param map 
	 * @param SM 
	*/
	MazeManager(std::string map, Ogre::SceneManager* SM);

	/**
	 * @brief Destructor de la clase
	 */
	~MazeManager();

private:

	void InitMaze();

	void centraLab();

	int _sizeX = 0;
	int _sizeZ = 0;

	std::vector<std::vector<Tile*>> _maze = std::vector<std::vector<Tile*>>(0, std::vector<Tile*>(0));

	std::string _map = "";
	Ogre::SceneManager* mSM = nullptr;
};

#endif // !MAZE_MANAGER



