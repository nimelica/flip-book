/*
  This class helps to user to create different kinds of animations.
  User can give a .txt file to upload animation in given format
*/
#include "SFML/Graphics.hpp"
#include <iostream>
#include <map>

using namespace std;
using namespace sf;

#ifndef MODEL_H
#define MODEL_H

class Animation;

class Model
{
public:
	//constructor/destructor
	Model(string file);
	~Model();

	//public functions
	void readFile(string filename);
	void render(RenderWindow* window);

	//cowboy's situations
	void dead();
	void idle();
	void slide();
	void run();
	void jump();

private:
	map<string, unique_ptr<Animation>>animationsMap;   //string variables will show an animation in the table
	string currentAnimation;
};
#endif
