#pragma once
#include "IG2Object.h"
#include "Ogre.h"

class Tile;

class Mob : public IG2Object
{
public:
	Mob(){}
	Mob(Vector3 initPos, Vector3 dirA, SceneNode* node, SceneManager* sceneMng, string meshName, float _speed);
	virtual ~Mob();
	virtual void changeDirection(Vector3 newDir);
	inline virtual Vector3 getDirAct() { return dirAct; };
	inline virtual Vector3 getNewDir() { return newDir; };
	inline virtual double getX() { return PosX;}
	inline virtual double getZ() { return PosZ; }
	inline virtual float getSpeed() { return speed; }
	inline virtual void setDirAct(Vector3 dir) { dirAct = dir; }
	inline virtual void setNewDir(Vector3 nD) { newDir = nD; }
	inline virtual void setPosX(double x) { PosX = x; }
	inline virtual void setPosZ(double z) { PosZ = z; }
protected:
	float speed;
	Vector3 dirAct;
	Vector3 newDir;
	double PosX;
	double PosZ;
};

