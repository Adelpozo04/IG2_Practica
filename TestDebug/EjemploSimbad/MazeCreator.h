#ifndef MAZE_CREATOR
#define MAZE_CREATOR

#include <OgreApplicationContext.h>
#include <OgreSceneManager.h>
#include <string>
#include "Ogre.h"
#include "Tile.h"
#include "MazeManager.h"

class MazeCreator
{
public:

	MazeCreator(Ogre::SceneManager* SM) : mSM(SM) {}

	/**
	 * @brief Funcion para generar un laberinto
	 * @param map Nombre del fichero txt que represente el laberinto
	 * @return Vector bidimensional con referencias a los distintos IGObjects usados para su contruccion.
	 */
	MazeManager::MazeData GenerateMaze(std::string map);

private:

	void ReadMaze(int sizeX, int sizeZ, Ogre::Vector3& cubeSize, ifstream& mapFile, std::vector<Ogre::SceneNode*>& nodes,
		std::vector<std::vector<Tile*>>& maze, Ogre::SceneNode* mazeNode, Ogre::Vector3& initPos);

	Ogre::SceneManager* mSM;

};

#endif // !MAZE_CREATOR





