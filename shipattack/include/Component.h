//General class for Component

#ifndef h_Component
#define h_Component

#include "GameObject.h"
#include <SDL_image.h>
#include <string>
#include <exception>

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
	GraphicsComponent(SDL_Renderer*, SDL_Texture*);
	~GraphicsComponent();
	void update(GameObject*);

	bool loadTexture(std::string path);
	SDL_Texture* getTexture(void);
	SDL_Renderer* getRenderer(void);
	
private:
	SDL_Texture* _texture;
	SDL_Renderer* _renderer;

};

#endif
