#ifndef CHARACTER_H
#define CHARACTER_H

#include "IG2Object.h"
class Character : public IG2Object
{
public:

	inline float getSpeed() const {
		return _speed;
	}

	inline int getLifes() const {
		return _lifes;
	}

	inline Ogre::Vector3 getDir() const {
		return _currentDir;
	}

	inline void setDir(Ogre::Vector3 dir) {
		_currentDir = dir;
	}

	inline Ogre::Vector3 getNextDir() const {
		return _nextDir;
	}

	inline void setNextDir(Ogre::Vector3 ndir) {
		_nextDir = ndir;
	}

	inline Ogre::Vector3 getOffset() const {
		return _offset;
	}

	inline void setOffset(Ogre::Vector3 offset) {
		_offset = offset;
	}

	inline std::list<Character*>::iterator getIterator() const {
		return _it;
	}

	inline void setIterator(std::list<Character*>::iterator it) {
		_it = it;
	}

protected:

	Character();
	Character(Vector3 initPos, SceneNode* node, SceneManager* sceneMng);
	Character(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh);

	virtual ~Character() = default;

	virtual void Config() = 0;

	int _lifes;
	float _speed;

	std::list<Character*>::iterator _it;

	Ogre::Vector3 _currentDir;
	Ogre::Vector3 _nextDir;

	Ogre::Vector3 _offset;
};

#endif // !CHARACTER_H

