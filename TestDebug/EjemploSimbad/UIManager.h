#pragma once
#include <Ogre.h>
#include <OgreTrays.h>
#include <OgreInput.h>

class UIManager
{
public:

	/**
	 * @brief Constructor del Manager que crea las distintas cajas de texto del juego
	 * @param TrayMgr TrayManager
	 * @param window Ventana de renderizado sobre la que poner la UI
	 */
	UIManager(OgreBites::TrayManager* TrayMgr, Ogre::RenderWindow* window);
	~UIManager();

	/**
	 * @brief Actualiza el texto de estadisticas del jugador
	 * @param nLifes Nueva cantidad de vidas
	 * @param points Nueva cantidad de puntos
	 */
	void updateTextBox(int nLifes, int points)const;

	/**
	 * @brief Muestra el mensaje de muerte en pantalla
	 */
	void showDeathBox();

private:
	OgreBites::TextBox* mTextBox = nullptr;
	OgreBites::TextBox* mDeathBox = nullptr;
	OgreBites::TrayManager* mTrayMgr = nullptr;
};

