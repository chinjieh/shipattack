#include "../include/GameObject.h"

GameObject::GameObject(void) {
	this->setPos(Vector(0, 0));
}

GameObject::GameObject(const Vector newpos) {
	this->setPos(newpos);
}

GameObject::~GameObject() {
	//Free components
	std::list<Component*>::iterator it;
	std::list<Component*> components = this->getComponents();
	for (it=components.begin(); it != components.end(); it++) {
		//deletes Component OBJECT! Make sure its correct, and no other object is using the same component
		this->removeComponent(*it);
	}
	
}

void GameObject::addComponent(Component* component) {
	this->_components.push_back(component);
}

void GameObject::removeComponent(Component* component) {
	delete component;
}

void GameObject::setPos(const Vector v) {
	this->_pos = v;
}

Vector GameObject::getPos(void) {
	return this->_pos;
}

std::list<Component*> GameObject::getComponents(void) {
	return this->_components;
}

void GameObject::update(void) {
	std::list<Component*>::iterator it;
	std::list<Component*> components = this->getComponents();
	for (it = components.begin(); it != components.end(); it++) {
		(*it)->update(this);
	}
}