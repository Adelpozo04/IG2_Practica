#include "SinbadExample.h"
#include "IG2Object.h"
#include "GameScene.h"
#include "OpeningScene.h"
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

    float deltaTime = evt.timeSinceLastFrame;

    mGameScn->Update(deltaTime);
    //mOpeningScn->Update(deltaTime);

    //std::cout << "DeltaTime: " << deltaTime << "\n";

    //std::cout << mCamNode->getPosition() << "\n";
}


void SinbadExample::shutdown() {

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

    mGameScn = new GameScene(mSM, mTrayMgr, this);
    //mOpeningScn = new OpeningScene(mSM, this);
 
}