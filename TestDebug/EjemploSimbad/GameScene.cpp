#include "GameScene.h"
#include "constantes.h"

GameScene::GameScene(Ogre::SceneManager* SM, OgreBites::TrayManager* TM, OgreBites::ApplicationContext* AC): 
    mTrayMgr(TM), Scene(SM), mAplicCont(AC)
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
    mPlayerMgr->Update(dt);
    mEnemyMgr->Update(dt);
    mColisionMgr->Update();
}

void GameScene::GenerateScene()
{

    mUIMgr = new UIManager(mTrayMgr, mAplicCont->getRenderWindow());
    mMazeMgr = new MazeManager(MAP_LAYOUT, mSM);
    mPlayerMgr = new PlayerManager(mSM, mMazeMgr, mUIMgr);
    mAplicCont->addInputListener(mPlayerMgr);
    mLightMgr = new LightManager(mPlayerMgr, mSM, mMazeMgr->getLight());
    mEnemyMgr = new EnemyManager(mSM, mMazeMgr);
    mColisionMgr = new ColisionManager(mPlayerMgr, mEnemyMgr);

}


