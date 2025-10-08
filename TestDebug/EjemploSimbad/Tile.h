#ifndef TILE_H
#define TILE_H


#include "IG2Object.h"
class Tile : public IG2Object
{

public:

	/**
	 * @brief Constructor vacio de Tile, se pone traspasable a false
	 */
	Tile();

	/**
	 * @brief Constructor de Tile sin entidad atachada
	 * @param initPos Posicion inicial
	 * @param node Nodo del propio objeto
	 * @param sceneMng Manager de la escena
	 * @param trasfer Si sera traspasable o no
	 */
	Tile(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, bool trasfer);

	/**
	 * @brief Constructor de Tile con entidad atachada
	 * @param initPos Posicion inicial
	 * @param node Nodo del propio objeto
	 * @param sceneMng Manager de la escena
	 * @param mesh Malla de que representa a la entidad
	 * @param trasfer Si sera traspasable o no
	 */
	Tile(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh, bool trasfer);

	/**
	 * @brief Cambia la caracteristica de atravesabilidad del objeto
	 * @param trasfer indica si es atravesable o no
	 */
	void SetTransferable(bool trasfer);
	
	/**
	 * @brief Obtener la caracteristica de atravesabilidad
	 * @return devuelve si es atravesable o no
	 */
	bool GetTransferable();


protected:

	bool transferable;

};

#endif // !TILE_H