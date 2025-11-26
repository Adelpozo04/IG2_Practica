#include "Bomb.h"
#include "constantes.h"

Bomb::Bomb(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, int index) : IG2Object(initPos, node, sceneMng)
{
	CompleteMesh(index, node);
	CreateParticlesSystems(node);
	Config(node);
	CreateAnimations();
}

void Bomb::InlineAnimation(float dt)
{

	if (_isVisible) {

	}

}

void Bomb::Update(float dt)
{

	_elapsedTime += dt;

	if (_elapsedTime >= BOMB_EXPLOSION_TIME) {
		Explote();		
	}

	if (_elapsedTime >= BOMB_SMOKE_TIME) {
		_pSysSmoke->setEmitting(false);
		_elapsedTime = 0;

	}

}

void Bomb::Reset()
{

	_pSysFlame->clear();
	_pSysFlame->setEmitting(true);

	_pSysSmoke->clear();
	_pSysSmoke->setEmitting(false);

	this->setVisible(true);
}

void Bomb::CompleteMesh(int index, SceneNode* node)
{

	Ogre::Entity* bombEnt = mSM->createEntity(BOMB_MESH);
	bombEnt->setMaterialName("bomb");

	Ogre::Entity* wickEnt = mSM->createEntity(WICK_MESH);
	wickEnt->setMaterialName("wick");

	_BombNode = node->createChildSceneNode("bomb" + index);
	_BombNode->attachObject(bombEnt);

	_wickNode = _BombNode->createChildSceneNode("wick" + index);
	_wickNode->attachObject(wickEnt);
}

void Bomb::CreateParticlesSystems(SceneNode* node)
{

	_pSysFlameNode = node->createChildSceneNode();
	_pSysFlame = mSM->createParticleSystem("psFlameBomb", "flameSmoke");
	_pSysFlame->setEmitting(true);
	_pSysFlameNode->attachObject(_pSysFlame);

	_pSysSmokeNode = node->createChildSceneNode();
	_pSysSmoke = mSM->createParticleSystem("psSmokeBomb", "explosionSmoke");
	_pSysSmoke->setEmitting(false);
	_pSysSmokeNode->attachObject(_pSysSmoke);

}

void Bomb::Config(SceneNode* node)
{
	node->setScale(BOMB_SCALE);

	_wickNode->setScale(BOMB_WICK_SCALE);
	_wickNode->translate({ 0, node->getScale().y / 2, 0 });
	_pSysFlameNode->setPosition(BOMB_FLAME_INI_MOVE);
}

void Bomb::CreateAnimations()
{
	
	//Bomb animation

	//Particle animation

}

void Bomb::Explote()
{
	_pSysFlame->clear();
	_pSysFlame->setEmitting(false);
	_pSysSmoke->setEmitting(true);
	_BombNode->setVisible(false);
	//Llamada a BombManager para que gestione el danyo hablando con colision manager

}
