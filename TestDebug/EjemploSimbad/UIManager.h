#pragma once
#include <Ogre.h>
#include <OgreTrays.h>
#include <OgreInput.h>

class UIManager
{
public:
	UIManager(OgreBites::TrayManager* TrayMgr, Ogre::RenderWindow* window);
	~UIManager();
	void updateTextBox(int nLifes, int points)const;

private:
	OgreBites::TextBox* mTextBox = nullptr;
	OgreBites::TrayManager* mTrayMgr = nullptr;
};

