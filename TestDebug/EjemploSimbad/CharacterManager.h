#ifndef CHARACTERMANAGER_H
#define CHARACTERMANAGER_H

#include <OgreInput.h>

#include "Character.h"
#include "MazeManager.h"

class CharacterManager : public OgreBites::InputListener
{

public:



protected:

	CharacterManager();

	CharacterManager(Ogre::SceneManager* SM, MazeManager* MM);

	virtual void CreateCharacters(String mesh) = 0;

	Ogre::Vector3 CalculateOffset(Character* ch);

	std::list<Character*> _characters;
	Ogre::SceneManager* mSM;
	MazeManager* _MM;
};

#endif // !CHARACTERMANAGER_H





