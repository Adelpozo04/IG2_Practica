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

EnemyPenguin::EnemyPenguin(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, int index, MazeManager* MM) :
	Enemy(initPos, node, sceneMng, COMPLEX_ENEMY_MAIN_MESH_NAME)
{

    Ogre::Entity* ent1 = mSM->createEntity("razor.mesh");
    mRazorNode = node->createChildSceneNode("nRazor" + index);
    mRazorNode->attachObject(ent1);

    mRazorNode->translate(4, 0, 0, Ogre::Node::TS_LOCAL);
    mRazorNode->setScale(0.5, 0.5, 0.2);

    mHalo01 = node->createChildSceneNode("mHalo01_" + index);
    mHalo02 = node->createChildSceneNode("mHalo02_" + index);

    for (int i = 0; i < mFish1.size(); ++i) {
        Ogre::Entity* ent = mSM->createEntity("fish.mesh");
        
        string name = "nFish1_" + to_string(i) + to_string(index);

        mFish1[i] = mHalo01->createChildSceneNode(name);
        mFish1[i]->attachObject(ent);
    }
    
    for (int i = 0; i < mFish2.size(); ++i) {
        Ogre::Entity* ent = mSM->createEntity("fish.mesh");

        string name = "nFish2_" + to_string(i) + to_string(index);

        mFish2[i] = mHalo02->createChildSceneNode(name);
        mFish2[i]->attachObject(ent);
    }

	_lifes = COMPLEX_ENEMY_LIFES;
	_speed = COMPLEX_ENEMY_SPEED;
	_currentDir = { 0, 0, 0 };
	_nextDir = { 0, 0, 0 };
	_offset = { 0, 0, 0 };
    Config();
    setDir(ChooseNextDir(MM));
    mNode->rotate(getOrientation().getRotationTo(getDir()));
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

void EnemyPenguin::move(MazeManager* MM, float dt)
{

    if (CanGo(getNextDir(), MM)) {
        if (getNextDir() != Ogre::Vector3::ZERO && canTurn(getNextDir(), MM, dt)) {
            setDir(getNextDir());
            Vector3 center = MM->getTileCenter(getPosition());
            setPosition(center);
            mNode->rotate(getOrientation().getRotationTo(getDir()));
            setNextDir({ 0, 0, 0 });
        }
    }

    if (passCenterTile(MM, dt)) {
        Vector3 selectDir = ChooseNextDir(MM);

        if (getDir() != selectDir) {
            setNextDir(selectDir);
        }
    }

    if (!CanGo(getDir(), MM)) {
        setDir({ 0, 0, 0 });
        Vector3 center = MM->getTileCenter(getPosition());
        setPosition(center);
        setNextDir(ChooseNextDir(MM));
    }

    Ogre::Vector3 newPos = getPosition() + getDir() * getSpeed() * dt;

    if (newPos.x < MM->GetNumTilesX() * CUBE_SIZE.x && newPos.z < MM->GetNumTilesZ() * CUBE_SIZE.z &&
        newPos.x >= 0 && newPos.z >= 0) {
        IG2Object::move(getDir() * getSpeed() * dt);
    }
    
}

void EnemyPenguin::inlineAnimation(float dt)
{

    mHalo01->yaw(Ogre::Degree(HALO_SPEED) * dt);
    mHalo02->yaw(Ogre::Degree(HALO_SPEED*-1 * dt));

}


