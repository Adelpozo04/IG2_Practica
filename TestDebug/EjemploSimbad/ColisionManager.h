#ifndef COLISIONMANAGER_H
#define COLISIONMANAGER_H

#include <Ogre.h>
class PlayerManager;
class EnemyManager;
class BombsManager;
class MazeManager;

class ColisionManager
{

public:

	ColisionManager();
	ColisionManager(PlayerManager* PM, EnemyManager* EM, BombsManager* BM, MazeManager* MM);

	/**
	 * @brief Metodo llamado en cada frame de la ejecucion. Este hara comprobaciones de las intersecciones entre los elementps del juego.
	 */
	void Update();

private:

	/**
	 * @brief Metedo que comprueba si 2 posiciones estan en las mismas coordenadas
	 * @param a Vector a
	 * @param b Vector b
	 * @return true si ambos tienen las mismas coordenados x,y,z
	 */
	bool isTheSamePos(Ogre::Vector3 a, Ogre::Vector3 b);

	PlayerManager* _PM;
	EnemyManager* _EM;
	BombsManager* _BM;
	MazeManager* _MM;
};


#endif // !COLISIONMANAGER_H





