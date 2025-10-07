#pragma once

#include <Ogre.h>

using uint = unsigned int;

const uint CUBE_SIZE = 98;
const uint PLAYER_SPEED = 5;
const uint PLAYER_LIFES = 3;

const string MAP_LAYOUT = "../../media/maps/stage1.txt";

const Ogre::Vector3 INITIAL_POS = Ogre::Vector3(0, 0, 0);

//Multiplicador al tamanyo
const Ogre::Vector3 PLAYER_SCALE = Ogre::Vector3(8, 8, 8);