#include "IG2Project.h"
#include "DataSizes.h"

using namespace std;
using namespace Ogre;


bool IG2Project::keyPressed(const OgreBites::KeyboardEvent& evt) {

    // ESC key finished the rendering...
    if (evt.keysym.sym == SDLK_ESCAPE) {
        getRoot()->queueEndRendering();
    }

    if (evt.keysym.sym == SDLK_d) {
        _planeRot = true;
        _rightRot = true;
    }

    if (evt.keysym.sym == SDLK_a) {
        _planeRot = true;
        _rightRot = false;
    }

    if (evt.keysym.sym == SDLK_s) {
        _planeRot = false;
        _rightRot = false;
    }

    if (evt.keysym.sym == SDLK_w) {
        _turbo = true;
        _plane->Turbo();
    }

    return true;
}

void IG2Project::frameRendered(const Ogre::FrameEvent& evt) {

    if (!_turbo) {
        _flightControlNode->yaw(Ogre::Degree(DataSizes::AIRPLANE_SPEED * evt.timeSinceLastFrame));
    }
    else{
    
        _flightControlNode->yaw(Ogre::Degree(DataSizes::AIRPLANE_SPEED * evt.timeSinceLastFrame * 2));
        
    }
    

    if (_planeRot) {
        if (_rightRot) {
            _planeNode->roll(Ogre::Degree(DataSizes::AIRPLANE_ROTATION * evt.timeSinceLastFrame), Ogre::Node::TS_LOCAL);
        }
        else {
            _planeNode->roll(Ogre::Degree(-DataSizes::AIRPLANE_ROTATION * evt.timeSinceLastFrame), Ogre::Node::TS_LOCAL);
        }
    }

}

void IG2Project::shutdown() {

    mShaderGenerator->removeSceneManager(mSM);
    mSM->removeRenderQueueListener(mOverlaySystem);

    mRoot->destroySceneManager(mSM);

    delete mTrayMgr;  mTrayMgr = nullptr;
    delete mCamMgr; mCamMgr = nullptr;

    // do not forget to call the base 
    OgreBites::ApplicationContext::shutdown();
}

void IG2Project::setup(void) {

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

    // Adds the listener for this object
    addInputListener(this);
    setupScene();
}

void IG2Project::setupScene(void) {

    //------------------------------------------------------------------------
    // Creating the camera

    Camera* cam = mSM->createCamera("Cam");
    cam->setNearClipDistance(1);
    cam->setFarClipDistance(10000);
    cam->setAutoAspectRatio(true);
    //cam->setPolygonMode(Ogre::PM_WIREFRAME);

    mCamNode = mSM->getRootSceneNode()->createChildSceneNode("nCam");
    mCamNode->attachObject(cam);

    mCamNode->setPosition(1000, 0, 0);
    mCamNode->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TS_WORLD);

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
 
    //Plane creation
    _flightControlNode = mSM->getRootSceneNode()->createChildSceneNode();
    _planeNode = _flightControlNode->createChildSceneNode();
    _plane = new Body({ 0, 0, 0 }, _planeNode, mSM);

    _plane->move({ -2500, 0, 0 });
   
    //Floor

    MeshManager::getSingleton().createPlane("floor", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        Plane(Vector3::UNIT_Y, 0),
        5000, 5000, 200, 200, true, 1, 5, 5, Vector3::UNIT_Z);

    Entity* ent = mSM->createEntity("floor");

    ent->setMaterialName("floorJun");

    _floor = mSM->getRootSceneNode()->createChildSceneNode();
    _floor->attachObject(ent);

    _floor->translate({0, -450, 0});

    //Sky
    Ogre::Plane skyPlane;
    skyPlane.d = 100;
    skyPlane.normal = Ogre::Vector3::UNIT_Z;
    mSM->setSkyPlane(true, skyPlane, "skyJun", 1500, 50, true, 1.5, 50, 50);

}