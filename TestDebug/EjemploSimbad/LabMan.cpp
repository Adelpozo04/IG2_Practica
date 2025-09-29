#include "LabMan.h"
#include "Muro.h"
#include "constantes.h"
#include <fstream>

LabMan::LabMan(SceneNode* labNode, SceneManager* sM, std::string file) : mLabNode(labNode), mSM(sM)
{
	loadLabFromFile(file);
}

LabMan::~LabMan()
{
	for (IG2Object* obj : objects) {
		if(obj != nullptr)
			obj->removeEntity();
		obj = nullptr;
	}

	for (int i = 0; i < nFil; ++i) {
		if(labArray[i] != nullptr)
			delete[] labArray[i];  // delete each row
		labArray[i] == nullptr;
	}
	delete[] labArray;  // delete the array of row pointers
	labArray = nullptr;
}

void LabMan::loadLabFromFile(std::string file)
{
	std::string s = "../../media/maps/";
	s += file;
	std::ifstream reader(s);
	if (!reader.is_open()) throw "Error al abrir el archivo";
	int nFils;
	int nCols;
	reader >> nFils;
	reader >> nCols;

	nFil = nFils;

	labArray = new bool*[nFils];
	for (int i = 0; i < nFils; i++) {
		labArray[i] = new bool[nCols];
	}

	char c;
	for (int i = 0; i < nFils; i++) {
		for (int j = 0; j < nCols; j++) {
			reader >> c;
			readChars(c, i, j);
		}
	}
	reader.close();
	mLabNode->setPosition(centraLab(nFils), 0, centraLab(nCols));
}

void LabMan::readChars(char c, int i, int j)
{
	IG2Object* obj = nullptr;
	switch (c) {
	case 'x':
		obj = new Muro(Ogre::Vector3(CUBE_SIZE * j, 0, CUBE_SIZE * i), mLabNode->createChildSceneNode(), mSM);
		labArray[i][j] = false;
		break;
	case 'o':
		labArray[i][j] = true;
		break;
	default:
		break;
	}
	if(obj != nullptr)
		objects.push_back(obj);
}

double LabMan::centraLab(int a) {
	double b = a - 1;
	b = b * CUBE_SIZE;
	b = b * -1;
	b = b / 2;
	return b;
}
