#include "Model.h"
#include <fstream>
#include "Animation.h"

using namespace std;
using namespace sf;

Model::Model(string file){
	readFile(file);
}

Model::~Model(){}

void Model::readFile(string filename)
{
	ifstream infile;
	infile.open(filename);

	if (!infile.is_open()){
		cerr << ".txt file not found!\n";
	}

	string dummy, animationName, animFileName;
	int frameNum;

	infile >> dummy >> currentAnimation;

	while (infile >> animationName >> animFileName >> frameNum){
		unique_ptr<Animation>nextAnimation = make_unique<Animation>();
		nextAnimation->addAnimation(animFileName, frameNum, 100.f, 300.f);
		animationsMap[animationName] = move(nextAnimation);
	}
}

void Model::render(RenderWindow* window){
	animationsMap[currentAnimation]->render(window);
	animationsMap[currentAnimation]->update();
}

void Model::dead(){
	currentAnimation = "dead";
}

void Model::idle(){
	currentAnimation = "idle";
}

void Model::slide(){
	currentAnimation = "slide";
}

void Model::run(){
	currentAnimation = "run";
}

void Model::jump(){
	currentAnimation = "jump";
}

