#ifndef MAZE_MANAGER
#define MAZE_MANAGER

#include <OgreApplicationContext.h>
#include <OgreSceneManager.h>

#include <string>

#include "Ogre.h"
#include "Tile.h"

/**
 * @brief Clase encargada de la gestion del laberinto, tanto para editarlo como para obtener informacion de el.
 */
class MazeManager
{

public:

	struct MazeData {

		std::vector<std::vector<Tile*>> maze;
		Ogre::Vector3 initialPos;
		
		MazeData() {
			maze = std::vector<std::vector<Tile*>>(0, std::vector<Tile*>(0));
			initialPos = Ogre::Vector3::ZERO;
		}

		MazeData(std::vector<std::vector<Tile*>> m, Ogre::Vector3 pos) : maze(m), initialPos(pos) {

		}
	};

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

	/**
	 * @brief Metodo que nos indica si la casilla correspondiente a una posicion es traspasable o no
	 * @param position Posicion de la casilla a comprobar
	 * @return Si es traspasable o no
	 */
	bool IsTrasferable(Ogre::Vector3 position);

	Ogre::Vector3 GetPlayerInitialPos();

private:

	/**
	 * @brief Inicializa el laberinto y almacena los Tiles de este
	 */
	void InitMaze();

	/**
	 * @brief Metodo que nos devuelve los index de la casilla a la que le corresponde una posicion determinada
	 * @param position La posicion de la casilla a comprobar
	 * @return El par de index de la casilla, siendo el first la x y el second la z
	 */
	std::pair<int, int> FromPositionToIndex(Ogre::Vector3 position);

	//Cambiar las variables para inicializarlas en constructor por defecto
	int _sizeX = 0;
	int _sizeZ = 0;
	Ogre::Vector3 _sizeMesh;

	//Vector bidimensional con las casillas del laberinto
	MazeData _mazeData;

	//Nombre del mapa a cargar
	std::string _map = "";
	Ogre::SceneManager* mSM = nullptr;

};

#endif // !MAZE_MANAGER



