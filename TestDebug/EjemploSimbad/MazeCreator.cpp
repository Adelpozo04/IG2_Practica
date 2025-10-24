#include <iostream>
#include <fstream>
#include "MazeCreator.h"
#include "constantes.h"

MazeManager::MazeData* MazeCreator::GenerateMaze(std::string map)
{
    ifstream mapFile;
    mapFile.open(map);

    if (mapFile.is_open()) {

        //Lectura del tamanyo del laberinto
        int sizeX;
        int sizeZ;
        string matSuelo;

        mapFile >> sizeX;
        mapFile >> sizeZ;
        mapFile >> matMuro;
        mapFile >> matSuelo;

        std::vector<Ogre::SceneNode*> nodes = std::vector<Ogre::SceneNode*>(sizeX * sizeZ);

        //Calculo de tamanyo de un cubo

        Ogre::SceneNode* test = mSM->getRootSceneNode()->createChildSceneNode("nCube");
        Tile* cube = new Tile(Ogre::Vector3{ 0, 0, 0 }, test, mSM, "cube.mesh", false);
        Ogre::Vector3 cubeSize = cube->calculateBoxSize();

        delete cube;
        cube = nullptr;

        //Vector solucion
        std::vector<std::vector<Tile*>> maze = std::vector<std::vector<Tile*>>(sizeX, std::vector<Tile*>(sizeZ));

        mazeNode = mSM->getRootSceneNode()->createChildSceneNode("Maze");

        //Bucle de rellenado de laberinto.
        
        Ogre::Vector3 initPos = Ogre::Vector3::ZERO;

        std::vector<Ogre::Vector3> enemiesInitPos = std::vector<Ogre::Vector3>(0);

        ReadMaze(sizeX, sizeZ, cubeSize, mapFile, nodes, maze, mazeNode, initPos, enemiesInitPos);

        MazeManager::MazeData* mazeData = new MazeManager::MazeData(maze, initPos, enemiesInitPos);

        ConfigMaze(mazeNode, cubeSize);

        //creacion del suelo
        Ogre::MeshManager::getSingleton().createPlane("suelo", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, Plane(Vector3::UNIT_Y, 0), 1, 1,
            SUBDIVISION_LUZ_PLANO, SUBDIVISION_LUZ_PLANO, true, 1, sizeX, sizeZ, Vector3::UNIT_Z);
        //Creación del suelo
        Entity* Suel = mSM->createEntity("suelo");

        Ogre::SceneNode* nodoSuelo = mazeNode->createChildSceneNode();
        nodoSuelo->setPosition((sizeZ - 1) * CUBE_SIZE.x / 2, (float)CUBE_SIZE.y / -2, (sizeX - 1) * CUBE_SIZE.z / 2);
        nodoSuelo->setScale(sizeZ * CUBE_SIZE.x, 1, sizeX * CUBE_SIZE.z);
        Suel->setMaterialName(matSuelo);
        nodoSuelo->attachObject(Suel);

        return mazeData;
    }
    else {

        MazeManager::MazeData* mazeData = new MazeManager::MazeData();

        return mazeData;

    }
    
}

void MazeCreator::ReadMaze(int sizeX, int sizeZ, Ogre::Vector3& cubeSize, ifstream& mapFile, std::vector<Ogre::SceneNode*>& nodes,
    std::vector<std::vector<Tile*>>& maze, Ogre::SceneNode* mazeNode, Ogre::Vector3& initPos, std::vector<Ogre::Vector3>& enemiesInitPos)
{

    for (int i = 0; i < sizeX; ++i) {

        for (int j = 0; j < sizeZ; ++j) {

            char mapFloor;
            mapFile >> mapFloor;

            int index = (i * sizeZ) + j;
            Ogre::String id = "nCube" + Ogre::StringConverter::toString(index);

            readChars(mapFloor, i, j, index, maze, nodes, initPos, enemiesInitPos);
            
        }
    }

}

void MazeCreator::readChars(char c, int i, int j, int index, std::vector<std::vector<Tile*>>& maze, std::vector<Ogre::SceneNode*>& nodes, 
    Ogre::Vector3& initPos, std::vector<Ogre::Vector3>& enemiesInitPos)
{
    Ogre::String id = "nCube" + Ogre::StringConverter::toString(index);

    switch (c)
    {
    case 'x':
        nodes[index] = mazeNode->createChildSceneNode(id);
        nodes[index]->setScale(CUBE_SIZE.x / INI_CUBE_SIZE.x, 1, CUBE_SIZE.z / INI_CUBE_SIZE.z);
        maze[i][j] = new Tile(Ogre::Vector3{ CUBE_SIZE.x * i, 0, CUBE_SIZE.z * j }, nodes[index], mSM, "cube.mesh", false);
        maze[i][j]->setMaterialName(matMuro);
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
    case 'v':
        nodes[index] = mazeNode->createChildSceneNode(id);
        nodes[index]->setScale(CUBE_SIZE.x / INI_CUBE_SIZE.x, 1, CUBE_SIZE.z / INI_CUBE_SIZE.z);
        maze[i][j] = new Tile(Ogre::Vector3{ CUBE_SIZE.x * i, 0, CUBE_SIZE.z * j }, nodes[index], mSM, true);
        enemiesInitPos.push_back(Ogre::Vector3(CUBE_SIZE.x * i + (CUBE_SIZE.x / 2), 0, CUBE_SIZE.z * j + (CUBE_SIZE.z / 2)));
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