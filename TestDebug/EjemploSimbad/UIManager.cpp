#include "UIManager.h"
#include <string>

UIManager::UIManager(OgreBites::TrayManager* TrayMgr, Ogre::RenderWindow* window)
{
    mTrayMgr = TrayMgr;
    mTrayMgr->showFrameStats(OgreBites::TL_BOTTOMLEFT);
    mTrayMgr->createLabel(OgreBites::TL_BOTTOMRIGHT, "AreaTextBox", "Player", 250);
    mTextBox = mTrayMgr->createTextBox(OgreBites::TL_BOTTOMRIGHT, "TextBox", "Info", 280, 175);
}

UIManager::~UIManager()
{
    delete mTextBox;
}

void UIManager::updateTextBox(int nLifes, int points) const
{
    std::string text = "lifes: " + std::to_string(nLifes) + "\nponts: " + std::to_string(points);
    mTextBox->setText(text);
}
