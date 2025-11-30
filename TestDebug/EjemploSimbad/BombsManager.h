#pragma once
#include <vector>
#include <list>
#include <Ogre.h>
#include "ObjectPool.h"

class Bomb;
class SmokeObject;
class MazeManager;

class BombsManager
{
public:
    BombsManager(Ogre::SceneManager* SM, MazeManager* mz);
    ~BombsManager() = default;

    void Shoot(Ogre::Vector3 pos);
    void explode(Bomb* bomb); // libera bomba cuando explota
    void Update(float dt);
    inline  std::vector< Ogre::Vector3>& const getPositionsWithDamage() { return positionsWithDamage; }
private:
    void applyDamage(Ogre::Vector3 pos, int range);
    void applyDamage(Ogre::Vector3 pos, int range, Ogre::Vector3 dir);
    ObjectPool<Bomb*> bombPool;
    std::list<Bomb*> bombsInUse;
    std::list<Bomb*> bombsToExplode;
    ObjectPool<SmokeObject*> smokePool;
    std::list<SmokeObject*> smokesInUse;
    std::list<SmokeObject*> smokesToStop;
    Ogre::SceneManager* mSM;
    std::vector< Ogre::Vector3> positionsWithDamage;
    MazeManager* mMZ = nullptr;
};
