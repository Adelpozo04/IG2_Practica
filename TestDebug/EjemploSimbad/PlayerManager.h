#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include <OgreInput.h>
#include <SDL_keycode.h>
#include "Player.h"
#include "MazeManager.h"

class PlayerManager : public OgreBites::InputListener
{

public:

	/**
	 * @brief Constructor por defecto
	 */
	PlayerManager();

	/**
	 * @brief Contructor del player manager
	 * @param SM El manager de la escena
	 * @param mesh El mesh que va a representar al player
	 * @param MM El manager del laberinto para calculos de movimientos respecto al layout
	 */
	PlayerManager(Ogre::SceneManager* SM, String mesh, MazeManager* MM);

private:

	/**
	 * @brief Recoge el input de una tecla pulsada
	 * @param evt La tecla que se ha pulsado
	 * @return devuelve true si se ha podido procesar
	 */
	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);

	/**
	 * @brief Recorrido que se hace por cada frame (Update de Unity)
	 * @param evt recoge el momento del frame a examinar, si es al final de este, al inicio, tras un proceso...
	 */
	virtual void frameRendered(const Ogre::FrameEvent& evt);

	/**
	 * @brief Metodo que crea al jugador y lo almacena
	 * @param initPos Posicion inicial en la que crear al player
	 * @param mesh Mesh que representa al player
	 */
	void CreatePlayer(Ogre::Vector3 initPos, String mesh);

	/**
	 * @brief Metodo que nos indica si 
	 * @param dir 
	 * @return 
	 */
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



