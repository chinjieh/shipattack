
#ifndef h_GameObject
#define h_GameObject

#include "Component.h"
#include "globals.h"
#include <list>


class Component; //Leaving this out till I find out why uncommenting this fixes it
class GameObject {
public:
	GameObject();
	GameObject(Vector initialpos);
	~GameObject();

	void addComponent(Component*);
	void removeComponent(Component*);

	void setPos(Vector newpos);
	Vector getPos(void);
	
	std::list<Component*> getComponents();

	void update();


private:
	std::list<Component*> _components; //list here
	Vector _pos;

};

#endif

