#include "PlayerManager.h"
#include "constantes.h"

PlayerManager::PlayerManager() : CharacterManager()
{


}

PlayerManager::PlayerManager(Ogre::SceneManager* SM, MazeManager* MM, UIManager* UIM) : CharacterManager(SM, MM), UImgr(UIM)
{

	CreateCharacters();
	UIM->updateTextBox(_characters.front()->getLifes(),_characters.front()->getPoints());
}

void PlayerManager::CreateCharacters()
{
	Ogre::Vector3 initPos = _MM->GetPlayerInitialPos();
	SceneNode* mPlayerNode = mSM->getRootSceneNode()->createChildSceneNode("nPlayer");
	_characters.push_back(new Player(initPos, mPlayerNode, mSM, PLAYER_MESH_NAME));
}

bool PlayerManager::keyPressed(const OgreBites::KeyboardEvent& evt) {

	switch (evt.keysym.sym)
	{
	case SDLK_DOWN:

		_characters.front()->setNextDir(Ogre::Vector3::NEGATIVE_UNIT_Z);
		break;

	case SDLK_UP:

		_characters.front()->setNextDir(Ogre::Vector3::UNIT_Z);
		break;

	case SDLK_LEFT:

		_characters.front()->setNextDir(Ogre::Vector3::UNIT_X);
		break;

	case SDLK_RIGHT:

		_characters.front()->setNextDir(Ogre::Vector3::NEGATIVE_UNIT_X);
		break;

	}

	return true;

}

void PlayerManager::Update(float dt) {

	_characters.front()->move(_MM, dt);

}

void PlayerManager::HitPlayer(int damage)
{

	_characters.front()->reciveDamage(damage);
	_characters.front()->setPosition(_MM->GetPlayerInitialPos());

	_characters.front()->setDir({ 0, 0, 0 });
	_characters.front()->setNextDir({ 0, 0, 0 });

	UImgr->updateTextBox(_characters.front()->getLifes(), _characters.front()->getPoints());

	if (_characters.front()->getLifes() <= 0) {
		UImgr->showDeathBox();
	}
}

