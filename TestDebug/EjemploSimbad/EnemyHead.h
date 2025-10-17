#ifndef ENEMYHEAD_H
#define ENEMYHEAD_H

#include "Enemy.h"
class EnemyHead : public Enemy
{

public:

	EnemyHead();
	EnemyHead(Vector3 initPos, SceneNode* node, SceneManager* sceneMng);
	EnemyHead(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh);

private:

	void Config() override;

};

#endif // !ENEMYHEAD_H



