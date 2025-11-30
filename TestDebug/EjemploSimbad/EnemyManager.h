#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include "CharacterManager.h"
class EnemyManager : public CharacterManager
{

public:

	/**
	 * @brief Constructor por defecto
	 */
	EnemyManager();

	/**
	 * @brief Contructor del player manager
	 * @param SM El manager de la escena
	 * @param mesh El mesh que va a representar al player
	 * @param MM El manager del laberinto para calculos de movimientos respecto al layout
	 */
	EnemyManager(Ogre::SceneManager* SM, MazeManager* MM);

	/**
	 * @brief Recorrido que se hace por cada frame (Update de Unity)
	 * @param evt recoge el momento del frame a examinar, si es al final de este, al inicio, tras un proceso...
	 */
	void Update(float dt) override;

	void hitEnemy(Character* enemy, int damage);

private:

	/**
	 * @brief Metodo que crea al jugador y lo almacena
	 * @param initPos Posicion inicial en la que crear al player
	 * @param mesh Mesh que representa al player
	 */
	void CreateCharacters() override;

};

#endif // !ENEMYMANAGER_H



