
#ifndef h_GameObject
#define h_GameObject

#include "Component.h"
#include "globals.h"
#include <list>
#include <memory>
#include <vector>


class Component; //Leaving this out till I find out why uncommenting this fixes it
class GameObject {
public:
	GameObject();
	GameObject(Vector initialpos);
	~GameObject();

	void addComponent(std::shared_ptr<Component>);
	//void removeComponent(std::shared_ptr<Component>);

	void setPos(Vector newpos);
	Vector getPos(void);
	
	std::vector<std::shared_ptr<Component>> getComponents();

	void update();


private:
	std::vector<std::shared_ptr<Component>> _components; //list here
	Vector _pos;

};

#endif

