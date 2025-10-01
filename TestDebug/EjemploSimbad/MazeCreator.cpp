#include <iostream>
#include <fstream>
#include "MazeCreator.h"

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
    
}
