#ifndef CHARACTER_H
#define CHARACTER_H

#include "IG2Object.h"
#include "MazeManager.h"

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

	virtual void move(MazeManager* MM) = 0;

	virtual void inlineAnimation() = 0;

protected:

	Character();
	Character(Vector3 initPos, SceneNode* node, SceneManager* sceneMng);
	Character(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh);

	Character(const Character&) = delete;

	Character& operator=(const Character&) = delete;

	virtual ~Character() = default;

	bool CanGo(Ogre::Vector3 dir, MazeManager* MM);

	bool canTurn(Ogre::Vector3 dir, MazeManager* MM);

	virtual void Config() = 0;

	int _lifes;
	float _speed;

	Ogre::Vector3 _currentDir;
	Ogre::Vector3 _nextDir;

	Ogre::Vector3 _offset;
};

#endif // !CHARACTER_H

