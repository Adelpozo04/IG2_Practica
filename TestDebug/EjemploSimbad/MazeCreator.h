#ifndef MAZE_CREATOR
#define MAZE_CREATOR

#include <OgreApplicationContext.h>
#include <OgreSceneManager.h>
#include <string>
#include "Ogre.h"
#include "Tile.h"

class MazeCreator
{
public:

	MazeCreator(Ogre::SceneManager* SM) : mSM(SM) {}

	/**
	 * @brief Funcion para generar un laberinto
	 * @param map Nombre del fichero txt que represente el laberinto
	 * @return Vector bidimensional con referencias a los distintos IGObjects usados para su contruccion.
	 */
	std::vector<std::vector<Tile*>> GenerateMaze(std::string map);

private:

	Ogre::SceneManager* mSM;

};

#endif // !MAZE_CREATOR





