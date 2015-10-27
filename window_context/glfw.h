#ifndef GLFW_H_
#define GLFW_H_

#include <iostream>
#include <cstdlib>
#include <GL/glfw3.h>
#include <string>

class GLFW{

private:
	SDL_Window* win;
	SDL_GLContext glcontext;
	SDL_Event event;
	int winWidth,winHeight;

public:
	 GLFW(){

        if(!glfwInit()){
            fprintf( stderr, "Failed to initialize GLFW\n" );
            exit(1);
        }

        GLFWwindow* window;
        window = glfwCreateWindow( 600, 600, "GLFW", NULL, NULL); 
        if(!window){
            fprintf( stderr, "Failed to open GLFW window.\n" );
            glfwTerminate();
            exit(1);
        }
	 	glfwMakeContextCurrent(window);
        glewExperimental=true; // Needed in core profile 
        if(glewInit() != GLEW_OK) {
            fprintf(stderr, "Failed to initialize GLEW\n");
            exit(1);
        }
	 }

	 GLFW(string name,int width,int height){
	 	if(!glfwInit()){
            fprintf( stderr, "Failed to initialize GLFW\n" );
            exit(1);
        }

        GLFWwindow* window;
        window = glfwCreateWindow(width, height, name, NULL, NULL); 
        if(!window){
            fprintf( stderr, "Failed to open GLFW window.\n" );
            glfwTerminate();
            exit(1);
        }
        glfwMakeContextCurrent(window);
        glewExperimental=true; // Needed in core profile 
        if(glewInit() != GLEW_OK) {
            fprintf(stderr, "Failed to initialize GLEW\n");
            exit(1);
        }
	 }

	~ GLFW(){
		glfwWindowShouldClose(window);
        glfwTerminate();
	}
	
};

#endif