#include "Tile.h"

Tile::Tile() : 
	transferable(false), IG2Object()
{

}

Tile::Tile(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, bool trasfer) : 
	transferable(trasfer), IG2Object(initPos, node, sceneMng)
{

}

Tile::Tile(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh, bool trasfer) :
	transferable(trasfer), IG2Object(initPos, node, sceneMng, mesh)
{
}

void Tile::SetTransferable(bool trasfer)
{
	transferable = trasfer;
}

bool Tile::GetTransferable()
{
	return transferable;
}

