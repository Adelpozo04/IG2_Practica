#ifndef CHARACTER_H
#define CHARACTER_H

#include "IG2Object.h"
class Character : public IG2Object
{

public:

	Character();
	Character(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, int lifes, int speed);
	Character(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh, int lifes, int speed);

protected:

	int _lifes;
	float _speed;

};

#endif // !CHARACTER_H

