#include <math.h>

#include "MazeManager.h"
#include "MazeCreator.h"
#include "constantes.h"

MazeManager::MazeManager(std::string map, Ogre::SceneManager* SM) : 
	mSM(SM), _map(map), _sizeMesh(Ogre::Vector3::ZERO)
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

	if (index.first >= 0 && index.first < _mazeData.maze.size() && index.second >= 0 && index.second < _mazeData.maze[index.first].size()) {
		return _mazeData.maze[index.first][index.second]->GetTransferable();
	}
	else{
		return false;
	}
	
}

Ogre::Vector3 MazeManager::GetPlayerInitialPos()
{
	return _mazeData.initialPos;
}

vector<Ogre::Vector3> MazeManager::GetEnemiesInitialPos()
{
	return _mazeData.enemiesInitialPos;
}

Ogre::Vector3 MazeManager::GetTileSize()
{
	return _sizeMesh;
}

void MazeManager::InitMaze()
{
	MazeCreator mc = MazeCreator(mSM);
	_mazeData = mc.GenerateMaze(_map);

	if (_mazeData.maze.size() != 0) {
		_sizeX = _mazeData.maze.size();
		_sizeZ = _mazeData.maze[0].size();
	}

	int nCountX = 0;
	int nCountZ = 0;

	while (_mazeData.maze[nCountX][nCountZ]->GetTransferable() && nCountX < _mazeData.maze.size()) {
		while (_mazeData.maze[nCountX][nCountZ]->GetTransferable() && nCountZ < _mazeData.maze[nCountX].size()) {
			nCountZ++;
		}
		nCountX++;
		nCountZ = 0;
	}

	_sizeMesh = _mazeData.maze[nCountX][nCountZ]->calculateBoxSize();
	
}

std::pair<int, int> MazeManager::FromPositionToIndex(Ogre::Vector3 position)
{

	int indexX = std::trunc(position.x / _sizeMesh.x);
	int indexZ = std::trunc(position.z / _sizeMesh.z);

	std::pair<int, int> sol = std::pair<int, int>(indexX, indexZ);

	return sol;
}

Vector3  MazeManager::getTileCenter(Ogre::Vector3 position) {
	std::pair<int, int> index = FromPositionToIndex(position);

	return  _mazeData.maze[index.first][index.second]->getPosition() + CUBE_SIZE / 2;
}
