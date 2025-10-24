#include "SinbadExample.h"
#include "IG2Object.h"
#include "constantes.h"

using namespace std;
using namespace Ogre;


bool SinbadExample::keyPressed(const OgreBites::KeyboardEvent& evt) {

    // ESC key finished the rendering...
    if (evt.keysym.sym == SDLK_ESCAPE) {
        getRoot()->queueEndRendering();
    }

    return true;
}

void SinbadExample::frameRendered(const Ogre::FrameEvent& evt) {

    auto currentTime = std::chrono::high_resolution_clock::now();

    float deltaTime = (std::chrono::duration<float>(currentTime - lastTime)).count();

    lastTime = currentTime;

    mPlayerMgr->Update(deltaTime);
    mEnemyMgr->Update(deltaTime);
    mColisionMgr->Update();

    //std::cout << "DeltaTime: " << deltaTime << "\n";
}


void SinbadExample::shutdown() {

    delete mMazeMgr;
    delete mPlayerMgr;
    delete mEnemyMgr;
    delete mColisionMgr;

    mMazeMgr = nullptr;
    mPlayerMgr = nullptr;
    mEnemyMgr = nullptr;
    mColisionMgr = nullptr;

    mShaderGenerator->removeSceneManager(mSM);
    mSM->removeRenderQueueListener(mOverlaySystem);

    mRoot->destroySceneManager(mSM);

    delete mTrayMgr;  mTrayMgr = nullptr;
    delete mCamMgr; mCamMgr = nullptr;

    // do not forget to call the base 
    OgreBites::ApplicationContext::shutdown();
}

void SinbadExample::setup(void) {

    // do not forget to call the base first
    OgreBites::ApplicationContext::setup();

    // Create the scene manager
    mSM = mRoot->createSceneManager();

    // Register our scene with the RTSS
    mShaderGenerator->addSceneManager(mSM);
        
    mSM->addRenderQueueListener(mOverlaySystem);
    //mTrayMgr = new OgreBites::TrayManager("TrayGUISystem", mWindow.render);
    mTrayMgr = new OgreBites::TrayManager("TrayGUISystem", getRenderWindow());
    mTrayMgr->showFrameStats(OgreBites::TL_BOTTOMLEFT);
    addInputListener(mTrayMgr);

    setupScene();

    lastTime = std::chrono::high_resolution_clock::now();

    // Adds the listener for this object
    addInputListener(this);
}

void SinbadExample::setupScene(void) {

    //------------------------------------------------------------------------
    // Creating the camera

    Camera* cam = mSM->createCamera("Cam");
    cam->setNearClipDistance(1);
    cam->setFarClipDistance(10000);
    cam->setAutoAspectRatio(true);
    //cam->setPolygonMode(Ogre::PM_WIREFRAME);

    mCamNode = mSM->getRootSceneNode()->createChildSceneNode("nCam");
    mCamNode->attachObject(cam);

    mCamNode->setPosition(1000, -1000, 1000);
    mCamNode->lookAt(Ogre::Vector3(1000, 1000, 1000), Ogre::Node::TS_WORLD);

    // and tell it to render into the main window
    Viewport* vp = getRenderWindow()->addViewport(cam);

    mCamMgr = new OgreBites::CameraMan(mCamNode);
    addInputListener(mCamMgr);
    mCamMgr->setStyle(OgreBites::CS_ORBIT);


    //------------------------------------------------------------------------
    // Creating the light

    //mSM->setAmbientLight(ColourValue(0.5, 0.5, 0.5));
    
    Light* luz = mSM->createLight("Luz");
    luz->setType(Ogre::Light::LT_DIRECTIONAL);
    luz->setDiffuseColour(0.75, 0.75, 0.75);

    mLightNode = mSM->getRootSceneNode()->createChildSceneNode("nLuz");
    mLightNode->attachObject(luz);
    mLightNode->setDirection(Ogre::Vector3(-1, -1, -1));
 

    //------------------------------------------------------------------------
    // Creating Sinbad

    mUIMgr = new UIManager(mTrayMgr,getRenderWindow());
    mMazeMgr = new MazeManager(MAP_LAYOUT, mSM);
    mPlayerMgr = new PlayerManager(mSM, mMazeMgr,mUIMgr);
    addInputListener(mPlayerMgr);
    mEnemyMgr = new EnemyManager(mSM, mMazeMgr);
    mColisionMgr = new ColisionManager(mPlayerMgr, mEnemyMgr);
 
}