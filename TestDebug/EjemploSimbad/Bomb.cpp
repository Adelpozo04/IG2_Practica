#include "Bomb.h"
#include "constantes.h"

Bomb::Bomb(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh, int index) : IG2Object(initPos, node, sceneMng, mesh)
{
	CompleteMesh(index, node);
	CreateParticlesSystems(node);
	Config(node);
	CreateAnimations();
}

void Bomb::InlineAnimation(float dt)
{
}

void Bomb::CompleteMesh(int index, SceneNode* node)
{

	Ogre::Entity* wickEnt = mSM->createEntity("column.mesh");

	_wickNode = node->createChildSceneNode("wick");
	_wickNode->attachObject(wickEnt);
}

void Bomb::CreateParticlesSystems(SceneNode* node)
{

	_pSysFlameNode = node->createChildSceneNode();
	_pSysFlame = mSM->createParticleSystem("psFlameBomb", "flameSmoke");
	_pSysFlame->setEmitting(false);
	_pSysFlameNode->attachObject(_pSysFlame);

	_pSysSmokeNode = node->createChildSceneNode();
	_pSysSmoke = mSM->createParticleSystem("psSmokeBomb", "explosionSmoke");
	_pSysSmoke->setEmitting(true);
	_pSysSmokeNode->attachObject(_pSysSmoke);

}

void Bomb::Config(SceneNode* node)
{
	node->setScale(BOMB_SCALE);

	_wickNode->setScale(BOMB_WICK_SCALE);
	_wickNode->translate({ 0, node->getScale().y / 2, 0 });
	_pSysFlameNode->translate(BOMB_FLAME_INI_MOVE);
}

void Bomb::CreateAnimations()
{
	
}
