#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character
{

protected:

	Enemy();
	Enemy(Vector3 initPos, SceneNode* node, SceneManager* sceneMng);
	Enemy(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh);

	/**
	 * @brief Metodo para escoger de manera aleatoria la siguiente direccion posible a la cual girar (o mantenerse). 
	 * En un futuro puede que cada enemigo implemente su propia version
	 * @param MM MazeManager
	 * @return Devuelve la direccion que se ha elegido.
	 */
	Ogre::Vector3 ChooseNextDir(MazeManager* MM);

};

#endif // !ENEMY_H
