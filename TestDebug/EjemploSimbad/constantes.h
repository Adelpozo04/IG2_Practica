#pragma once

#include <Ogre.h>

using uint = unsigned int;

//MAPA
const Ogre::Vector3 INI_CUBE_SIZE = Ogre::Vector3(98, 98, 98);
const Ogre::Vector3 CUBE_SIZE = Ogre::Vector3(100, 100, 100);
const std::string MAP_LAYOUT = "stage1.txt";
const Ogre::Vector3 INITIAL_POS = Ogre::Vector3(0, 0, 0);
const int SUBDIVISION_LUZ_PLANO = 200;

//PLAYER
const float PLAYER_SPEED = 300;
const uint PLAYER_LIFES = 3;
const std::string PLAYER_MESH_NAME = "Sinbad.mesh";
const uint PLAYER_INITIAL_POINTS = 0;
const Ogre::Vector3 PLAYER_SCALE = Ogre::Vector3(8, 8, 8);
const int INITIAL_POINTS = 0;

//ENEMIES
///Simple enemy
const float SIMPLE_ENEMY_SPEED = 200;
const uint SIMPLE_ENEMY_LIFES = 3;
const std::string SIMPLE_ENEMY_MESH_NAME = "ogrehead.mesh";
const Ogre::Vector3 SIMPLE_ENEMY_SCALE = Ogre::Vector3(1, 1, 1);
const int SIMPLE_ENEMY_AMOUNT = 1;

///Complex enemy
const float COMPLEX_ENEMY_SPEED = 300;
const uint COMPLEX_ENEMY_LIFES = 3;
const std::string COMPLEX_ENEMY_MAIN_MESH_NAME = "penguin.mesh";
const Ogre::Vector3 COMPLEX_ENEMY_SCALE = Ogre::Vector3(2, 2, 2);
const int COMPLEX_ENEMY_FISH_AMOUNT = 4;
const float HALO_SPACE = 10;
const float HALO_SPEED = 100;
const int COMPLEX_ENEMY_AMOUNT = 2;

///General
const int NUM_ENEMIES = SIMPLE_ENEMY_AMOUNT + COMPLEX_ENEMY_AMOUNT;
const int ENEMIES_DAMAGE = 1;

//UI
const std::string GAMEOVER_TEXT = "Has muerto";

// BOMBS
const uint MAX_NUM_BOMBS = 3;
const uint EXPLOSION_AREA = 4;
const uint TIME_TO_EXPLODE = 3;
//ANMATION BOMS
const Ogre::Vector3 MIN_BOMB_SCALE = Ogre::Vector3(20, 20, 20);
const Ogre::Vector3 MAX_BOMB_SCALE = Ogre::Vector3(40, 40, 40);
const uint SMOKE_TIME = 4;


