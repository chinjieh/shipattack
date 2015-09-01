//General class for Component

#ifndef h_Component
#define h_Component

#include "GameObject.h"

class GameObject;

class Component {
public:
	Component();
	~Component();
	virtual void update(GameObject*)=0;

};

/*
//Subclasses of Component
class PhysicsComponent : public Component{
public:
	PhysicsComponent();
	~PhysicsComponent();
	void update(GameObject*);
};

class LogicComponent : public Component{
public:
	LogicComponent();
	~LogicComponent();
	void update(GameObject*);
};
*/
class GraphicsComponent : public Component{
public:
	GraphicsComponent();
	~GraphicsComponent();
	void update(GameObject*);
};

#endif
