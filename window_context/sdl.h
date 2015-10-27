#ifndef SDL2_H_
#define SDL2_H_

#include <iostream>
#include <cstdlib>
#include <SDL/SL.h>
#include <string>

class SDL2{

private:
	SDL_Window* win;
	SDL_GLContext glcontext;
	SDL_Event event;
	int winWidth,winHeight;

public:
	 SDL2(){
	 	if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
        	fprintf(stderr, "Error: Unable to init SDL: %s\n", SDL_GetError());
        	exit(1);
    	}
    	win = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,600, 600,SDL_WINDOW_OPENGL);

    	if (!win) {
        	fprintf(stderr, "Unable to start video: %s\n", SDL_GetError());
        	SDL_Quit();
        	exit(1);
    	}

    	glcontext = SDL_GL_CreateContext(win);

    	glewExperimental=true; // Needed in core profile 
        if(glewInit() != GLEW_OK) {
            fprintf(stderr, "Failed to initialize GLEW\n");
            exit(1);
        }
	 	
	 }

	 SDL2(string name,int width,int height){
	 	if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
        	fprintf(stderr, "Error: Unable to init SDL: %s\n", SDL_GetError());
        	exit(1);
    	}
    	win = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,width, height,SDL_WINDOW_OPENGL);

    	if (!win) {
        	fprintf(stderr, "Unable to start video: %s\n", SDL_GetError());
        	SDL_Quit();
        	exit(1);
    	}
    	
    	glcontext = SDL_GL_CreateContext(win);

    	glewExperimental=true; // Needed in core profile 
        if(glewInit() != GLEW_OK) {
            fprintf(stderr, "Failed to initialize GLEW\n");
            exit(1);
        }
	 }

	~ SDL2(){
		SDL_GL_DeleteContext(glcontext);
		SDL_Quit();
	}
	
};

#endif