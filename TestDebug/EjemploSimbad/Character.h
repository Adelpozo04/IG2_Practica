#ifndef CHARACTER_H
#define CHARACTER_H

#include "IG2Object.h"
class Character : public IG2Object
{
public:

	

protected:

	Character();
	Character(Vector3 initPos, SceneNode* node, SceneManager* sceneMng);
	Character(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh);

	int _lifes;
	float _speed;

};

#endif // !CHARACTER_H

