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
	MazeManager::MazeData* GenerateMaze(std::string map);


private:
	void readChars(char c, int i, int j, int index, std::vector<std::vector<Tile*>>& maze, std::vector<Ogre::SceneNode*>& nodes, 
		Ogre::Vector3& initPos, std::vector<Ogre::Vector3>& enemiesInitPos);

	void ReadMaze(int sizeX, int sizeZ, ifstream& mapFile, std::vector<Ogre::SceneNode*>& nodes,
		std::vector<std::vector<Tile*>>& maze, Ogre::SceneNode* mazeNode, Ogre::Vector3& initPos, std::vector<Ogre::Vector3>& enemiesInitPos);

	void ConfigMaze(Ogre::SceneNode* mazeNode);

	Ogre::SceneManager* mSM;


	Ogre::SceneNode* mazeNode;

	string matMuro;

};

#endif // !MAZE_CREATOR