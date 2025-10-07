#include <math.h>

#include "MazeManager.h"
#include "MazeCreator.h"

MazeManager::MazeManager(std::string map, Ogre::SceneManager* SM) : mSM(SM), _map(map)
{
	InitMaze();
}

MazeManager::~MazeManager()
{

	for (int i = 0; i < _mazeData.maze.size(); ++i) {
		for (int j = 0; j < _mazeData.maze[i].size(); ++j) {
			delete _mazeData.maze[i][j];
		}
	}

}

bool MazeManager::IsTrasferable(Ogre::Vector3 position)
{
	std::pair<int, int> index = FromPositionToIndex(position);

	return _mazeData.maze[index.first][index.second]->GetTransferable();
}

Ogre::Vector3 MazeManager::GetPlayerInitialPos()
{
	return _mazeData.initialPos;
}

void MazeManager::InitMaze()
{
	MazeCreator mc = MazeCreator(mSM);
	_mazeData = mc.GenerateMaze(_map);

	if (_mazeData.maze.size() != 0) {
		_sizeX = _mazeData.maze.size();
		_sizeZ = _mazeData.maze[0].size();
	}
	
}

std::pair<int, int> MazeManager::FromPositionToIndex(Ogre::Vector3 position)
{

	int indexX = std::trunc(position.x / _sizeX);
	int indexZ = std::trunc(position.z / _sizeZ);

	std::pair<int, int> sol = std::pair<int, int>(indexX, indexZ);

	return sol;
}
