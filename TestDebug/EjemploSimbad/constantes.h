#pragma once

#include <Ogre.h>

using uint = unsigned int;

//MAPA
///Game
const Ogre::Vector3 INI_CUBE_SIZE = Ogre::Vector3(98, 98, 98);
const Ogre::Vector3 CUBE_SIZE = Ogre::Vector3(100, 100, 100);
const std::string MAP_LAYOUT = "stage1.txt";
const Ogre::Vector3 INITIAL_POS = Ogre::Vector3(0, 0, 0);

///OpeningAnimation
const Ogre::Vector3 OS_SURFACE_SCALE = Ogre::Vector3(50, 1, 50);

const Ogre::Real OS_INITIAL_STATIC_DUR = 0.001;

////Simbad
const Ogre::Vector3 OS_SIMBAD_DEFAULT_SCAL = {13, 13, 13};
const Ogre::Real OS_SIMBAD_STATIC_DUR = 5;

const int OS_SIMBAD_FLIP_DER_DEGREES = 90;
const Ogre::Real OS_SIMBAD_FLIP_DER_DUR = 0.5;

const int OS_SIMBAD_DER_MOV = 200;
const Ogre::Real OS_SIMBAD_DER_DUR = 3;

const int OS_SIMBAD_FLIP_IZQ_DEGREES = -90;
const Ogre::Real OS_SIMBAD_FLIP_IZQ_DUR = 1;

const int OS_SIMBAD_IZQ_MOV = 400;
const Ogre::Real OS_SIMBAD_IZQ_DUR = 5;

const int OS_SIMBAD_FLIP_DER2_DEGREES = 90;
const Ogre::Real OS_SIMBAD_FLIP_DER2_DUR = 1;

const int OS_SIMBAD_DER2_MOV = 200;
const Ogre::Real OS_SIMBAD_DER2_DUR = 4;

const int OS_SIMBAD_FLIP_CENTER_DEGREES = 0;
const Ogre::Real OS_SIMBAD_FLIP_CENTER_DUR = 0.5;

const Ogre::Real OS_SIMBAD_TOTAL_DUR = OS_INITIAL_STATIC_DUR + OS_SIMBAD_STATIC_DUR + OS_SIMBAD_FLIP_DER_DUR + OS_SIMBAD_DER_DUR +
OS_SIMBAD_IZQ_DUR + OS_SIMBAD_DER2_DUR + OS_SIMBAD_FLIP_IZQ_DUR + OS_SIMBAD_FLIP_DER2_DUR + OS_SIMBAD_FLIP_CENTER_DUR;

const Ogre::Real OS_SIMBAD_SWORD_PICK_DUR = OS_SIMBAD_STATIC_DUR + OS_SIMBAD_FLIP_DER_DUR + OS_SIMBAD_DER_DUR + OS_SIMBAD_FLIP_IZQ_DUR;

const Ogre::Real OS_SIMBAD_SWORD_DROP_DUR = OS_SIMBAD_SWORD_PICK_DUR + OS_SIMBAD_IZQ_DUR;

////OgreHead
const Ogre::Vector3 OS_OGREHEAD_DEFAULT_SCAL = {2, 2, 2};
const int OS_OGREHEAD_MED_DEGREES = 90;
const int OS_OGREHEAD_MED_MOV = 826;
const Ogre::Real OS_OGREHEAD_MED_DUR = OS_INITIAL_STATIC_DUR + OS_SIMBAD_STATIC_DUR + OS_SIMBAD_FLIP_DER_DUR + OS_SIMBAD_DER_DUR;

const int OS_OGREHEAD_FLIP_IZQ_DEGREES = -90;
const Ogre::Real OS_OGREHEAD_FLIP_IZQ_DUR = OS_SIMBAD_FLIP_IZQ_DUR;

const int OS_OGREHEAD_IZQ_MOV = 400;
const Ogre::Real OS_OGREHEAD_IZQ_DUR = OS_SIMBAD_IZQ_DUR;

const int OS_OGREHEAD_FLIP_DER_DEGREES = 90;
const Ogre::Real OS_OGREHEAD_FLIP_DER_DUR = OS_SIMBAD_FLIP_DER2_DUR;

const int OS_OGREHEAD_DER2_MOV = 333;
const Ogre::Vector3 OS_OGREHEAD_DER2_SCAL = { 0.01, 0.01, 0.01 };
const Ogre::Real OS_OGREHEAD_DER2_DUR = OS_SIMBAD_DER2_DUR + OS_SIMBAD_FLIP_CENTER_DUR;

const Ogre::Real OS_OGREHEAD_TOTAL_DUR = OS_OGREHEAD_MED_DUR + OS_OGREHEAD_FLIP_IZQ_DUR + OS_OGREHEAD_IZQ_DUR +
OS_OGREHEAD_FLIP_DER_DUR + OS_OGREHEAD_DER2_DUR;

///General
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

//BOMB

///Properties
const std::string BOMB_MESH = "geosphere4500.mesh";
const std::string WICK_MESH = "column.mesh";
const Ogre::Vector3 BOMB_SCALE = { 0.075, 0.075, 0.075 };
const Ogre::Vector3 BOMB_WICK_SCALE = { 0.9, 0.9, 0.9 };
const Ogre::Vector3 BOMB_FLAME_INI_MOVE = { 0, 300, 0 };
const int BOMB_AMOUNT = 3;
const float BOMB_EXPLOSION_TIME = 3;
const float BOMB_SMOKE_TIME = 2;
const int BOMB_EXPLOSION_RANGE = 3;
const int BOMB_EXPLOSION_DAMAGE = 1;
///Animation




//UI
const std::string GAMEOVER_TEXT = "Has muerto";

// BOMBS
const uint MAX_NUM_BOMBS = 3;
const uint EXPLOSION_AREA = 4;
const double TIME_TO_EXPLODE = 3;
//ANMATION BOMS
const Ogre::Vector3 MIN_BOMB_SCALE = Ogre::Vector3(20, 20, 20);
const Ogre::Vector3 MAX_BOMB_SCALE = Ogre::Vector3(40, 40, 40);
const uint SMOKE_TIME = 4;


