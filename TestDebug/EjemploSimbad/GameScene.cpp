#include "GameScene.h"
#include "constantes.h"

GameScene::GameScene(Ogre::SceneManager* SM, OgreBites::TrayManager* TM, OgreBites::ApplicationContext* AC): 
    mTrayMgr(TM), Scene(SM, AC)
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
    //Creacion camara
    Camera* cam = mSM->createCamera("Cam");
    cam->setNearClipDistance(1);
    cam->setFarClipDistance(10000);
    cam->setAutoAspectRatio(true);
    //cam->setPolygonMode(Ogre::PM_WIREFRAME);

    mCamNode = mSM->getRootSceneNode()->createChildSceneNode("nCam");
    mCamNode->attachObject(cam);

    mCamNode->setPosition(0, -3000, 0);
    mCamNode->lookAt(Ogre::Vector3(0, 3000, 0), Ogre::Node::TS_WORLD);

    // and tell it to render into the main window
    Viewport* vp = mAplicCont->getRenderWindow()->addViewport(cam);

    mCamMgr = new OgreBites::CameraMan(mCamNode);
    mAplicCont->addInputListener(mCamMgr);
    mCamMgr->setStyle(OgreBites::CS_ORBIT);


    //Creacion managers
    mUIMgr = new UIManager(mTrayMgr, mAplicCont->getRenderWindow());
    mMazeMgr = new MazeManager(MAP_LAYOUT, mSM);
    mPlayerMgr = new PlayerManager(mSM, mMazeMgr, mUIMgr);
    mAplicCont->addInputListener(mPlayerMgr);
    mLightMgr = new LightManager(mPlayerMgr, mSM, mMazeMgr->getLight());
    mEnemyMgr = new EnemyManager(mSM, mMazeMgr);
    mColisionMgr = new ColisionManager(mPlayerMgr, mEnemyMgr);

}


