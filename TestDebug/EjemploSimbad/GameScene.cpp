#include "GameScene.h"
#include "constantes.h"
#include "Bomb.h"

GameScene::GameScene(Ogre::SceneManager* SM, OgreBites::TrayManager* TM, OgreBites::ApplicationContext* AC, Ogre::SceneNode* cam):
    mTrayMgr(TM), Scene(SM, AC, cam)
{
    GenerateScene();
}

GameScene::~GameScene()
{

    delete mMazeMgr;
    delete mPlayerMgr;
    delete mEnemyMgr;
    delete mColisionMgr;

    mMazeMgr = nullptr;
    mPlayerMgr = nullptr;
    mEnemyMgr = nullptr;
    mColisionMgr = nullptr;

}

void GameScene::Update(float dt)
{
    /*mPlayerMgr->Update(dt);
    mEnemyMgr->Update(dt);
    mColisionMgr->Update();*/
}

void GameScene::GenerateScene()
{
    //Creacion camara
    mCamNode->setPosition(0, -3000, 0);
    mCamNode->lookAt(Ogre::Vector3(0, 3000, 0), Ogre::Node::TS_WORLD);

    mCamMgr = new OgreBites::CameraMan(mCamNode);
    mAplicCont->addInputListener(mCamMgr);
    mCamMgr->setStyle(OgreBites::CS_ORBIT);

    //BombaTest
    SceneNode* bNode = mSM->getRootSceneNode()->createChildSceneNode("BombTest");
    Bomb* b = new Bomb({ 150, -20, 250 }, bNode, mSM, "geosphere4500.mesh", 0);

    //Creacion managers
    mUIMgr = new UIManager(mTrayMgr, mAplicCont->getRenderWindow());
    mMazeMgr = new MazeManager(MAP_LAYOUT, mSM);
    mPlayerMgr = new PlayerManager(mSM, mMazeMgr, mUIMgr);
    mAplicCont->addInputListener(mPlayerMgr);
    mLightMgr = new LightManager(mPlayerMgr, mSM, mMazeMgr->getLight());
    mEnemyMgr = new EnemyManager(mSM, mMazeMgr);
    mColisionMgr = new ColisionManager(mPlayerMgr, mEnemyMgr);

}


