#include "OpeningScene.h"
#include "constantes.h"
#include <OgreSceneManager.h>

OpeningScene::OpeningScene(Ogre::SceneManager* SM, OgreBites::ApplicationContext* AC) : Scene(SM, AC)
{

    GenerateScene();

}

OpeningScene::~OpeningScene()
{


}

void OpeningScene::Update(float dt)
{



}

void OpeningScene::GenerateScene()
{
    //Creacion del plano
    Ogre::MeshManager::getSingleton().createPlane("animationFloor", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        Ogre::Plane(Ogre::Vector3::UNIT_Y, 0),
        0.6, 0.6, SUBDIVISION_LUZ_PLANO, SUBDIVISION_LUZ_PLANO, true, 1, 5, 5,
        Ogre::Vector3::UNIT_Z);

    Ogre::Entity* ent = mSM->createEntity("animationFloor");
    ent->setMaterialName("animationFloor");
    Ogre::SceneNode* floor = mSM->getRootSceneNode()->createChildSceneNode("OS_Floor");
    floor->attachObject(ent);

    ///Configuracion plano
    floor->setPosition(0, -5, 0);
    floor->setScale(OS_SURFACE_SCALE);

    //Creacion de la camara

    Ogre::Camera* cam = mSM->createCamera("Cam");
    cam->setNearClipDistance(1);
    cam->setFarClipDistance(10000);
    cam->setAutoAspectRatio(true);
    //cam->setPolygonMode(Ogre::PM_WIREFRAME);

    mCamNode = mSM->getRootSceneNode()->createChildSceneNode("nCam");
    mCamNode->attachObject(cam);

    mCamNode->setPosition(1.7, 2.6, 35.2);
    mCamNode->lookAt(Ogre::Vector3(0, 0, -100), Ogre::Node::TS_WORLD);

    // and tell it to render into the main window
    Ogre::Viewport* vp = mAplicCont->getRenderWindow()->addViewport(cam);

    //Creacion de la luz
    Ogre::Light* directionalLight1 = mSM->createLight("DirectionalLight1");
    directionalLight1->setType(Ogre::Light::LT_DIRECTIONAL);
    directionalLight1->setDiffuseColour(0.75, 0.75, 0.75);

    _light = mSM->getRootSceneNode()->createChildSceneNode();
    _light->attachObject(directionalLight1);
    _light->setDirection(Ogre::Vector3(-0.25, -0.45, -0.45));

    //Creacion de los personajes
    ///Simbad
    Ogre::Entity* simbadEnt = mSM->createEntity("Sinbad.mesh");
    _simbad = mSM->getRootSceneNode()->createChildSceneNode("OS_Simbad");
    _simbad->attachObject(simbadEnt);

    ///OgreHead
    Ogre::Entity* ogreHeadEnt = mSM->createEntity("ogrehead.mesh");
    _ogreHead = mSM->getRootSceneNode()->createChildSceneNode("OS_OgreHead");
    _ogreHead->attachObject(ogreHeadEnt);
    _ogreHead->setScale(0.2, 0.2, 0.2);
    _ogreHead->setPosition(50, 0, 0);

    ///Espadas
    _leftSword = mSM->createEntity("Sword.mesh");
    _rightSword = mSM->createEntity("Sword.mesh");

}
