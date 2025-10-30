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

};

#endif // !OPENINGSCENE_H


