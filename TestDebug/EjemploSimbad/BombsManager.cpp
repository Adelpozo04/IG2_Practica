#include "BombsManager.h"
#include "Bomb.h"
#include "PlayerManager.h"
#include "constantes.h"

BombsManager::BombsManager(Ogre::SceneManager* SM) : mSM(SM), bombPool(0)
{
    std::vector<Bomb*> mbombs;
    mbombs.reserve(MAX_NUM_BOMBS);

    for (int i = 0; i < MAX_NUM_BOMBS; ++i)
    {
        Bomb* b = new Bomb(Ogre::Vector3(0, 0, 0),mSM->getRootSceneNode()->createChildSceneNode(),mSM, i);
        b->setVisible(false);
        mbombs.push_back(b);
    }

    bombPool.resize(mbombs);
}

void BombsManager::Shoot(Ogre::Vector3 pos)
{
    if (bombPool.isFull())
        return;

    Bomb* b = bombPool.acquire();
    if (!b)
        return;

    b->setVisible(true);
    b->setPosition(pos);
    //b->setTimeToExplode(BOMB_EXPLOSION_TIME);
    bombInUse.push_back(b);
}

void BombsManager::Explode(Bomb* bomb)
{
    bomb->setVisible(false);
    bombPool.release(bomb);
    bombInUse.remove(bomb);
}
