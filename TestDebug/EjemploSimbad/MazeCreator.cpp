#include <iostream>
#include <fstream>
#include "MazeCreator.h"
#include "constantes.h"

MazeManager::MazeData MazeCreator::GenerateMaze(std::string map)
{
    ifstream mapFile;
    mapFile.open(map);

    if (mapFile.is_open()) {

        //Lectura del tamanyo del laberinto
        int sizeX;
        int sizeZ;

        mapFile >> sizeX;
        mapFile >> sizeZ;

        std::vector<Ogre::SceneNode*> nodes = std::vector<Ogre::SceneNode*>(sizeX * sizeZ);

        //Calculo de tamanyo de un cubo

        Ogre::SceneNode* test = mSM->getRootSceneNode()->createChildSceneNode("nCube");
        Tile* cube = new Tile(Ogre::Vector3{ 0, 0, 0 }, test, mSM, "cube.mesh", false);
        Ogre::Vector3 cubeSize = cube->calculateBoxSize();

        delete cube;

        //Vector solucion
        std::vector<std::vector<Tile*>> maze = std::vector<std::vector<Tile*>>(sizeX, std::vector<Tile*>(sizeZ));

        mazeNode = mSM->getRootSceneNode()->createChildSceneNode("Maze");

        //Bucle de rellenado de laberinto.
        
        Ogre::Vector3 initPos = Ogre::Vector3::ZERO;

        ReadMaze(sizeX, sizeZ, cubeSize, mapFile, nodes, maze, mazeNode, initPos);

        MazeManager::MazeData mazeData = MazeManager::MazeData(maze, initPos);

        ConfigMaze(mazeNode, cubeSize);

        return mazeData;
    }
    else {

        MazeManager::MazeData mazeData = MazeManager::MazeData();

        return mazeData;

    }
    
}

void MazeCreator::ReadMaze(int sizeX, int sizeZ, Ogre::Vector3& cubeSize, ifstream& mapFile, std::vector<Ogre::SceneNode*>& nodes,
    std::vector<std::vector<Tile*>>& maze, Ogre::SceneNode* mazeNode, Ogre::Vector3& initPos)
{

    for (int i = 0; i < sizeX; ++i) {

        for (int j = 0; j < sizeZ; ++j) {

            char mapFloor;
            mapFile >> mapFloor;

            int index = (i * sizeZ) + j;
            Ogre::String id = "nCube" + Ogre::StringConverter::toString(index);

            readChars(mapFloor, i, j, index, maze, nodes, initPos);
            
        }
    }

}

void MazeCreator::readChars(char c, int i, int j, int index, std::vector<std::vector<Tile*>>& maze, std::vector<Ogre::SceneNode*>& nodes, Ogre::Vector3& initPos)
{
    Ogre::String id = "nCube" + Ogre::StringConverter::toString(index);

    switch (c)
    {
        case 'x':       
            nodes[index] = mazeNode->createChildSceneNode(id);
            nodes[index]->setScale(CUBE_SIZE.x / INI_CUBE_SIZE.x, 1, CUBE_SIZE.z / INI_CUBE_SIZE.z);
            maze[i][j] = new Tile(Ogre::Vector3{ CUBE_SIZE.x * i, 0, CUBE_SIZE.z * j }, nodes[index], mSM, "cube.mesh", false);
            break;
        case 'o':
            nodes[index] = mazeNode->createChildSceneNode(id);
            nodes[index]->setScale(CUBE_SIZE.x / INI_CUBE_SIZE.x, 1, CUBE_SIZE.z / INI_CUBE_SIZE.z);
            maze[i][j] = new Tile(Ogre::Vector3{ CUBE_SIZE.x * i, 0, CUBE_SIZE.z * j }, nodes[index], mSM, true);
            break;
        case 'h':

            nodes[index] = mazeNode->createChildSceneNode(id);
            nodes[index]->setScale(CUBE_SIZE.x / INI_CUBE_SIZE.x, 1, CUBE_SIZE.z / INI_CUBE_SIZE.z);
            maze[i][j] = new Tile(Ogre::Vector3{ CUBE_SIZE.x * i, 0, CUBE_SIZE.z * j }, nodes[index], mSM, true);
            initPos = Ogre::Vector3(CUBE_SIZE.x * i + (CUBE_SIZE.x / 2), 0, CUBE_SIZE.z * j + (CUBE_SIZE.z / 2));
            break;

        default:
            break;
    }
}

void MazeCreator::ConfigMaze(Ogre::SceneNode* mazeNode, Ogre::Vector3& cubeSize)
{

    Ogre::Vector3 newPos = mazeNode->getPosition() + Ogre::Vector3(CUBE_SIZE.x / 2, 0, CUBE_SIZE.z / 2);
    mazeNode->setPosition(newPos);

}