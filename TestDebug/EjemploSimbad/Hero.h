#pragma once
#include <OgreSceneManager.h>
#include "Mob.h"
#include <vector>
class Hero : public Mob
{
public:
	Hero() {};
	Hero(Vector3 initPos, Vector3 dirAct, SceneNode* node, SceneManager* sceneMng, string meshName, float speed, uint iniLifes, uint iniPoints);
	virtual ~Hero();
	inline uint getLifes() { return nLifes; }
	inline uint getPoints() { return points; }
	inline void setPoints(uint nP) { points = nP; }
	inline void setLifes(uint nL) { points = nL; }
private:
	uint nLifes;
	uint points;
};