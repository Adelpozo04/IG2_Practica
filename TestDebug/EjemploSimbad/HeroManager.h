#pragma once
#include <OgreInput.h>
#include <SDL_keycode.h>
#include "Hero.h"
#include "MazeManager.h"
#include "HeroManager.h"
class Hero;
class HeroManager : public OgreBites::InputListener
{
public:
	HeroManager(Hero* mHero, Ogre::SceneManager* sM, Ogre::Node* hNode);
	~HeroManager();
	inline void setMazeMan(MazeManager* mM) { mzM = mM; }
private:

	virtual bool keyPressed(const OgreBites::KeyboardEvent& ev);

	virtual void frameRendered(const Ogre::FrameEvent& ev);

	bool checkDir();

	bool checkWallCollisions(Vector3 dir);

	Hero* mHero;
	Ogre::SceneManager* mSM;
	Ogre::Node* heroNode;
	MazeManager* mzM;
};

