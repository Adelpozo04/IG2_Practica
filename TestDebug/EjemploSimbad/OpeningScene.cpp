#include "OpeningScene.h"
#include "constantes.h"
#include <OgreSceneManager.h>

OpeningScene::OpeningScene(Ogre::SceneManager* SM) : Scene(SM)
{



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
        1, 1, SUBDIVISION_LUZ_PLANO, SUBDIVISION_LUZ_PLANO, true, 1, 5, 5,
        Ogre::Vector3::UNIT_Z);

    Ogre::Entity* ent = mSM->createEntity("sueloAnimacion");
    ent->setMaterialName("animationFloor");
    Ogre::SceneNode* floor = mSM->getRootSceneNode()->createChildSceneNode();
    floor->attachObject(ent);

    //Configuracion plano
    floor->setPosition(0, 0, 0);
    floor->setScale(OS_SURFACE_SCALE);

    //Creacion de la luz
    Ogre::Light* directionalLight1 = mSM->createLight("DirectionalLight1");
    directionalLight1->setType(Ogre::Light::LT_DIRECTIONAL);
    directionalLight1->setDiffuseColour(1.0f, 1.0f, 1.0f);

    //Creacion de los personajes
    ///Simbad
    Ogre::Entity* simbadEnt = mSM->createEntity("Sinbad.mesh");
    _simbad = mSM->getRootSceneNode()->createChildSceneNode();
    _simbad->attachObject(simbadEnt);
    ///OgreHead
    Ogre::Entity* ogreHeadEnt = mSM->createEntity("ogrehead.mesh");
    _ogreHead = mSM->getRootSceneNode()->createChildSceneNode();
    _ogreHead->attachObject(ogreHeadEnt);
    ///Espadas
    _leftSword = mSM->createEntity("Sword.mesh");
    _rightSword = mSM->createEntity("Sword.mesh");

}
