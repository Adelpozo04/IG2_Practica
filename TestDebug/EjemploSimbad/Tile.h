#ifndef TILE_H
#define TILE_H


#include "IG2Object.h"
class Tile : public IG2Object
{

public:

	Tile();

	Tile(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, bool trasfer);

	Tile(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh, bool trasfer);

	void SetTransferable(bool trasfer);

	bool GetTransferable();


protected:

	bool transferable;

};

#endif // !TILE_H