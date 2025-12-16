#include "Engine.h"
#include "DataSizes.h"

Engine::Engine(Vector3 initPos, SceneNode* node, SceneManager* sceneMng) : IG2Object(initPos, node, sceneMng), 
rockets(DataSizes::AIRPLANE_NUM_ROCKETS, nullptr)
{
	barrelNode = node->createChildSceneNode();
	barrelObject = new IG2Object(initPos, barrelNode, mSM, "Barrel.mesh");
	barrelObject->setScale(DataSizes::ENGINE_BASE_SIZE / barrelObject->calculateBoxSize());

	createRockets();
}

Engine::~Engine()
{
}

void Engine::createRockets()
{
    int n = DataSizes::AIRPLANE_NUM_ROCKETS;
    float degrees = 360.0f / n;
    float radius = barrelObject->calculateBoxSize().y * 0.8f;

    fatherRocket = mNode->createChildSceneNode();

    for (int i = 0; i < n; ++i)
    {
        SceneNode* node = fatherRocket->createChildSceneNode();
        rockets[i] = new IG2Object(Vector3(0, -radius, 0), node, mSM, "uv_sphere.mesh");

        rockets[i]->setScale(DataSizes::ROCKET_SIZE / rockets[i]->calculateBoxSize());
        rockets[i]->pitch(Degree(degrees * i));
        rockets[i]->move(Vector3(0, radius, 0));
    }

}
