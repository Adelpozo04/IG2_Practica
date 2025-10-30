#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"

#include "MazeManager.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "ColisionManager.h"
#include "UIManager.h"
#include "LightManager.h"

class GameScene : public Scene
{

public:

    GameScene(Ogre::SceneManager* SM, OgreBites::TrayManager* TM, OgreBites::ApplicationContext* AC);

    ~GameScene();

    void Update(float dt) override;

private:

    void GenerateScene() override;

    OgreBites::TrayManager* mTrayMgr = nullptr;
    OgreBites::ApplicationContext* mAplicCont = nullptr;

    MazeManager* mMazeMgr = nullptr;
    PlayerManager* mPlayerMgr = nullptr;
    EnemyManager* mEnemyMgr = nullptr;
    ColisionManager* mColisionMgr = nullptr;
    UIManager* mUIMgr = nullptr;
    LightManager* mLightMgr = nullptr;

};

#endif // !GAMESCENE_H




