#include "MazeManager.h"
#include "MazeCreator.h"

MazeManager::MazeManager(std::string map, Ogre::SceneManager* SM) : mSM(SM), _map(map)
{
	InitMaze();
}

MazeManager::~MazeManager()
{

	for (int i = 0; i < _maze.size(); ++i) {
		for (int j = 0; j < _maze[i].size(); ++j) {
			delete _maze[i][j];
		}
	}

}

void MazeManager::InitMaze()
{
	MazeCreator mc = MazeCreator(mSM);
	_maze = mc.GenerateMaze(_map);

	if (_maze.size() != 0) {
		_sizeX = _maze.size();
		_sizeZ = _maze[0].size();
	}
	
}