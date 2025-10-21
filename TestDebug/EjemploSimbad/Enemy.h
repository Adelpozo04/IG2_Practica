#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character
{

public:

	inline std::list<Character*>::iterator getIterator() const {
		return _it;
	}

	inline void setIterator(std::list<Character*>::iterator it) {
		_it = it;
	}

protected:

	Enemy();
	Enemy(Vector3 initPos, SceneNode* node, SceneManager* sceneMng);
	Enemy(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh);

	Ogre::Vector3 ChooseNextDir(MazeManager* MM);

	std::list<Character*>::iterator _it;

};

#endif // !ENEMY_H
