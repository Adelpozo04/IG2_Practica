#include "UIManager.h"
#include "constantes.h"
#include <string>

UIManager::UIManager(OgreBites::TrayManager* TrayMgr, Ogre::RenderWindow* window)
{
    mTrayMgr = TrayMgr;
    mTrayMgr->showFrameStats(OgreBites::TL_BOTTOMLEFT);
    mTrayMgr->createLabel(OgreBites::TL_BOTTOMRIGHT, "AreaTextBox", "Player", 250);
    mTextBox = mTrayMgr->createTextBox(OgreBites::TL_BOTTOMRIGHT, "TextBox", "Info", 180, 125);

}

UIManager::~UIManager()
{

}

void UIManager::updateTextBox(int nLifes, int points) const
{
    std::string text = "lifes: " + std::to_string(nLifes) + "\nponts: " + std::to_string(points);
    mTextBox->setText(text);
}

void UIManager::showDeathBox()
{
    mDeathBox = mTrayMgr->createTextBox(OgreBites::TL_CENTER, "DeathBox", "GAME OVER", 250, 250);
    mDeathBox->setText(GAMEOVER_TEXT);
}
