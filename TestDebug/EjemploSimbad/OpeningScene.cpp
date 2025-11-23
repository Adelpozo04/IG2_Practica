#include "OpeningScene.h"
#include "constantes.h"
#include <OgreSceneManager.h>
#include "Bomb.h"

OpeningScene::OpeningScene(Ogre::SceneManager* SM, OgreBites::ApplicationContext* AC, Ogre::SceneNode* cam) : Scene(SM, AC, cam)
{

    GenerateScene();

}

OpeningScene::~OpeningScene()
{

    _simbad->setVisible(false);
    _ogreHead->setVisible(false);
    _light->setVisible(false);

}

void OpeningScene::Update(float dt)
{
    _elapsedTime += dt;

    if (_elapsedTime >= OS_SIMBAD_TOTAL_DUR) {
        _elapsedTime = 0;
        _isDancing = true;
        _isRunning = false;
    }

    if (_elapsedTime - dt < OS_SIMBAD_STATIC_DUR && _elapsedTime >= OS_SIMBAD_STATIC_DUR) {
        _isDancing = false;
        _isRunning = true;
    }

    if (_elapsedTime - dt < OS_SIMBAD_SWORD_PICK_DUR && _elapsedTime >= OS_SIMBAD_SWORD_PICK_DUR) {
        _simbadEnt->attachObjectToBone("Handle.R", _rightSword);
        _simbadEnt->attachObjectToBone("Handle.L", _leftSword);
    }

    if (_elapsedTime - dt < OS_SIMBAD_SWORD_DROP_DUR && _elapsedTime >= OS_SIMBAD_SWORD_DROP_DUR) {
        _simbadEnt->detachObjectFromBone(_rightSword);
        _simbadEnt->detachObjectFromBone(_leftSword);
    }

    if (_isDancing) {
        _animationStateDance->addTime(dt);
    }
    else if (_isRunning) {
        _animationStateRunTop->addTime(dt);
        _animationStateRunBase->addTime(dt);
    }

    _animationNodeSimbad->addTime(dt);
    _animationNodeOgreHead->addTime(dt);
        
}

void OpeningScene::GenerateScene()
{
    CreateFloor();
    ConfigCamera();
    CreateLight();
    CreateCharacters();
    CreateAnimations();   
}

void OpeningScene::CreateFloor()
{
    Ogre::MeshManager::getSingleton().createPlane("animationFloor", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        Ogre::Plane(Ogre::Vector3::UNIT_Y, 0),
        200, 200, SUBDIVISION_LUZ_PLANO, SUBDIVISION_LUZ_PLANO, true, 1, 30, 30,
        Ogre::Vector3::UNIT_Z);

    Ogre::Entity* ent = mSM->createEntity("animationFloor");
    ent->setMaterialName("WaveShader");

    Ogre::SceneNode* floor = mSM->getRootSceneNode()->createChildSceneNode("OS_Floor");
    floor->attachObject(ent);

    //Configuracion plano
    floor->setPosition(0, -5, 0);
    floor->setScale(OS_SURFACE_SCALE);

}

void OpeningScene::ConfigCamera()
{
    mCamNode->setPosition(0, 0, 35);
    mCamNode->lookAt(Ogre::Vector3(0, 0, -100), Ogre::Node::TS_WORLD);

}

void OpeningScene::CreateLight()
{
    Ogre::Light* directionalLight1 = mSM->createLight("DirectionalLight1");
    directionalLight1->setType(Ogre::Light::LT_DIRECTIONAL);
    directionalLight1->setDiffuseColour(0.75, 0.75, 0.75);
    _light = mSM->getRootSceneNode()->createChildSceneNode();
    _light->attachObject(directionalLight1);
    _light->setDirection(Ogre::Vector3(-0.25, -0.45, -0.45));

}

void OpeningScene::CreateCharacters() {
    //Simbad
    _simbadEnt = mSM->createEntity("Sinbad.mesh");
    _simbad = mSM->getRootSceneNode()->createChildSceneNode("OS_Simbad");
    _simbad->attachObject(_simbadEnt);
    _simbad->setPosition(0, 0, 0);

    //OgreHead
    Ogre::Entity* ogreHeadEnt = mSM->createEntity("ogrehead.mesh");
    _ogreHead = mSM->getRootSceneNode()->createChildSceneNode("OS_OgreHead");
    _ogreHead->attachObject(ogreHeadEnt);
    _ogreHead->setScale(0.15, 0.15, 0.15);
    _ogreHead->setPosition(-55, 0, 0);
    _ogreHead->rotate(Ogre::Quaternion(Ogre::Degree(90), Ogre::Vector3::UNIT_Y));

    //Espadas
    _leftSword = mSM->createEntity("Sword.mesh");
    _rightSword = mSM->createEntity("Sword.mesh");

}

void OpeningScene::CreateAnimations()
{
    //Creacion de las animaciones del mesh
    _animationStateDance = _simbadEnt->getAnimationState("Dance");
    _animationStateDance->setLoop(true);
    _animationStateDance->setEnabled(true);

    _animationStateRunTop = _simbadEnt->getAnimationState("RunTop");
    _animationStateRunTop->setLoop(true);
    _animationStateRunTop->setEnabled(true);

    _animationStateRunBase = _simbadEnt->getAnimationState("RunBase");
    _animationStateRunBase->setLoop(true);
    _animationStateRunBase->setEnabled(true);

    //Animaciones de nodos

    ///Simbad

    Ogre::Vector3 keyframePos = _simbad->getPosition();
    float currentTime = 0;

    Ogre::Animation* animationNodeSimbad = mSM->createAnimation("sinbadOpeningScene", OS_SIMBAD_TOTAL_DUR); 
    animationNodeSimbad->setInterpolationMode(Ogre::Animation::IM_SPLINE);
    Ogre::NodeAnimationTrack* trackSimbad = animationNodeSimbad->createNodeTrack(0);
    trackSimbad->setAssociatedNode(_simbad);

    Ogre::TransformKeyFrame* kfSimbad = trackSimbad->createNodeKeyFrame(0);
    kfSimbad->setTranslate(keyframePos);

    currentTime += OS_SIMBAD_STATIC_DUR;
    CreateKeyframe(kfSimbad, trackSimbad, currentTime, keyframePos, {0.01, 0, 0});

    currentTime += OS_SIMBAD_FLIP_DER_DUR;
    CreateKeyframe(kfSimbad, trackSimbad, currentTime, keyframePos,{0, 0, 0},
        Ogre::Vector3::UNIT_Y, OS_SIMBAD_FLIP_DER_DEGREES);

    currentTime += OS_SIMBAD_DER_DUR;
    CreateKeyframe(kfSimbad, trackSimbad, currentTime, keyframePos, OS_SIMBAD_DER_MOV * Ogre::Vector3::UNIT_X,
        Ogre::Vector3::UNIT_Y, OS_SIMBAD_FLIP_DER_DEGREES);

    currentTime += OS_SIMBAD_FLIP_IZQ_DUR;
    CreateKeyframe(kfSimbad, trackSimbad, currentTime, keyframePos, { 0, 0, 0 },
        Ogre::Vector3::UNIT_Y, OS_SIMBAD_FLIP_IZQ_DEGREES);

    currentTime += OS_SIMBAD_IZQ_DUR;
    CreateKeyframe(kfSimbad, trackSimbad, currentTime, keyframePos, OS_SIMBAD_IZQ_MOV * Ogre::Vector3::NEGATIVE_UNIT_X,
        Ogre::Vector3::UNIT_Y, OS_SIMBAD_FLIP_IZQ_DEGREES);

    currentTime += OS_SIMBAD_FLIP_DER2_DUR;
    CreateKeyframe(kfSimbad, trackSimbad, currentTime, keyframePos, {0, 0, 0},
        Ogre::Vector3::UNIT_Y, OS_SIMBAD_FLIP_DER2_DEGREES);

    currentTime += OS_SIMBAD_DER2_DUR;
    CreateKeyframe(kfSimbad, trackSimbad, currentTime, keyframePos, OS_SIMBAD_DER2_MOV * Ogre::Vector3::UNIT_X,
        Ogre::Vector3::UNIT_Y, OS_SIMBAD_FLIP_DER2_DEGREES);

    currentTime += OS_SIMBAD_FLIP_CENTER_DUR;
    CreateKeyframe(kfSimbad, trackSimbad, currentTime, keyframePos, {0, 0, 0},
        Ogre::Vector3::UNIT_Y, OS_SIMBAD_FLIP_CENTER_DEGREES);


    _animationNodeSimbad = mSM->createAnimationState("sinbadOpeningScene");
    _animationNodeSimbad->setLoop(true);
    _animationNodeSimbad->setEnabled(true);

    ///OgreHead

    Ogre::Vector3 keyframePosOgreHead = _ogreHead->getPosition();
    float currentTimeOgreHead = 0;

    Ogre::Animation* animationNodeOgreHead = mSM->createAnimation("ogreheadOpeningScene", OS_OGREHEAD_TOTAL_DUR);
    animationNodeOgreHead->setInterpolationMode(Ogre::Animation::IM_SPLINE);
    Ogre::NodeAnimationTrack* trackOgreHead = animationNodeOgreHead->createNodeTrack(0);
    trackOgreHead->setAssociatedNode(_ogreHead);

    Ogre::TransformKeyFrame* kfOgreHead = trackOgreHead->createNodeKeyFrame(0);
    kfOgreHead->setTranslate(keyframePosOgreHead);

    currentTimeOgreHead = 0.1;
    CreateKeyframe(kfOgreHead, trackOgreHead, currentTimeOgreHead, keyframePosOgreHead, {0.1, 0, 0},
        Ogre::Vector3::UNIT_Y, OS_OGREHEAD_FLIP_DER_DEGREES, OS_OGREHEAD_DEFAULT_SCAL);

    currentTimeOgreHead += OS_OGREHEAD_MED_DUR;
    CreateKeyframe(kfOgreHead, trackOgreHead, currentTimeOgreHead, keyframePosOgreHead, OS_OGREHEAD_MED_MOV * Ogre::Vector3::UNIT_X, 
        Ogre::Vector3::UNIT_Y, OS_OGREHEAD_FLIP_DER_DEGREES, OS_OGREHEAD_DEFAULT_SCAL);

    currentTimeOgreHead += OS_OGREHEAD_FLIP_IZQ_DUR;
    CreateKeyframe(kfOgreHead, trackOgreHead, currentTimeOgreHead, keyframePosOgreHead, { 0, 0, 0 },
        Ogre::Vector3::UNIT_Y, OS_OGREHEAD_FLIP_IZQ_DEGREES, OS_OGREHEAD_DEFAULT_SCAL);

    currentTimeOgreHead += OS_OGREHEAD_IZQ_DUR;
    CreateKeyframe(kfOgreHead, trackOgreHead, currentTimeOgreHead, keyframePosOgreHead, OS_OGREHEAD_IZQ_MOV * Ogre::Vector3::NEGATIVE_UNIT_X,
        Ogre::Vector3::UNIT_Y, OS_OGREHEAD_FLIP_IZQ_DEGREES, OS_OGREHEAD_DEFAULT_SCAL);

    currentTimeOgreHead += OS_OGREHEAD_FLIP_DER_DUR;
    CreateKeyframe(kfOgreHead, trackOgreHead, currentTimeOgreHead, keyframePosOgreHead, { 0, 0, 0 },
        Ogre::Vector3::UNIT_Y, OS_OGREHEAD_FLIP_DER_DEGREES, OS_OGREHEAD_DEFAULT_SCAL);

    currentTimeOgreHead += OS_OGREHEAD_DER2_DUR;
    CreateKeyframe(kfOgreHead, trackOgreHead, currentTimeOgreHead, keyframePosOgreHead, OS_OGREHEAD_DER2_MOV * Ogre::Vector3::UNIT_X,
        Ogre::Vector3::UNIT_Y, OS_OGREHEAD_FLIP_DER_DEGREES, OS_OGREHEAD_DER2_SCAL);

    _animationNodeOgreHead = mSM->createAnimationState("ogreheadOpeningScene");
    _animationNodeOgreHead->setLoop(true);
    _animationNodeOgreHead->setEnabled(true);
}

void OpeningScene::CreateKeyframe(Ogre::TransformKeyFrame* kf, Ogre::NodeAnimationTrack* track, Ogre::Real durStep, 
    Ogre::Vector3& keyframePos,
    Ogre::Vector3 traslationValue, 
    Ogre::Vector3 rotationValue, 
    float degrees, 
    Ogre::Vector3 scaleValue)
{
    kf = track->createNodeKeyFrame(durStep);

    keyframePos += traslationValue;

    kf->setTranslate(keyframePos); 
    kf->setRotation(Ogre::Quaternion(Ogre::Degree(degrees), rotationValue.normalisedCopy()));

    if (scaleValue != Ogre::Vector3::ZERO) {
        kf->setScale(scaleValue);
    }
    else {
        kf->setScale({1, 1, 1});
    }
    
    
}




