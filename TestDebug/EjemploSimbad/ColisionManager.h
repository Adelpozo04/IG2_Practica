#ifndef COLISIONMANAGER_H
#define COLISIONMANAGER_H

class PlayerManager;
class EnemyManager;

class ColisionManager
{

public:

	ColisionManager();
	ColisionManager(PlayerManager* PM, EnemyManager* EM);

	/**
	 * @brief Metodo llamado en cada frame de la ejecucion. Este hara comprobaciones de las intersecciones entre los elementps del juego.
	 */
	void Update();

private:

	PlayerManager* _PM;
	EnemyManager* _EM;

};


#endif // !COLISIONMANAGER_H





