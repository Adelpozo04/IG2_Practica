#include "Pata.h"
#include "DataSizes.h"
#include "Motor.h"

Pata::Pata(Vector3 initPos, SceneNode* node, SceneManager* sceneMng) : IG2Object(initPos, node, sceneMng)
{

	_esfera = node->createChildSceneNode();
	_esferaObject = new IG2Object({0,-12,0}, _esfera, sceneMng, "uv_sphere.mesh");
	_esferaObject->setMaterialName("rocket_sphere");
	
	_columna = node->createChildSceneNode();
	_columnaObject = new IG2Object({ 0,0,0 }, _columna, sceneMng, "cube.mesh");
	_columnaObject->setMaterialName("rocket_cube");

	Config();
	
}

Pata::~Pata() {
	delete _esferaObject;
	_esferaObject = nullptr;

	delete _columnaObject;
	_columnaObject = nullptr;
}

void Pata::Config()
{
	_esfera->setScale((DataSizes::ROCKET_SPHERE_SIZE / _esferaObject->calculateBoxSize()));
	_columna->setScale((DataSizes::ROCKET_CUBE_SIZE / _columnaObject->calculateBoxSize()));
}

void Pata::Update(float dt)
{


}
