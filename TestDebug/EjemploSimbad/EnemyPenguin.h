#ifndef ENEMYPENGUIN_H
#define ENEMYPENGUIN_H

#include "Enemy.h"
#include "constantes.h"

class EnemyPenguin : public Enemy
{

public:

    EnemyPenguin();
    EnemyPenguin(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, int index);

private:

    void Config() override;

    Ogre::SceneNode* mRazorNode = nullptr;

    Ogre::SceneNode* mHalo01 = nullptr;
    Ogre::SceneNode* mHalo02 = nullptr;

    std::vector< Ogre::SceneNode*> mFish1 = std::vector< Ogre::SceneNode*>(COMPLEX_ENEMY_FISH_AMOUNT, nullptr);
    std::vector< Ogre::SceneNode*> mFish2 = std::vector< Ogre::SceneNode*>(COMPLEX_ENEMY_FISH_AMOUNT, nullptr);

};

#endif // !ENEMYPENGUIN_H




