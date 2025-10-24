#ifndef CHARACTERMANAGER_H
#define CHARACTERMANAGER_H

#include <OgreInput.h>

#include "Character.h"
#include "MazeManager.h"

class CharacterManager
{

public:

	~CharacterManager();

	/**
	 * @brief Metodo llamado en cada frame de la ejecucion.
	 * @param dt DeltaTime
	 */
	virtual void Update(float dt) = 0;

	/**
	 * @brief Devuelve las entidades creadas en el manager especifico
	 * @return Lista con las entidades que gestiona el manager
	 */
	inline std::list<Character*> & const getCharacters() {
		return _characters;
	}

protected:

	CharacterManager();

	CharacterManager(Ogre::SceneManager* SM, MazeManager* MM);

	/**
	 * @brief Metodo de creacion de las entidades que gestiona el manager.
	 * Debe implementarlo cada manager
	 */
	virtual void CreateCharacters() = 0;

	//Lista con las entidades que gestiona el manager
	std::list<Character*> _characters;
	Ogre::SceneManager* mSM;
	//Referencia al MazeManager para consultas sobre el layout del mapa
	MazeManager* _MM;
};

#endif // !CHARACTERMANAGER_H





