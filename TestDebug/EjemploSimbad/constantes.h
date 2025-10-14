#pragma once

#include <Ogre.h>

using uint = unsigned int;

const Ogre::Vector3 CUBE_SIZE = { 100, 0, 100 };
const uint PLAYER_SPEED = 1;
const uint PLAYER_LIFES = 3;

const string MAP_LAYOUT = "../../media/maps/stage1.txt";

const Ogre::Vector3 INITIAL_POS = Ogre::Vector3(0, 0, 0);

//Multiplicador al tamanyo
const Ogre::Vector3 PLAYER_SCALE = Ogre::Vector3(8, 8, 8);