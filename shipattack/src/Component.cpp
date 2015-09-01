#include "../include/Component.h"

Component::Component() {

}

Component::~Component() {

}


GraphicsComponent::GraphicsComponent(SDL_Renderer* renderer, SDL_Texture* texture) {
	this->_renderer = renderer;
	this->_texture = texture;

}

GraphicsComponent::~GraphicsComponent() {

}

void GraphicsComponent::update(GameObject* gameobj) {
	//Render the texture
	SDL_Rect destrect;
	destrect.x = int( (gameobj->getPos()).x);
	destrect.y = int( (gameobj->getPos()).y);
	int texturewidth, textureheight;

	//Get texture info; might want to move this out next time
	SDL_QueryTexture(this->getTexture(), NULL, NULL, &texturewidth, &textureheight);
	destrect.w = texturewidth;
	destrect.h = textureheight;
	if (SDL_RenderCopyEx(this->_renderer, this->_texture, NULL, &destrect, 0, NULL, SDL_FLIP_NONE) < 0) {
		printf("Unable to RenderCopy GameObject: %s", SDL_GetError());
		std::string excep = (boost::format("Unable to RenderCopy GameObject: %s") % SDL_GetError()).str();
		throw std::runtime_error(excep); //create customException next time
	}
}

SDL_Texture* GraphicsComponent::getTexture(void) { return this->_texture; }

SDL_Renderer* GraphicsComponent::getRenderer(void) { return this->_renderer; }