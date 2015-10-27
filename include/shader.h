#ifndef INITSHADERS_H_
#define INITSHADERS_H_

#include "GL/gl.h"
#include "GL/glu.h"
#include <fstream>


class Shader{

private:
	GLenum type;
	string filename;
	Glint status;

public:
	Shader();
	~Shader();

	inputShader(){
		ifstream input(filename.c_str());
		string lines
		if(input.in_open()){
			while(input >> lines){

			}

		}else{
			cerr << "File not open" << filename << endl;
		}
	}

	createShader(){

	}

	loginfo();
	
};


#endif