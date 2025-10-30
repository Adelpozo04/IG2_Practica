#ifndef __SINBADEXAMPLE_H__
#define __SINBADEXAMPLE_H__

#include <OgreApplicationContext.h>
#include <OgreSceneManager.h>
#include <OgreRTShaderSystem.h>       
#include <OgreSceneNode.h>
#include <OgreTrays.h>
#include <OgreCameraMan.h>
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreMeshManager.h>
#include <sstream>
#include <iostream>
#include <string>
#include "Ogre.h"
#include <OgreWindowEventUtilities.h>
#include <SDL_keycode.h>

class GameScene;
class OpeningScene;

class SinbadExample: public OgreBites::ApplicationContext, OgreBites::InputListener {

public:
    explicit SinbadExample() : OgreBites::ApplicationContext("SinbadExample") {};
    virtual ~SinbadExample() {};

protected:
    virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
    virtual void frameRendered(const Ogre::FrameEvent& evt);
    virtual void setup();
    virtual void shutdown();
    virtual void setupScene();

    Ogre::SceneManager* mSM = nullptr;
    OgreBites::TrayManager* mTrayMgr = nullptr;

    Ogre::Light* light = nullptr;
    Ogre::SceneNode* mLightParent = nullptr;
    Ogre::SceneNode* mLightNode = nullptr;

    Ogre::SceneNode* mCamNode = nullptr;
    OgreBites::CameraMan* mCamMgr = nullptr;

    GameScene* mGameScn = nullptr;
    OpeningScene* mOpeningScn = nullptr;

    std::chrono::time_point<std::chrono::high_resolution_clock> lastTime;

};

#endif
