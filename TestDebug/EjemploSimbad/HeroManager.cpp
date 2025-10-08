#include "HeroManager.h"
#include "Config.h"

HeroManager::HeroManager(Hero* mH, Ogre::SceneManager* sM, Ogre::Node* hNode): mHero(mH), mSM(sM), heroNode(hNode)
{
}

HeroManager::~HeroManager()
{
	delete mHero;
}

bool HeroManager::keyPressed(const OgreBites::KeyboardEvent& ev)
{
	switch (ev.keysym.sym) {
	case SDLK_LEFT:
		mHero->setNewDir(Vector3(-1, 0, 0));
		break;
	case SDLK_RIGHT:
		mHero->setNewDir(Vector3(1, 0, 0));
		break;
	case SDLK_UP:
		mHero->setNewDir(Vector3(0, 0, -1));
		break;
	case SDLK_DOWN:
		mHero->setNewDir(Vector3(0, 0, 1));
		break;
	default:
		break;
	}
	return true;
}

void HeroManager::frameRendered(const Ogre::FrameEvent& ev)
{//Aquí comprueba si hay que hacer algún cambio de dirección
	if (mHero->getDirAct() != mHero->getNewDir()) {
		if (checkDir()) {
			mHero->setDirAct(mHero->getNewDir());
			Quaternion q = mHero->getOrientation().getRotationTo(mHero->getNewDir());
			//rotate(q);
			heroNode->rotate(q);
		}
	}
	uint frenador = 1;
	/*if (checkWallCollision(dirAct)) {
		frenador = 0;
	}*/
	float speed = mHero->getSpeed();
	Vector3 dir = mHero->getDirAct();
	mHero->move(dir * speed * frenador);
	mHero->setPosX(dir.x * speed * frenador);
	mHero->setPosZ(dir.z * speed * frenador);

	/*move(mher * speed * frenador);
	PosX += dirAct.x * speed * frenador;
	PosZ += dirAct.z * speed * frenador;*/
}

bool HeroManager::checkDir()
{

	double margenX = (mHero->getDirAct().x * CUBE_SIZE) / -2;
	double margenZ = (mHero->getDirAct().z * CUBE_SIZE) / -2;
	uint _x = (mHero->getX() + margenX) / CUBE_SIZE;
	uint _y = (mHero->getZ() + margenZ) / CUBE_SIZE;
	if (mHero->getNewDir().x != 0) {
		uint aux = _x + mHero->getNewDir().x;
		return mzM->canWalk(_y, aux);
	}
	else if (mHero->getNewDir().z != 0) {
		uint aux = _y + mHero->getNewDir().z;
		return mzM->canWalk(aux, _x);
	}
	else
		return false;
}

bool HeroManager::checkWallCollisions(Vector3 dir)
{
	//Aquí comprueba si se va a chocar con un muro
	double margenX = (dir.x * CUBE_SIZE) / -2;
	double margenZ = (dir.z * CUBE_SIZE) / -2;
	uint _x = (mHero->getX() + margenX) / CUBE_SIZE;
	uint _y = (mHero->getZ() + margenZ) / CUBE_SIZE;
	uint aux = _x + dir.x;
	uint aux2 = _y + dir.z;

	return mzM->canWalk(_x,_y);
}
