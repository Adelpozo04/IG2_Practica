#pragma once

#include <Ogre.h>

using uint = unsigned int;

//MAPA
const Ogre::Vector3 INI_CUBE_SIZE = Ogre::Vector3(98, 98, 98);
const Ogre::Vector3 CUBE_SIZE = Ogre::Vector3(100, 100, 100);

//PLAYER
const float PLAYER_SPEED = 300;
const uint PLAYER_LIFES = 3;
const string PLAYER_MESH_NAME = "Sinbad.mesh";
const uint PLAYER_INITIAL_POINTS = 0;
const Ogre::Vector3 PLAYER_SCALE = Ogre::Vector3(8, 8, 8);

//ENEMIES
///Simple enemy
const float SIMPLE_ENEMY_SPEED = 100;
const uint SIMPLE_ENEMY_LIFES = 3;
const string SIMPLE_ENEMY_MESH_NAME = "ogrehead.mesh";
const Ogre::Vector3 SIMPLE_ENEMY_SCALE = Ogre::Vector3(1, 1, 1);
const int SIMPLE_ENEMY_AMOUNT = 1;

///Complex enemy
const float COMPLEX_ENEMY_SPEED = 1000;
const uint COMPLEX_ENEMY_LIFES = 3;
const string COMPLEX_ENEMY_MAIN_MESH_NAME = "penguin.mesh";
const Ogre::Vector3 COMPLEX_ENEMY_SCALE = Ogre::Vector3(2, 2, 2);
const int COMPLEX_ENEMY_FISH_AMOUNT = 4;
const float HALO_SPACE = 10;
const float HALO_SPEED = 2;
const int COMPLEX_ENEMY_AMOUNT = 2;

///General
const int NUM_ENEMIES = SIMPLE_ENEMY_AMOUNT + COMPLEX_ENEMY_AMOUNT;
const int ENEMIES_DAMAGE = 1;

//MAP
const string MAP_LAYOUT = "../../media/maps/stage1.txt";

const Ogre::Vector3 INITIAL_POS = Ogre::Vector3(0, 0, 0);

