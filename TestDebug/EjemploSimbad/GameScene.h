#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <OgreCameraMan.h>

#include "Scene.h"

#include "MazeManager.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "ColisionManager.h"
#include "UIManager.h"
#include "LightManager.h"
#include "BombsManager.h"

class GameScene : public Scene
{

public:

    GameScene(Ogre::SceneManager* SM, OgreBites::TrayManager* TM, OgreBites::ApplicationContext* AC, Ogre::SceneNode* cam);

    ~GameScene();

    void Update(float dt) override;

private:

    void GenerateScene() override;

    OgreBites::TrayManager* mTrayMgr = nullptr;
    OgreBites::CameraMan* mCamMgr = nullptr;

    MazeManager* mMazeMgr = nullptr;
    PlayerManager* mPlayerMgr = nullptr;
    EnemyManager* mEnemyMgr = nullptr;
    ColisionManager* mColisionMgr = nullptr;
    UIManager* mUIMgr = nullptr;
    LightManager* mLightMgr = nullptr;
    BombsManager* mBombsMgr = nullptr;
};

#endif // !GAMESCENE_H




