#pragma once
#include <OgreSceneManager.h>
#include "IG2Object.h"
#include <vector>
#include <string>
using namespace Ogre;
class LabMan
{
public:
	LabMan(SceneNode* labNode, SceneManager* sM, std::string file);
	~LabMan();
private:
	void loadLabFromFile(std::string file);
	Ogre::SceneNode* mLabNode = nullptr;
	Ogre::SceneManager* mSM = nullptr;
	void readChars(char c, int i, int j);
	double centraLab(int a);

	bool** labArray;
	int nFil;

	std::vector<IG2Object*> objects;
};

