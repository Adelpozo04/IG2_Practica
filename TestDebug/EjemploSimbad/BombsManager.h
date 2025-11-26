#pragma once
#include <vector>
#include <list>
#include <Ogre.h>
#include "ObjectPool.h"

class Bomb;
class PlayerManager;

class BombsManager
{
public:
    BombsManager(Ogre::SceneManager* SM);
    ~BombsManager() = default;

    void Shoot(Ogre::Vector3 pos);
    void explode(Bomb* bomb); // libera bomba cuando explota
    void Update(float dt);

private:
    ObjectPool<Bomb*> bombPool;
    std::list<Bomb*> bombInUse;
    std::list<Bomb*> bombToExplode;
    Ogre::SceneManager* mSM;
    PlayerManager* mPM;
};
