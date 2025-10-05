#include <math.h>

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

bool MazeManager::IsTrasferable(Ogre::Vector3 position)
{
	std::pair<int, int> index = FromPositionToIndex(position);

	return _maze[index.first][index.second]->GetTransferable();
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

std::pair<int, int> MazeManager::FromPositionToIndex(Ogre::Vector3 position)
{

	int indexX = std::trunc(position.x / _sizeX);
	int indexZ = std::trunc(position.z / _sizeZ);

	std::pair<int, int> sol = std::pair<int, int>(indexX, indexZ);

	return sol;
}
