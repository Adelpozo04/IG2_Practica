#include "BombsManager.h"
#include "Bomb.h"
#include "MazeManager.h"
#include "SmokeObject.h"
#include "constantes.h"

BombsManager::BombsManager(Ogre::SceneManager* SM, MazeManager* MZ) : mSM(SM), bombPool(0),smokePool(0), mMZ(MZ)
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
    // el tamaño es el numero de bombas + 1 ya que al desaparecer una puedes poner otra mientra el humo de la anterior sigue,* el rango,* 4 direcciones
    for (int i = 0; i <= (MAX_NUM_BOMBS + 1) * BOMB_EXPLOSION_RANGE*4;++i) {
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

    applyDamage(pos,BOMB_EXPLOSION_RANGE);
    /*SmokeObject* s = smokePool.acquire();

    if (!s)
        return;
    s->reset(pos);
    smokesInUse.push_back(s);*/
}

void BombsManager::Update(float dt)
{
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

    for (Bomb* b : bombsInUse) {
        if (b != nullptr && !b->Update(dt))
            bombsToExplode.push_back(b);
    }

    for (Bomb* b : bombsToExplode) {
        explode(b);
    }
    bombsToExplode.clear();

}

void BombsManager::applyDamage(Ogre::Vector3 pos, int range)
{
    if (!mMZ->IsTrasferable(pos) || range < 0)
        return;

    SmokeObject* s = smokePool.acquire();

    if (!s)
        return;

    s->reset(pos);
    smokesInUse.push_back(s);
    positionsWithDamage.push_back(pos);

    applyDamage(pos + (mMZ->GetTileSize() * Ogre::Vector3::UNIT_X), --range);
    applyDamage(pos + (mMZ->GetTileSize() * Ogre::Vector3::UNIT_Z), --range);
    applyDamage(pos + (mMZ->GetTileSize() * Ogre::Vector3::NEGATIVE_UNIT_X), --range);
    applyDamage(pos + (mMZ->GetTileSize() * Ogre::Vector3::NEGATIVE_UNIT_Z), --range);
}
