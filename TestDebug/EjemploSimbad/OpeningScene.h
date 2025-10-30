#ifndef OPENINGSCENE_H
#define OPENINGSCENE_H

#include "Scene.h"

class OpeningScene : public Scene
{

public:

	OpeningScene(Ogre::SceneManager* SM);

	~OpeningScene();

	void Update(float dt) override;

private:

	void GenerateScene() override;

	Ogre::SceneNode* _simbad = nullptr;
	Ogre::SceneNode* _ogreHead = nullptr;

	Ogre::Entity* _rightSword = nullptr;
	Ogre::Entity* _leftSword = nullptr;

};

#endif // !OPENINGSCENE_H


