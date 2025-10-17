#include "EnemyPenguin.h"

EnemyPenguin::EnemyPenguin() : 
	Enemy()
{

	_lifes = COMPLEX_ENEMY_LIFES;
	_speed = COMPLEX_ENEMY_SPEED;
	_currentDir = { 0, 0, 0 };
	_nextDir = { 0, 0, 0 };
	_offset = { 0, 0, 0 };
    Config();
}

EnemyPenguin::EnemyPenguin(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, int index) : 
	Enemy(initPos, node, sceneMng, COMPLEX_ENEMY_MAIN_MESH_NAME)
{

    Ogre::Entity* ent1 = mSM->createEntity("razor.mesh");
    mRazorNode = node->createChildSceneNode("nRazor" + index);
    mRazorNode->attachObject(ent1);

    mRazorNode->setPosition(node->getPosition());
    mRazorNode->setScale(0.5, 0.5, 0.2);

    mHalo01 = node->createChildSceneNode("mHalo01_" + index);
    mHalo02 = node->createChildSceneNode("mHalo01_" + index);

    for (int i = 0; i < mFish1.size(); ++i) {
        Ogre::Entity* ent = mSM->createEntity("fish.mesh");
        
        mFish1[i] = mHalo01->createChildSceneNode("nFish1_" + i + index);
        mFish1[i]->attachObject(ent);
    }
    
    for (int i = 0; i < mFish2.size(); ++i) {
        Ogre::Entity* ent = mSM->createEntity("fish.mesh");

        mFish2[i] = mHalo02->createChildSceneNode("nFish2_" + i + index);
        mFish2[i]->attachObject(ent);
    }

	_lifes = COMPLEX_ENEMY_LIFES;
	_speed = COMPLEX_ENEMY_SPEED;
	_currentDir = { 0, 0, 0 };
	_nextDir = { 0, 0, 0 };
	_offset = { 0, 0, 0 };
    Config();
}

void EnemyPenguin::Config()
{
    float rot = (float)360 / mFish1.size();
    float rot2 = (float)360 / mFish2.size();

    mHalo01->setPosition(0, 30, 0);
    mHalo02->setPosition(0, 10, 0);

    for (int i = 0; i < mFish1.size(); ++i) {
        mFish1[i]->yaw(Ogre::Degree(rot * i));
        mFish1[i]->translate({0, 0, HALO_SPACE}, Ogre::Node::TS_LOCAL);
    }

    for (int i = 0; i < mFish2.size(); ++i) {
        mFish2[i]->yaw(Ogre::Degree(rot2 * i));
        mFish2[i]->translate({ 0, 0, HALO_SPACE * 2}, Ogre::Node::TS_LOCAL);
    }

}


