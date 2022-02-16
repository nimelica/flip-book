#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;
using namespace sf;

#ifndef ANIMATION_H
#define ANIMATION_H

class Model;

class Animation {
public:
	//constructor/destructor
	Animation();
	~Animation();

	//public functions
	void addAnimation(string firstFileName, int frameNum, float xpos, float ypos);
	void render(RenderWindow* window);
	void update();
	void frameTimeUpdate(int time);


private:

	vector<unique_ptr<Sprite>>spriteList;           //to not lose our sprites, we use a sprite vector that holds addresses
	vector<unique_ptr<Texture>>textureList;         //to not lose our textures, we use a texture vector that holds addresses

	int currentFrameNumber;
	int totalFrame;
	int frameTime;                                   //when should we get next sprite
	int frameCounter;                                //how many times update function is called

};
#endif

