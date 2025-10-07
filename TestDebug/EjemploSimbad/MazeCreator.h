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

	MazeCreator(Ogre::SceneManager* SM);

	/**
	 * @brief Funcion para generar un laberinto
	 * @param map Nombre del fichero txt que represente el laberinto
	 * @return Vector bidimensional con referencias a los distintos IGObjects usados para su contruccion.
	 */
	//std::vector<std::vector<Tile*>> GenerateMaze(std::string map);

	/**
	 * @brief Funcion para generar un laberinto
	 * @param file map Nombre del fichero txt que represente el laberinto
	 * @return Vector bidimensional con referencias a los distintos IGObjects usados para su contruccion.
	 */
	std::vector<std::vector<Tile*>> GenerateMaze(std::string file);

	/**
	 * @brief Funcion que lee chars y crea objetos dentro del laberinto
	 * @param c Char que indica el tipo de objeto
	 * @param i indice i del bucle de la creacion
	 * @param j indice j del bucle de la creacion
	 * @param index indice dentro del vector de nodos 
	 * @param tileMap tileMap en donde se crearan los objetos
	 * @param nodes Vector con los ScenNodes del laberinto
	 */
	void readChars(char c, int i, int j,int index, std::vector<std::vector<Tile*>> & tileMap, std::vector<Ogre::SceneNode*>& nodes);

private:

	double centraLab(int a);

	Ogre::SceneManager* mSM;
	Ogre::SceneNode* mazeNode;

};

#endif // !MAZE_CREATOR





