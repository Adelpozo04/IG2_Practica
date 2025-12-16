#include "Airplane.h"
#include "Engine.h"
#include "DataSizes.h"

Airplane::Airplane(Vector3 initPos, SceneNode* node, SceneManager* sceneMng): IG2Object(initPos,node,sceneMng)
{

	bodyNode = node->createChildSceneNode();
	bodyObject = new IG2Object(Vector3(0,0,0),bodyNode,mSM, "uv_sphere.mesh");
	bodyObject->setScale(DataSizes::AIRPLANE_BODY_SIZE / bodyObject->calculateBoxSize());

	wingLNode = node->createChildSceneNode();
	wingLObject = new IG2Object(Vector3(-bodyObject->calculateBoxSize().x * 0.8,0, 0),
		wingLNode, mSM, "cube.mesh");
	wingLObject->setScale(DataSizes::AIRPLANE_WING_SIZE / wingLObject->calculateBoxSize());
	wingLObject->pitch(Degree(90));


	wingRNode = node->createChildSceneNode();
	wingRObject = new IG2Object(Vector3(bodyObject->calculateBoxSize().x *0.8, 0, 0),
		wingRNode, mSM, "cube.mesh");
	wingRObject->setScale(DataSizes::AIRPLANE_WING_SIZE / wingRObject->calculateBoxSize());
	wingRObject->pitch(Degree(90));

	rudderNode = node->createChildSceneNode();
	rudderObject = new IG2Object(Vector3(0, - bodyObject->calculateBoxSize().y * 0.35, -bodyObject->calculateBoxSize().z * 0.6), rudderNode, mSM, "cube.mesh");
	rudderObject->setScale(DataSizes::AIRPLANE_RUDDER_SIZE / rudderObject->calculateBoxSize());
	rudderObject->roll(Degree(90));
	rudderObject->yaw(Degree(-45));

	engineL = new Engine(wingRObject->getPosition() - Vector3(0, 0, wingLObject->calculateBoxSize().y), node->createChildSceneNode(), mSM);

	node->pitch(Degree(90));
}

Airplane::~Airplane()
{
}
