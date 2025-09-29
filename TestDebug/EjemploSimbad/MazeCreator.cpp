#include <iostream>
#include <fstream>
#include "MazeCreator.h"

std::vector<std::vector<IG2Object>>* MazeCreator::GenerateMaze(std::string map)
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
        IG2Object* cube = new IG2Object(Ogre::Vector3{ 0, 0, 0 }, test, mSM, "cube.mesh");
        Ogre::Vector3 cubeSize = cube->calculateBoxSize();

        //Vector solucion
        std::vector<std::vector<IG2Object>> maze = std::vector<std::vector<IG2Object>>(sizeX, std::vector<IG2Object>(sizeZ));

        //Bucle de rellenado de laberinto.
        for (int i = 0; i < sizeX; ++i) {

            for (int j = 0; j < sizeZ; ++j) {

                char mapFloor;
                mapFile >> mapFloor;

                int index = (i * sizeZ) + j;
                Ogre::String id = "nCube" + Ogre::StringConverter::toString(index);

                if (mapFloor == 'x') {
                    
                    nodes[index] = mSM->getRootSceneNode()->createChildSceneNode(id);
                    maze[i][j] = IG2Object(Ogre::Vector3{cubeSize.x * i, 0, cubeSize.z * j}, nodes[index], mSM, "cube.mesh");
                }
                else if(mapFloor == 'o'){
                    nodes[index] = mSM->getRootSceneNode()->createChildSceneNode(id);
                    maze[i][j] = IG2Object(Ogre::Vector3{ cubeSize.x * i, 0, cubeSize.z * j }, nodes[index], mSM);
                }
                
            }  
        }

        return &maze;
    }
    else {

        return nullptr;

    }
    
}
