#include "Wing.h"
#include "DataSizes.h"

Wing::Wing(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, int index) : IG2Object(initPos, node, sceneMng)
{

	//Engine
	_engineNode = node->createChildSceneNode();
	_engine = new IG2Object(initPos, _engineNode, sceneMng, "Barrel.mesh");

	_engine->setMaterialName("engineJun");

	//Wing
	_wingNode = node->createChildSceneNode();
	_wing = new IG2Object(initPos, _wingNode, sceneMng, "cube.mesh");

	_wing->setMaterialName("wingJun");

	//Rockets

	node->setInheritScale(false);

	_rockets = new Rockets(initPos, node, sceneMng, index);

	Config();
}

void Wing::Config()
{
	
	_engine->move({ 0, -30, 0 });
	_engineNode->pitch(Ogre::Degree(90));
	_engine->setScale(DataSizes::ENGINE_BASE_SIZE / _engine->calculateBoxSize());


	_wing->setScale(DataSizes::AIRPLANE_WING_SIZE / _wing->calculateBoxSize());
}
