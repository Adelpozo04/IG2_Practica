#pragma once
#include "IG2Object.h"
class Rockets : public IG2Object
{

public:

	Rockets(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, int index);

private:

	void Config();

	Ogre::SceneNode* _controlNode = nullptr;

	std::vector<Ogre::SceneNode*> _rocketsNodes;
	std::vector<IG2Object*> _rockets;

	std::vector<Ogre::SceneNode*> _grayParticlesNodes;
	std::vector<Ogre::ParticleSystem*> _grayParticles;

	std::vector<Ogre::SceneNode*> _whiteParticlesNodes;
	std::vector<Ogre::ParticleSystem*> _whiteParticles;

	Ogre::SceneNode* _particleNodeAux = nullptr;
	Ogre::ParticleSystem* _particleAux = nullptr;
};

