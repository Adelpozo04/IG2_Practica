#include "BombsManager.h"
#include "Bomb.h"
#include "PlayerManager.h"
#include "SmokeObject.h"
#include "constantes.h"

BombsManager::BombsManager(Ogre::SceneManager* SM) : mSM(SM), bombPool(0),smokePool(0)
{
    std::vector<Bomb*> mbombs;
    mbombs.reserve(MAX_NUM_BOMBS);

    for (int i = 0; i < MAX_NUM_BOMBS; ++i)
    {
        Bomb* b = new Bomb(Ogre::Vector3(0, 0, 0),mSM->getRootSceneNode()->createChildSceneNode(),mSM,i);
        mbombs.push_back(b);
    }

    bombPool.resize(mbombs);

    std::vector<SmokeObject*> mSmokes;
    for (int i = 0; i < MAX_NUM_BOMBS * BOMB_EXPLOSION_RANGE;++i) {
        SmokeObject* s = new SmokeObject(Ogre::Vector3(0, 0, 0), mSM->getRootSceneNode()->createChildSceneNode(), mSM, i);
        mSmokes.push_back(s);
    }
    smokePool.resize(mSmokes);
}

void BombsManager::Shoot(Ogre::Vector3 pos)
{
    if (bombPool.isFull())
        return;

    Bomb* b = bombPool.acquire();
    if (!b)
        return;

    b->reset(pos);
    //b->setTimeToExplode(BOMB_EXPLOSION_TIME);
    bombsInUse.push_back(b);
}

void BombsManager::explode(Bomb* bomb)
{
    Ogre::Vector3 pos = bomb->getPosition();
    bomb->explode();
    bombPool.release(bomb);
    bombsInUse.remove(bomb);

    SmokeObject* s = smokePool.acquire();

    if (!s)
        return;
    s->reset(pos);
    smokesInUse.push_back(s);
}

void BombsManager::Update(float dt)
{
    for (Bomb* b : bombsInUse) {
        if (b != nullptr && !b->Update(dt))
            bombsToExplode.push_back(b);
    }

    for (Bomb* b : bombsToExplode) {
        explode(b);
    }
    bombsToExplode.clear();

    for (SmokeObject* s : smokesInUse) {
        if (s != nullptr && !s->update(dt))
            smokesToStop.push_back(s);
    }

    for (SmokeObject* s : smokesToStop) {
        s->stop();
        smokePool.release(s);
        smokesInUse.remove(s);
    }
    smokesToStop.clear();
}
