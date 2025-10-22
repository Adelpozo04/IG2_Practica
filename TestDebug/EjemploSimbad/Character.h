#ifndef CHARACTER_H
#define CHARACTER_H

#include "IG2Object.h"
#include "MazeManager.h"

class Character : public IG2Object
{
public:

	/**
	 * @brief Devuelve la velocidad a la que va la entidad, independientemente de la que sea
	 * @return la velocidad a la que va la entidad.
	 */
	inline float getSpeed() const {
		return _speed;
	}

	/**
	 * @brief Devuelve las vidas actuales de la entidad.
	 * @return las vidas actuales de la entidad
	 */
	inline int getLifes() const {
		return _lifes;
	}

	inline int getPoints() const{ return _points; }

	inline void addPoints(int p) { _points += p; }

	/**
	 * @brief aplica un danyo especifico a la vida de la entidad, asegurandose de que no sea menor a cero esta
	 * @param damage cantidad de vidas que le debe restar
	 */
	inline void reciveDamage(int damage) {
		_lifes -= damage;
		if (_lifes < 0) {
			_lifes = 0;
		}
	}

	/**
	 * @brief nos da la direccion actual hacia la que se mueve la entidad
	 * @return un vector 3 con la direccion especifica
	 */
	inline Ogre::Vector3 getDir() const {
		return _currentDir;
	}

	/**
	 * @brief indicar cual es la direccion actual que ha de seguir la entidad
	 * @param dir direccion la cual seguir
	 */
	inline void setDir(Ogre::Vector3 dir) {
		_currentDir = dir;
	}

	/**
	 * @brief obtener la siguiente direccion a la que quiere ir la entidad cuando le sea posible
	 * @return la direccion a la que cambiar
	 */
	inline Ogre::Vector3 getNextDir() const {
		return _nextDir;
	}

	/**
	 * @brief establecer la direccion a la que ira la entidad en la siguiente interseccion o fin de ruta
	 * @param ndir direccion a la que queremos cambiar
	 */
	inline void setNextDir(Ogre::Vector3 ndir) {
		_nextDir = ndir;
	}

	/**
	 * @brief Metodo para obtener el iterador de la posicion actual de la entidad en la lista de su manager.
	 * No debe de ser usado obligatoriamente
	 * @return Iterador de la lista de entidades del manager de la entidad
	 */
	inline std::list<Character*>::iterator getIterator() const {
		return _it;
	}

	/**
	 * @brief Metodo para establecer el iterador de la entidad
	 * @param it Iterador de la lista de entidades del manager especifico de la entidad.
	 */
	inline void setIterator(std::list<Character*>::iterator it) {
		_it = it;
	}

	/**
	 * @brief Metodo que debe definir cada tipo de entidad. Este marca el algoritmo de movimiento a aplicar sobre la direccion actual y
	 * la siguiente en eleccion
	 * @param MM MazeManager
	 * @param dt deltaTime que aplicar a los desplazamientos
	 */
	virtual void move(MazeManager* MM, float dt) = 0;

	/**
	 * @brief Metodo que debe definir cada tipo de entidad. Este sirve para definir las animaciones de la entidad siempre que estas se reduzcan a cambios en parametros como posicion, rotacion
	 * o escala
	 * @param dt deltaTime sobre el que se realizaran esos cambios 
	 */
	virtual void inlineAnimation(float dt) = 0;

protected:

	Character();
	Character(Vector3 initPos, SceneNode* node, SceneManager* sceneMng);
	Character(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh);

	/**
	 * @brief Eliminacion de la posibilidad de hacer una llamada al constructor mediante la copia de otra entidad
	 */
	Character(const Character&) = delete;

	/**
	 * @brief Eliminacion de la posibilidad de hacer una copia de una entidad a otra. Esto con el objetivo de que las instancias de entidades
	 * deban de ser si o si punteros.
	 */
	Character& operator=(const Character&) = delete;

	/**
	 * @brief destructor de la clase, debe ser implementado por cada hijo de esta
	 */
	virtual ~Character() = default;

	/**
	 * @brief Metodo que sirve para comprobar si puedes avanzar en una direccion determinada
	 * @param dir direccion a la que avanzar
	 * @param MM MazeManager
	 * @return 
	 */
	bool CanGo(Ogre::Vector3 dir, MazeManager* MM);

	/**
	 * @brief Metodo que sirve para comprobar si puedes girar hacia una direccion
	 * @param dir direccion a la que quieres girar
	 * @param MM MazeManager
	 * @return 
	 */
	bool canTurn(Ogre::Vector3 dir, MazeManager* MM, float dt);

	/**
	 * @brief Metodo que nos indica si hemos pasado en ese frame del centro de la tile en la que nos encontramos. Para ello nuestra poscion
	 * actual debe de estar detras del centro y la siguiente a esa debe ser posterior a este centro.
	 * @param MM MazeManager
	 * @param dt DeltaTime
	 * @return Devuelve si se ha pasado del centro en ese frame o no
	 */
	bool passCenterTile(MazeManager* MM, float dt);

	/**
	 * @brief Metodo sobre el cual aplicar transformaciones sobre la entidad posterior a la creacion de esta.
	 */
	virtual void Config() = 0;

	int _lifes;
	float _speed;
	int _points;

	//Direccion actual a la que se mueve el jugador
	Ogre::Vector3 _currentDir;
	//Direccion futura a la que el jugador debe cambiar cuando se de la ocasion.
	Ogre::Vector3 _nextDir;

	//Iterador de la lista de entidades del manager de la entidad
	std::list<Character*>::iterator _it;

};

#endif // !CHARACTER_H

