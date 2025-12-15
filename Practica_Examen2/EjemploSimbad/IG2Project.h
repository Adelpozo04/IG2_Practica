#ifndef __IG2PROJECT_H__
#define __IG2PROJECT_H__

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

#include "Body.h"

class IG2Project: public OgreBites::ApplicationContext, OgreBites::InputListener {

public:
    explicit IG2Project() : OgreBites::ApplicationContext("SinbadExample") {};
    virtual ~IG2Project() {};

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

    Ogre::SceneNode* _flightControlNode = nullptr;
    Ogre::SceneNode* _planeNode = nullptr;
    Body* _plane = nullptr;

    SceneNode* _floor = nullptr;

    bool _rightRot = false;
    bool _planeRot = false;
    bool _turbo = false;

};

#endif
