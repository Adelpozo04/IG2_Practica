#include "Player.h"
#include "constantes.h"
#include "Enemy.h"

Player::Player() :
	Character()
{
	_lifes = PLAYER_LIFES;
	_speed = PLAYER_SPEED;
	_points = INITIAL_POINTS;
	_currentDir = { 0, 0, 0 };
	_nextDir = { 0, 0, 0 };
	Config();
}

Player::Player(Vector3 initPos, SceneNode* node, SceneManager* sceneMng) :
	Character(initPos, node, sceneMng)
{
	_lifes = PLAYER_LIFES;
	_speed = PLAYER_SPEED;
	_points = INITIAL_POINTS;
	_currentDir = { 0, 0, 0 };
	_nextDir = { 0, 0, 0 };

	Ogre::Entity* _simbadEnt = sceneMng->createEntity(PLAYER_MESH_NAME);

	_animationStateRunTop = _simbadEnt->getAnimationState("RunTop");
	_animationStateRunTop->setLoop(true);
	_animationStateRunTop->setEnabled(true);

	_animationStateRunBase = _simbadEnt->getAnimationState("RunBase");
	_animationStateRunBase->setLoop(true);
	_animationStateRunBase->setEnabled(true);

	node->attachObject(_simbadEnt);

	Config();
}

void Player::Config()
{
	setScale(PLAYER_SCALE);
}

void Player::move(MazeManager* MM, float dt)
{

	if (getNextDir() != Ogre::Vector3::ZERO && CanGo(getNextDir(), MM)) {
		if (canTurn(getNextDir(),MM, dt)) {
			setDir(getNextDir());
			Vector3 center = MM->getTileCenter(getPosition());
			setPosition(center);
			mNode->rotate(getOrientation().getRotationTo(getDir()));
			setNextDir({ 0, 0, 0 });
		}
	}

	if (!CanGo(getDir(), MM)) {
		setDir({ 0, 0, 0 });
		Vector3 center = MM->getTileCenter(getPosition());
		setPosition(center);
	}

	Ogre::Vector3 newPos = getPosition() + getDir() * getSpeed() * dt;

	if (newPos.x < MM->GetNumTilesX() * CUBE_SIZE.x && newPos.z < MM->GetNumTilesZ() * CUBE_SIZE.z &&
		newPos.x >= 0 && newPos.z >= 0) {
		IG2Object::move(getDir() * getSpeed() * dt);

		if (getDir() != Ogre::Vector3::ZERO) {
			_animationStateRunTop->addTime(dt);
			_animationStateRunBase->addTime(dt);
		}	
	}

}

void Player::inlineAnimation(float dt)
{
}


