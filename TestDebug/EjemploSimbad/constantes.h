#pragma once

#include <Ogre.h>

using uint = unsigned int;

//MAPA
const Ogre::Vector3 INI_CUBE_SIZE = Ogre::Vector3(98, 98, 98);
const Ogre::Vector3 CUBE_SIZE = Ogre::Vector3(100, 100, 100);

//PLAYER
const uint PLAYER_SPEED = 15;
const uint PLAYER_LIFES = 3;
const string PLAYER_MESH_NAME = "Sinbad.mesh";
const uint PLAYER_INITIAL_POINTS = 0;

const string MAP_LAYOUT = "../../media/maps/stage1.txt";

const Ogre::Vector3 INITIAL_POS = Ogre::Vector3(0, 0, 0);

//Multiplicador al tamanyo
const Ogre::Vector3 PLAYER_SCALE = Ogre::Vector3(8, 8, 8);