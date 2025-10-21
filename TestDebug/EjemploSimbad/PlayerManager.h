#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include <OgreInput.h>
#include <SDL_keycode.h>
#include "Player.h"
#include "CharacterManager.h"

class PlayerManager : public CharacterManager, public OgreBites::InputListener
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
	PlayerManager(Ogre::SceneManager* SM, MazeManager* MM);

	/**
	 * @brief Recorrido que se hace por cada frame (Update de Unity)
	 * @param evt recoge el momento del frame a examinar, si es al final de este, al inicio, tras un proceso...
	 */
	void Update(float dt) override;

	void HitPlayer(int damage);

private:

	/**
	 * @brief Recoge el input de una tecla pulsada
	 * @param evt La tecla que se ha pulsado
	 * @return devuelve true si se ha podido procesar
	 */
	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);

	/**
	 * @brief Metodo que crea al jugador y lo almacena
	 * @param initPos Posicion inicial en la que crear al player
	 * @param mesh Mesh que representa al player
	 */
	void CreateCharacters() override;

};

#endif // !PLAYERMANAGER_H



