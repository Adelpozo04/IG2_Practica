#ifndef ENEMYPENGUIN_H
#define ENEMYPENGUIN_H

#include "Enemy.h"
#include "constantes.h"

class EnemyPenguin : public Enemy
{

public:

    EnemyPenguin();
    EnemyPenguin(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, int index, MazeManager* MM);

    void move(MazeManager* MM, float dt) override;

    void inlineAnimation(float dt) override;

private:

    void Config() override;

    //Nodo del jetpack en la espalda
    Ogre::SceneNode* mRazorNode = nullptr;

    //Nodo de la aureola de pescados superior
    Ogre::SceneNode* mHalo01 = nullptr;
    //Nodo de la aureola de pescados inferior
    Ogre::SceneNode* mHalo02 = nullptr;

    //Pescados superiores
    std::vector< Ogre::SceneNode*> mFish1 = std::vector< Ogre::SceneNode*>(COMPLEX_ENEMY_FISH_AMOUNT, nullptr);
    //Pescados inferiores
    std::vector< Ogre::SceneNode*> mFish2 = std::vector< Ogre::SceneNode*>(COMPLEX_ENEMY_FISH_AMOUNT, nullptr);

};

#endif // !ENEMYPENGUIN_H




