#include "Bomb.h"
#include "constantes.h"

Bomb::Bomb(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, int index) : _index(index), IG2Object(initPos, node, sceneMng)
{
	CompleteMesh(node);
	CreateParticlesSystems(node);
	Config(node);
	CreateAnimations();
}

void Bomb::InlineAnimation(float dt)
{

	if (_isVisible) {

	}

}

bool Bomb::Update(float dt)
{

	_elapsedTime += dt;

	//if (_elapsedTime >= BOMB_EXPLOSION_TIME)
		//Explote();

	/*if (_elapsedTime >= BOMB_SMOKE_TIME) {
		_pSysSmoke->setEmitting(false);
		_elapsedTime = 0;
	}*/
	_animationNodeBomb->addTime(dt);
	_animationNodeFlame->addTime(dt);
	return _elapsedTime <= BOMB_EXPLOSION_TIME;
}

void Bomb::reset(Ogre::Vector3 pos)
{

	setPosition(pos);
	_pSysFlame->clear();
	_pSysFlame->setEmitting(true);
	_elapsedTime = 0;
	//_pSysSmoke->clear();
	//_pSysSmoke->setEmitting(false);

	this->setVisible(true);
	_animationNodeBomb->setEnabled(true);
	_animationNodeBomb->setTimePosition(0);

	_animationNodeFlame->setEnabled(true);
	_animationNodeFlame->setTimePosition(0);
}

void Bomb::CompleteMesh(SceneNode* node)
{

	Ogre::Entity* bombEnt = mSM->createEntity(BOMB_MESH);
	bombEnt->setMaterialName("bomb");

	Ogre::Entity* wickEnt = mSM->createEntity(WICK_MESH);
	wickEnt->setMaterialName("wick");

	_BombNode = node->createChildSceneNode();
	_BombNode->attachObject(bombEnt);

	_wickNode = node->createChildSceneNode();
	_wickNode->attachObject(wickEnt);
}

void Bomb::CreateParticlesSystems(SceneNode* node)
{

	_pSysFlameNode = node->createChildSceneNode();
	_pSysFlame = mSM->createParticleSystem("psFlameBomb" + std::to_string(_index), "flameSmoke");
	_pSysFlame->setEmitting(false);
	_pSysFlameNode->attachObject(_pSysFlame);

	/*_pSysSmokeNode = node->createChildSceneNode();
	_pSysSmoke = mSM->createParticleSystem("psSmokeBomb" + _index, "explosionSmoke");
	_pSysSmoke->setEmitting(false);
	_pSysSmokeNode->attachObject(_pSysSmoke);*/

}

void Bomb::Config(SceneNode* node)
{
	node->setScale(BOMB_SCALE);

	_wickNode->setScale(BOMB_WICK_SCALE);
	_wickNode->translate({ 0, node->getScale().y / 2, 0 });
	_pSysFlameNode->setPosition(BOMB_FLAME_INI_MOVE);
	mNode->setVisible(false);
}

void Bomb::CreateAnimations()
{
	
	//Bomb animation
	Ogre::Animation* animationBomb = mSM->createAnimation("bombAnim" + std::to_string(_index), ANIMATIONTIME);
	animationBomb->setInterpolationMode(Ogre::Animation::IM_SPLINE);
	Ogre::NodeAnimationTrack* trackBomb = animationBomb->createNodeTrack(0);
	trackBomb->setAssociatedNode(_BombNode);
	Ogre::TransformKeyFrame* kfBomb = trackBomb->createNodeKeyFrame(0);
	Vector3 pos = _BombNode->getPosition();
	createKf(kfBomb, trackBomb, 0, pos, {0, 0, 0},
		{0,0,0}, 0, { 1, 1, 1 });
	kfBomb = trackBomb->createNodeKeyFrame(1);
	createKf(kfBomb, trackBomb, ANIMATIONTIME /2, pos, { 0, 1, 0 },
		{ 0,0,0 }, 0, BOMB_ANIM_SCALE);
	_animationNodeBomb = mSM->createAnimationState("bombAnim" + std::to_string(_index));
	_animationNodeBomb->setEnabled(false);
	_animationNodeBomb->setLoop(true);

	//Particle animation
	Ogre::Animation* animationFlame = mSM->createAnimation("flameAnim" + std::to_string(_index), BOMB_EXPLOSION_TIME);
	animationFlame->setInterpolationMode(Ogre::Animation::IM_SPLINE);
	Ogre::NodeAnimationTrack* trackFlame = animationFlame->createNodeTrack(0);
	trackFlame->setAssociatedNode(_pSysFlameNode);
	Ogre::TransformKeyFrame* kfFlame = trackFlame->createNodeKeyFrame(0);
	pos = _pSysFlameNode->getPosition();
	createKf(kfFlame, trackFlame, 0, pos, { 0, 0, 0 },
		{ 0,0,0 }, 0, { 1, 1, 1 });
	kfFlame = trackFlame->createNodeKeyFrame(BOMB_EXPLOSION_TIME);
	pos = pos + getAABB().getSize();
	createKf(kfFlame, trackFlame, BOMB_EXPLOSION_TIME, pos, {0, 0, 0},
		{ 0,0,0 }, 0, { 1, 1, 1 });
	_animationNodeFlame = mSM->createAnimationState("flameAnim" + std::to_string(_index));
	_animationNodeFlame->setEnabled(false);
	_animationNodeFlame->setLoop(false);
}

void Bomb::createKf(Ogre::TransformKeyFrame* kf, Ogre::NodeAnimationTrack* track, Ogre::Real durStep, Ogre::Vector3& keyframePos, Ogre::Vector3 traslationValue, Ogre::Vector3 rotationValue, float degrees, Ogre::Vector3 scaleValue)
{
	kf = track->createNodeKeyFrame(durStep);

	keyframePos += traslationValue;

	kf->setTranslate(keyframePos);
	kf->setRotation(Ogre::Quaternion(Ogre::Degree(degrees), rotationValue.normalisedCopy()));

	if (scaleValue != Ogre::Vector3::ZERO) {
		kf->setScale(scaleValue);
	}
	else {
		kf->setScale({ 1, 1, 1 });
	}

}

void Bomb::explode()
{
	_pSysFlame->clear();
	_pSysFlame->setEmitting(false);
	mNode->setVisible(false);
	//_pSysSmoke->setEmitting(true);
	//_BombNode->setVisible(false);
	//Llamada a BombManager para que gestione el danyo hablando con colision manager

}
