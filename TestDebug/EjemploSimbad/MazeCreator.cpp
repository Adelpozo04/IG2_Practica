#include <iostream>
#include <fstream>
#include "MazeCreator.h"
#include "Constants.h"

MazeCreator::MazeCreator(Ogre::SceneManager* SM) : mSM(SM) 
{ 
    mazeNode = mSM->getRootSceneNode()->createChildSceneNode("Maze"); 
}
/*
std::vector<std::vector<Tile*>> MazeCreator::GenerateMaze(std::string map)
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

        Ogre::SceneNode* mazeNode = mSM->getRootSceneNode()->createChildSceneNode("Maze");

        //Bucle de rellenado de laberinto.
        for (int i = 0; i < sizeX; ++i) {

            for (int j = 0; j < sizeZ; ++j) {

                char mapFloor;
                mapFile >> mapFloor;

                int index = (i * sizeZ) + j;
                Ogre::String id = "nCube" + Ogre::StringConverter::toString(index);

                if (mapFloor == 'x') {
                    
                    nodes[index] = mazeNode->createChildSceneNode(id);
                    maze[i][j] = new Tile(Ogre::Vector3{cubeSize.x * i, 0, cubeSize.z * j}, nodes[index], mSM, "cube.mesh", false);
                }
                else if(mapFloor == 'o'){
                    nodes[index] = mazeNode->createChildSceneNode(id);
                    maze[i][j] = new Tile(Ogre::Vector3{ cubeSize.x * i, 0, cubeSize.z * j }, nodes[index], mSM, true);
                }
                
            }  
        }

        return maze;
    }
    else {

        std::vector<std::vector<Tile*>> mazeEmpty = std::vector<std::vector<Tile*>>(0, std::vector<Tile*>(0));

        return mazeEmpty;

    }
    
}*/

std::vector<std::vector<Tile*>> MazeCreator::GenerateMaze(std::string file)
{
    std::string s = "../../media/maps/";
    s += file;
    std::ifstream mapFile(s);

    if (!mapFile.is_open()) throw "Error al abrir el archivo";

    //Lectura del tamanyo del laberinto
    int sizeX;
    int sizeZ;

    mapFile >> sizeX;
    mapFile >> sizeZ;

    std::vector<Ogre::SceneNode*> nodes = std::vector<Ogre::SceneNode*>(sizeX * sizeZ);

    //Vector solucion
    std::vector<std::vector<Tile*>> maze = std::vector<std::vector<Tile*>>(sizeX, std::vector<Tile*>(sizeZ));

    //Bucle de rellenado de laberinto.
    for (int i = 0; i < sizeX; ++i) {

        for (int j = 0; j < sizeZ; ++j) {

            char mapFloor;
            mapFile >> mapFloor;

            int index = (i * sizeZ) + j;
            readChars(mapFloor, i, j, index, maze, nodes);

        }
    }

    mazeNode->setPosition(centraLab(sizeX), 0, centraLab(sizeZ));

    return maze;
}

void MazeCreator::readChars(char c, int i, int j,int index, std::vector<std::vector<Tile*>>& maze, std::vector<Ogre::SceneNode*>& nodes)
{
    Ogre::String id = "nCube" + Ogre::StringConverter::toString(index);

    if (c == 'x') {

        nodes[index] = mazeNode->createChildSceneNode(id);
        float x = CUBE_SIZE * i;
        float z = CUBE_SIZE * j;
        maze[i][j] = new Tile(Ogre::Vector3{ x, 0, z}, nodes[index], mSM, "cube.mesh", false);
    }
    else if (c == 'o') {
        nodes[index] = mazeNode->createChildSceneNode(id);
        float x = CUBE_SIZE * i;
        float z = CUBE_SIZE * j;
        maze[i][j] = new Tile(Ogre::Vector3{ x, 0, z }, nodes[index], mSM, true);
    }
}

double MazeCreator::centraLab(int a)
{
    double b = a - 1;
    b = b * CUBE_SIZE;
    b = b * -1;
    b = b / 2;
    return b;
}
