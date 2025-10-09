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
            /*if (mapFloor == 'x') {

                nodes[index] = mazeNode->createChildSceneNode(id);
                maze[i][j] = new Tile(Ogre::Vector3{ cubeSize.x * i, 0, cubeSize.z * j}, nodes[index], mSM, "cube.mesh", false);
            }
            else if (mapFloor == 'o') {
                nodes[index] = mazeNode->createChildSceneNode(id);
                maze[i][j] = new Tile(Ogre::Vector3{ cubeSize.x * i, 0, cubeSize.z * j }, nodes[index], mSM, true);
            }
            else if (mapFloor == 'h') {
                nodes[index] = mazeNode->createChildSceneNode(id);
                maze[i][j] = new Tile(Ogre::Vector3{ cubeSize.x * i, 0, cubeSize.z * j }, nodes[index], mSM, true);
                initPos = Ogre::Vector3(cubeSize.x * i + (cubeSize.x / 2), 0, cubeSize.z * j + (cubeSize.z / 2));
            }*/
        }
    }

}

void MazeCreator::readChars(char c, int i, int j, int index, std::vector<std::vector<Tile*>>& maze, std::vector<Ogre::SceneNode*>& nodes, Ogre::Vector3& initPos)
{
    Ogre::String id = "nCube" + Ogre::StringConverter::toString(index);

    if (c == 'x') {

        nodes[index] = mazeNode->createChildSceneNode(id);
        float x = INI_CUBE_SIZE.x * i;
        float z = INI_CUBE_SIZE.z * j;
        maze[i][j] = new Tile(Ogre::Vector3{ x, 0, z }, nodes[index], mSM, "cube.mesh", false);
    }
    else if (c == 'o') {
        nodes[index] = mazeNode->createChildSceneNode(id);
        float x = INI_CUBE_SIZE.x * i;
        float z = INI_CUBE_SIZE.z * j;
        maze[i][j] = new Tile(Ogre::Vector3{ x, 0, z }, nodes[index], mSM, true);
    }
    else if (c == 'h') {
        nodes[index] = mazeNode->createChildSceneNode(id);
        float x = INI_CUBE_SIZE.x * i;
        float z = INI_CUBE_SIZE.z * j;
        maze[i][j] = new Tile(Ogre::Vector3{ x, 0, z }, nodes[index], mSM, true);
        initPos = Ogre::Vector3(x + INI_CUBE_SIZE.x/2, 0, z + INI_CUBE_SIZE.z/2);


        /*hero = new Hero(Ogre::Vector3{x, 0, z}, Vector3(1, 0, 0), mSM->getRootSceneNode()->createChildSceneNode("Hero"),
            mSM, HERO_MESH_NAME, HERO_SPEED, HERO_INITIAL_LIFES, HERO_INITIAL_POINTS);
        mSM->getRootSceneNode()->getChild("Hero")->scale(Vector3(10, 10, 10));
        hMan = new HeroManager(hero, mSM, mSM->getRootSceneNode()->getChild("Hero"));*/
    }
}

void MazeCreator::ConfigMaze(Ogre::SceneNode* mazeNode, Ogre::Vector3& cubeSize)
{

    Ogre::Vector3 newPos = mazeNode->getPosition() + Ogre::Vector3(cubeSize.x / 2, 0, cubeSize.z / 2);
    mazeNode->setPosition(newPos);

}