#ifndef COLISIONMANAGER_H
#define COLISIONMANAGER_H

class PlayerManager;
class EnemyManager;

class ColisionManager
{

public:

	ColisionManager();
	ColisionManager(PlayerManager* PM, EnemyManager* EM);

	void Update();

private:

	PlayerManager* _PM;
	EnemyManager* _EM;

};


#endif // !COLISIONMANAGER_H





