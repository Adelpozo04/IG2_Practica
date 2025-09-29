#include "MazeManager.h"
#include "MazeCreator.h"

MazeManager::MazeManager(std::string map, Ogre::SceneManager* SM) : mSM(SM), _map(map)
{
	InitMaze();
}

void MazeManager::InitMaze()
{

	MazeCreator mc = MazeCreator(mSM);
	_maze = mc.GenerateMaze(_map);

}
