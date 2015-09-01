#include "../include/GameObject.h"

GameObject::GameObject(void) {
	this->setPos(Vector(0, 0));
}

GameObject::GameObject(const Vector newpos) {
	this->setPos(newpos);
}

GameObject::~GameObject() {
	//Free components
	std::vector<std::shared_ptr<Component>>::iterator it;
	std::vector<std::shared_ptr<Component>> components = this->getComponents();
	for (it=components.begin(); it != components.end(); it++) {
		//deletes Component OBJECT! Make sure its correct, and no other object is using the same component
	}
	
}

void GameObject::addComponent(std::shared_ptr<Component> component) {
	this->_components.push_back(component);
}

/*
void GameObject::removeComponent(std::shared_ptr<Component> component) {
	this->_components.pop_back
}
*/

void GameObject::setPos(const Vector v) {
	this->_pos = v;
}

Vector GameObject::getPos(void) {
	return this->_pos;
}

std::vector<std::shared_ptr<Component>> GameObject::getComponents(void) {
	return this->_components;
}

void GameObject::update(void) {
	std::vector<std::shared_ptr<Component>>::iterator it;
	std::vector<std::shared_ptr<Component>> components = this->getComponents();
	for (it = components.begin(); it != components.end(); it++) {
		(*it)->update(this);
	}
}