#ifndef h_main
#define h_main
/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <memory>
#include "../include/paths.h"
#include "../include/GameObject.h"

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

//Image paths
//const std::string BACKGROUND_IMAGE = "img/background.jpg";
const std::string BACKGROUND_IMAGE = paths::IMG_BACKGROUND;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

SDL_Texture* gBackgroundTexture = NULL;

//Window renderer
SDL_Renderer* gRenderer = NULL;

//Vector of items to update
std::vector<std::shared_ptr<GameObject>> gameobjvector;

bool init();
void close(); //cleanup garbage
SDL_Texture* loadTexture(std::string path); //load texture from path
bool loadMedia();

SDL_Texture* loadTexture(std::string path){
	SDL_Texture* texture = NULL;
	printf("Before IMG_Load\n");
	SDL_Surface* tempsurface = IMG_Load(path.c_str());
	printf("loadTexture: surface loaded\n");
	if (tempsurface == NULL){
		printf("Failed to load image: %s. Error: %s\n", path.c_str(), IMG_GetError());
	}
	else{
		//Convert surface to texture
		texture = SDL_CreateTextureFromSurface(gRenderer, tempsurface);
		if (texture == NULL){
			printf("Failed to create texture! Error: %s\n", IMG_GetError());
		}

		//Free surface
		SDL_FreeSurface(tempsurface);
	}

	return texture;
}

bool loadMedia(){
	bool success = true;
	printf("In loadMedia()\n");
	gBackgroundTexture = loadTexture(BACKGROUND_IMAGE);
	if (gBackgroundTexture == NULL){
		printf("BackgroundTexture failed to load!\n");
		success = false;
	}
	printf("Load media completed\n");
	return success;
}

void close(){
	//Deallocate resources
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();
}

bool init(){
	bool success = true;
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window Renderer
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL){
				printf("SDL Renderer failed to load!\n");
				success = false;
			}
			else{
				//Set Renderer options
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
			}
		}
	
	}
	return success;
}

int main( int argc, char* args[] )
{
	printf("Initialising...\n");
	if (!init()) {
		printf("SDL failed to initialise!");
	}
	else {
		printf("Initalised. Loading Media...\n");
		if (!loadMedia()){
			printf("Load Media failed!\n");
		}
		else {

			//Add stuff to gameobjvector
			//Create ship GameObject
			std::shared_ptr<GameObject> shipattack(new GameObject());

			//load ship texture
			SDL_Texture* shiptexture = loadTexture(paths::IMG_SHIP);
			//Create new ship GraphicComponent
			std::shared_ptr<GraphicsComponent> shipgraphiccomp(new GraphicsComponent(gRenderer, shiptexture));
			shipattack->addComponent(shipgraphiccomp);
			gameobjvector.push_back(shipattack);

			SDL_Event e;
			bool quit = false;
			while (!quit){

				//Process event messages
				while (SDL_PollEvent(&e) != 0){
					switch (e.type){
					case SDL_QUIT:
						quit = true;
						break;
					default:
						break;
					}

					SDL_RenderClear(gRenderer);
					SDL_RenderCopy(gRenderer, gBackgroundTexture, NULL, NULL);
					
					std::vector<std::shared_ptr<GameObject>>::iterator it;
					for (it = gameobjvector.begin(); it != gameobjvector.end(); it++) {
						(*it)->update();
					}
					SDL_RenderPresent(gRenderer);


				}

				//Update the surface
				SDL_UpdateWindowSurface(gWindow);

			}
		}
	}

	close();
	return 0;
}

#endif